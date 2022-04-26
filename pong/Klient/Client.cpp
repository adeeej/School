#include "Client.h"

using namespace std::string_literals;

/// <summary>
/// inicializacia grafickeho okna
/// </summary>
void Client::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), title);
	window->setFramerateLimit(FPS);
	window->setPosition(sf::Vector2i(100, 200));
	window->setActive(false);
	windowRunning = true;
}

/// <summary>
/// inicializacia hracskych rakiet
/// </summary>
void Client::initBars()
{
	//left Bar
	barLeft.setFillColor(colorOfGame);
	barLeft.setSize(sf::Vector2f(BAR_WIDTH, BAR_HEIGHT));
	barLeft.setPosition(sf::Vector2f(LEFT_BAR_X, bar1posY));

	//right Bar
	barRight.setFillColor(colorOfGame);
	barRight.setSize(sf::Vector2f(BAR_WIDTH, BAR_HEIGHT));
	barRight.setPosition(sf::Vector2f(RIGHT_BAR_X, bar2posY));
}

/// <summary>
/// inicializacia lopty v hre
/// </summary>
void Client::initBall()
{
	ball.setFillColor(colorOfGame);
	ball.setRadius(20);
	ball.setPosition(sf::Vector2f(WINDOW_WIDTH / 2.0 - BALL_RADIUS, WINDOW_HEIGHT / 2.0 - BALL_RADIUS));
}

/// <summary>
/// inicializacia textu na zobrazovanie bodov
/// </summary>
void Client::initPoints()
{
	if (!pismo.loadFromFile("arial.ttf"))
	{
		printf("File arial.ttf is missing!\n");
		exit;
	}
	for (int i = 0; i < NUM_OF_PLAYERS; i++)
	{
		points[i].setFont(pismo); //nastavenie druhu pisma
		points[i].setFillColor(colorOfGame); //nastavenie farbz
		points[i].setCharacterSize(60);
	}

	points[0].setString(std::to_string(serversPoints)); //prevedenie int na string
	points[0].setPosition(20, 20); //pozicia textu

	points[1].setString(std::to_string(clientsPoints)); //prevedenie int na string
	points[1].setPosition(750, 20); //pozicia textu
}

/// <summary>
/// nastavenie farby hry na zaklade ciselnej reprezentacie farby 0 - biela, 1 - cervena, 2 - zelena
/// </summary>
/// <param name="colorRepresentation"></param>
void Client::setColor(int colorRepresentation)
{
	switch (colorRepresentation)
	{
	case 0:
		colorOfGame = sf::Color::White;
		break;
	case 1:
		colorOfGame = sf::Color::Red;
		break;
	case 2:
		colorOfGame = sf::Color::Green;
		break;
	default:
		break;
	}
}

/// <summary>
/// cakanie na packet s nastaveniami hry, odoslaneho zo servera
/// </summary>
void Client::waitForSettings()
{
	packetForRecieving.clear();
	unsigned short port = 0;
	int color;

	if (socket.receive(packetForRecieving, ipAddress, port) == sf::Socket::Done)
	{
		packetForRecieving >> color;
		packetForRecieving >> startNewGame;
		packetForRecieving >> maximumPoints;
		std::cout << color << " " << startNewGame << "\n";
		setColor(color);
	}
	else
	{
		std::cout << "Failed recieving settings\n";
	}
}

/// <summary>
/// konstruktor triedy Client, nastavenie parametrov, spustenie uvodneho menu, nastavenie hry
/// </summary>
Client::Client()
{
	srand(time(NULL));
	bar1posY = 230;
	bar2posY = 230;
	title = "SFML Pong Game! Player 2 - CLIENT!";
	ballX = 0;
	ballY = 0;
	runMenu();
	if (isValidServerIp)
	{
		waitForSettings();
	}
	

}

/// <summary>
/// destruktor triedy Client
/// </summary>
Client::~Client()
{
	
}

/// <summary>
/// funkcia na detekovanie akcie vykonanej pouzivatelom, stlacenie klavesy, vypnutie okna
/// </summary>
void Client::isKeyPressed()
{
	while (window->pollEvent(ev)) {
		if (ev.type == sf::Event::Closed)
		{
			windowRunning = false;
			running = false;
			window->close();
		}

		if (ev.type == sf::Event::KeyPressed)
		{
			switch (ev.key.code)
			{
			case sf::Keyboard::Up:
				if (bar2posY >= speedBar)
				{
					bar2posY -= speedBar;
				}
				break;
			case sf::Keyboard::Down:
				if (bar2posY <= windowHeight - barHeight - speedBar)
				{
					bar2posY += speedBar;
				}
				break;
			}
		}
	}
}

/// <summary>
/// prepisanie pozicii jednotlivych objektov
/// </summary>
void Client::update()
{
	isKeyPressed();
	mutex.lock();
	ball.setPosition(ballX, ballY);
	barLeft.setPosition(leftBarX, bar1posY);
	barRight.setPosition(rightBarX, bar2posY);
	points[0].setString(std::to_string(serversPoints)); //prevedenie int na string
	points[1].setString(std::to_string(clientsPoints)); //prevedenie int na string
	mutex.unlock();
}

/// <summary>
/// zmazanie a novonakreslenie grafickeho okna spolu so vsetkymi objetami v nom
/// </summary>
void Client::render()
{
	window->clear();
	window->draw(barLeft);
	window->draw(barRight);
	window->draw(ball);
	for (int i = 0; i < NUM_OF_PLAYERS; i++)
	{
		window->draw(points[i]);
	}
	window->display();
}

/// <summary>
/// spustenie uvodneho menu
/// </summary>
void Client::runMenu()
{
	ClientMenu menu;
	bool tmpRunning = true;
	while (tmpRunning)
	{
		tmpRunning = menu.isRunning();
		menu.drawMenu();
	}
	if (menu.isJoinPressed())
	{
		ServerIp = menu.getIp();
		ServerPort = menu.getPort();
		initCommunication();
	}
	else
	{
		running = false;
	}
}

/// <summary>
/// inicializacia komunikacie so serverom
/// </summary>
void Client::initCommunication()
{
	running = true;
	std::signal(SIGTERM, signal_handler);
	auto state = CommunicationState::Send;
	if (socket.send(packetForSending, ServerIp, ServerPort) == sf::Socket::Done)
	{
		std::cout << "== Sending (" << ServerIp.toString() << ":" << ServerPort << ") ==\n";
		state = CommunicationState::Receive;
		isValidServerIp = true;
	}
	else
	{
		std::cerr << "Error sending to " << ServerIp.toString() << ":" << ServerPort << "\n";
		sf::sleep(sf::milliseconds(100));
	}
	
}

/// <summary>
/// spustenie vlakien a cakanie na ich skoncenie
/// </summary>
void Client::ruhThreads()
{ 
	if (startNewGame)
	{
		std::thread recieving(&Client::threadForRecieving, this);
		std::thread drawing(&Client::threadForDrawing, this);
		std::thread sending(&Client::threadForSending, this);

		recieving.join();
		drawing.join();
		sending.join();
	}
}

/// <summary>
/// funkcia spustana vo vlakne, posiela data na server
/// </summary>
void Client::threadForSending()
{
	float tmp;
	while (running)
	{
		mutex.lock();
		tmp = bar2posY;
		mutex.unlock();

		packetForSending.clear();
		packetForSending << tmp;
		if (socket.send(packetForSending, ServerIp, ServerPort) == sf::Socket::Done)
		{
			std::cout << "Send right bar position " << tmp << "\n";
		}
		else
		{
			std::cout << "Sending right bar position failed";
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(50));


	}
}

/// <summary>
/// funkcia spustena vo vlakne, prijma data zo servera
/// </summary>
void Client::threadForRecieving()
{
	unsigned short port = 0;
	bool tmpRunnig;
	while (running)
	{
		packetForRecieving.clear();
		if (socket.receive(packetForRecieving, ipAddress, port) == sf::Socket::Done)
		{
			mutex.lock();
			packetForRecieving >> ballX;
			packetForRecieving >> ballY;
			packetForRecieving >> bar1posY;
			packetForRecieving >> serversPoints;
			packetForRecieving >> clientsPoints;
			packetForRecieving >> tmpRunnig;
			if (!tmpRunnig)
			{
				running = tmpRunnig;
			}
			mutex.unlock();
			std::cout << ballX << " " << ballY << " " << bar1posY << " " << bar2posY << "\n";

		}
		else
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(50));

	}
}

/// <summary>
/// funkcia spustena vo vlakne, vykresluje graficke okno a spracuvava data prijate zo servera
/// </summary>
void Client::threadForDrawing()
{
	initWindow();
	initBars();
	initBall();
	initPoints();
	render();
	while (running)
	{
		window->setActive(true);
		//mutex.lock();
		update();
		//mutex.unlock();
		render();
		window->setActive(false);
		std::this_thread::sleep_for(std::chrono::milliseconds(30));
	}

	sf::Text result;
	std::string text;
	if (clientsPoints >= maximumPoints)
	{
		text = "CG, WINNER!";
	}
	else
	{
		text = "LOOSER!";
	}
	result.setFont(pismo);
	result.setString(text);
	result.setFillColor(sf::Color::White);
	result.setCharacterSize(50);
	sf::FloatRect textRect = result.getLocalBounds();
	result.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	result.setPosition(sf::Vector2f(windowWidth / 2.0f, windowHeight / 2.0f));
	while (windowRunning)
	{
		isKeyPressed();
		window->clear();
		window->draw(result);
		window->display();
	}
	delete window;
}
