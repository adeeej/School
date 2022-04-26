#include "Server.h"

/// <summary>
/// inicializacia grafickeho okna
/// </summary>
void Server::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), title);
	window->setFramerateLimit(FPS);
	window->setPosition(sf::Vector2i(800, 200));
	window->setActive(false);
	windowRunning = true;
}

/// <summary>
/// inicializacia lopty v hre
/// </summary>
void Server::initBall()
{
	ball.setFillColor(colorOfBars);
	ball.setRadius(20);
	ball.setPosition(sf::Vector2f(windowWidth /2.0 - ballRadius, windowHeight /2.0 - ballRadius));
}

/// <summary>
/// inicializacia rakiet oboch hracov
/// </summary>
void Server::initBars()
{
	//left Bar
	barLeft.setFillColor(colorOfBars);
	barLeft.setSize(sf::Vector2f(barWidth, barHeight));
	barLeft.setPosition(sf::Vector2f(leftBarX, bar1posY));

	//right Bar
	barRight.setFillColor(colorOfBars);
	barRight.setSize(sf::Vector2f(barWidth, barHeight));
	barRight.setPosition(sf::Vector2f(rightBarX, bar2posY));
}

/// <summary>
/// inicializacia textoveho zobrazenia bodov
/// </summary>
void Server::initPoints()
{
	if (!pismo.loadFromFile("arial.ttf"))
	{
		printf("File arial.ttf is missing!\n");
		exit;
	}
	for (int i = 0; i < NUM_OF_PLAYERS; i++)
	{
		points[i].setFont(pismo); //nastavenie druhu pisma
		points[i].setFillColor(colorOfBars); //nastavenie farbz
		points[i].setCharacterSize(60);
	}

	points[0].setString(std::to_string(serversPoints)); //prevedenie int na string
	points[0].setPosition(20, 20); //pozicia textu

	points[1].setString(std::to_string(clientsPoints)); //prevedenie int na string
	points[1].setPosition(750, 20); //pozicia textu
}

/// <summary>
/// bindovanie portu s ip adresou
/// </summary>
/// <returns>true ak binding bol uspesny</returns>
bool Server::bindPort()
{
	const int RetryCount = 3;
		for (auto connectionTries = 1; socket.bind(ServerPort, ServerIp) != sf::Socket::Done; ++connectionTries)
		{
			if (connectionTries >= RetryCount)
			{
				std::cerr << "Unable to bind on port " << ServerPort << "\n";
				running = false;
				break;
			}
		}
	
		if (running)
		{
			std::cout << "Binding to " << ServerIp.toString() << ":" << ServerPort << " was successful\n";
			std::cout << "Waiting for client messages...\n";
			return true;
		}
		return false;
}

/// <summary>
/// cakanie na pripojenie klienta
/// </summary>
/// <returns>true ak sa klient pripojil</returns>
bool Server::waitForClient()
{
	if (socket.receive(packetForRecieving, connection.IpAddress, connection.Port) == sf::Socket::Done)
			{
				auto data = ""s;
				packetForRecieving >> data;
		
				std::cout << "== Received (" << connection.IpAddress.toString() << ":" << connection.Port << ") ==\n";
				std::cout << data << "\n";
				std::cout << "Client is connected \n";
				return true;
			}
	
	return false;
}

/// <summary>
/// nastavenie obtiaznosti hry
/// </summary>
void Server::setGameDifficulty()
{
	if (isEasyGame)
	{
		dxBall = dxBall * (float)10.0;
		dyBall = dyBall * (float)10.0;
		delta = delta * (float)10.0;
	}
	else
	{
		dxBall = dxBall * (float)20.0;
		dyBall = dyBall * (float)20.0;
		delta = delta * (float)20.0;
	}
}

/// <summary>
/// getter pre farbu hry, v ciselnej reprezentacii
/// </summary>
/// <returns> 0 - white, 1-red, 2-green, 3- nothing</returns>
int Server::getColorInInt()	
{
	if (colorOfBars == sf::Color::White)
	{
		return 0;
	}
	if (colorOfBars == sf::Color::Red)
	{
		return 1;
	}
	if (colorOfBars == sf::Color::Green)
	{
		return 2;
	}
	return 3;
}

/// <summary>
/// posielanie nastaveni hry klientovi
/// </summary>
void Server::sendSettings()
{
	packetForSending.clear();
	int color = getColorInInt();
	packetForSending << color << startNewGame << maximumPoints;
	if (socket.send(packetForSending, connection.IpAddress, connection.Port) == sf::Socket::Done)
	{
		std::cout << "Send settings " << color << " " << startNewGame << " " << maximumPoints << "\n";
	}
}

/// <summary>
/// konstruktor triedy Server, nastavenie parametrov, spustenie menu a spustenie komunikacie
/// </summary>
Server::Server()
{
	srand((unsigned int)time(NULL));
	title = "SFML Pong Game! Player 1 - SERVER!";
	bar1posY = BARS_START_Y;
	bar2posY = BARS_START_Y;
	dxBall = float(rand()) / float((RAND_MAX)) * (float)((rand() % 2) * 2 - 1); // generating float beetween -1 and 1
	dyBall = float(rand()) / float((RAND_MAX)) * (float)((rand() % 2) * 2 - 1); // generating float beetween -1 and 1
	delta = (float)(abs(dxBall) / 2.0 + 0.01);
	XBall = (float)(WINDOW_WIDTH / 2 - BALL_RADIUS);
	YBall = (float)(WINDOW_HEIGHT / 2 - BALL_RADIUS);
	runMenu();
	if (!exitPressed)
	{
		initCommunication();
		sendSettings();
	}
}

/// <summary>
/// destruktor triedy Server
/// </summary>
Server::~Server()
{
	
}

/// <summary>
/// funkcia na zistovanie vstupu klienta, stlacenie klaves, uzatvorenie okna
/// </summary>
void Server::isKeyPressed()
{
	while (window->pollEvent(ev)) {
		if (ev.type == sf::Event::Closed)
		{
			running = false;
			windowRunning = false;
			window->close();			
		}

		if (ev.type == sf::Event::KeyPressed)
		{
			switch (ev.key.code)
			{
			case sf::Keyboard::Up:
				if (bar1posY >= speedBar)
				{
					bar1posY -= speedBar;
				}
				break;
			case sf::Keyboard::Down:
				if (bar1posY <= windowHeight - barHeight - speedBar)
				{
					bar1posY += speedBar;
				}
				break;
			}
		}
	}
}

/// <summary>
/// funkcia na kontrolu kolizii v hre
/// </summary>
void Server::controlColisions()
{
	if (XBall <= 0 )
	{
		dxBall = (float)((rand() % 2) * 2 - 1) * dxBall;
		dyBall = (float)((rand() % 2) * 2 - 1) * dyBall;
		XBall = windowWidth/2 - ballRadius;
		YBall = windowHeight/2 - ballRadius;
		clientsPoints++;

	}
	if (XBall + 2 * ballRadius >= windowWidth)
	{
		dxBall = (float)((rand() % 2) * 2 - 1) * dxBall;
		dyBall = (float)((rand() % 2) * 2 - 1) * dyBall;
		XBall = windowWidth / 2 - ballRadius;
		YBall = windowHeight / 2 - ballRadius;
		serversPoints++;
	}
	if (YBall <= 0 || YBall + 2 * ballRadius >= windowHeight)
	{
		dyBall = -dyBall;
	}
	if (XBall <= barLeft.getPosition().x + barWidth + delta && XBall >= barLeft.getPosition().x + barWidth - delta  && YBall + ballRadius > bar1posY && YBall + ballRadius < bar1posY + barHeight)
	{
		dxBall = -dxBall;
	}
	if (XBall + 2.0 * ballRadius >= (float)barRight.getPosition().x - delta && XBall + 2.0 * ballRadius <= (float)barRight.getPosition().x + delta && YBall + ballRadius > bar2posY && YBall + ballRadius < bar2posY + barHeight)
	{
		dxBall = -dxBall;
	}
}

/// <summary>
/// funkcia na pohyb lopty v hre, zmena jej suradnic
/// </summary>
void Server::moveBall()
{
	XBall += dxBall;
	YBall += dyBall;
}

/// <summary>
/// funkcia na obnovenie suradnic grafickych objektov
/// </summary>
void Server::update()
{
	isKeyPressed();
	mutex.lock();
	controlColisions();
	moveBall();
	ball.setPosition(XBall, YBall);
	barLeft.setPosition(leftBarX, bar1posY);
	barRight.setPosition(rightBarX, bar2posY);
	points[0].setString(std::to_string(serversPoints)); //prevedenie int na string
	points[1].setString(std::to_string(clientsPoints)); //prevedenie int na string
	mutex.unlock();
}

/// <summary>
/// funkcia na vykreslenie grafickeho okna hry
/// </summary>
void Server::render()
{
	window->clear();
	//draw window
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
/// funkcia na spustenie menu, kde sa nastavia parametre hry
/// </summary>
void Server::runMenu()
{
	StartMenu menu;
	bool tmpRunning = true;
	menu.setIpInfo(sf::IpAddress::getLocalAddress().toString(), ServerPort);
	while (tmpRunning)
	{
		tmpRunning = menu.isRunning();
		menu.drawMenu();
	}
	if (menu.isNewGame())
	{
		colorOfBars = menu.getColor();
		startNewGame = menu.isNewGame();
		isEasyGame = menu.isEasyGame();
		setGameDifficulty();
	}
	else
	{
		exitPressed = true;
	}	
}

/// <summary>
/// spustenie vlakien a cakanie na ich dokoncenie
/// </summary>
void Server::runThreads()
{
	if (startNewGame)
	{
		std::thread consuming(&Server::threadForConsuming, this);
		std::thread sending(&Server::threadForSending, this);
		std::thread recieving(&Server::threadForRecieving, this);

		consuming.join();
		sending.join();
		recieving.join();
	}	
}

/// <summary>
/// inicializacia komunikacie s klientom
/// </summary>
void Server::initCommunication()
{
	std::signal(SIGTERM, signal_handler);
	running = true;
	bindPort();
	waitForClient();
}

/// <summary>
/// funkcia spustana vo vlakne, posiela data klientovi
/// </summary>
void Server::threadForSending()
{
	while (running)
	{
		if (clientsPoints >= maximumPoints || serversPoints >= maximumPoints)
		{
			running = false;
		}
		packetForSending.clear();
		packetForSending << XBall << YBall << bar1posY << serversPoints << clientsPoints << running;
		if (socket.send(packetForSending, connection.IpAddress, connection.Port) == sf::Socket::Done)
		{
			std::cout << "Send " << XBall << " " << YBall << " " << bar1posY << " " << serversPoints << " " << clientsPoints << running << "\n";
		}
		else
		{
			std::cout << "Sending failed\n"; 
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(50));		
	}
}

/// <summary>
/// funkcia spustena vo vlakne, prijima data od klienta
/// </summary>
void Server::threadForRecieving()
{
	while (running)
	{
		packetForRecieving.clear();
		if (socket.receive(packetForRecieving, connection.IpAddress, connection.Port) == sf::Socket::Done)
		{
			mutex.lock();
			packetForRecieving >> bar2posY;
			mutex.unlock();
			std::cout << "== Received position of right from client (" << connection.IpAddress.toString() << ":" << connection.Port << ") ==\n";
			std::cout << bar2posY << "\n";
		}
		else
		{
			std::cout << "Recieving data from client failed\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
}

/// <summary>
/// funkcia spustena vo vlakne, spracuva prijate data a vykresluje graficke zobrazenie
/// </summary>
void Server::threadForConsuming()
{
	initWindow();
	initBall();
	initBars();
	initPoints();
	render();
	window->setActive(true);
	while (running)
	{
		//mutex.lock();		
		update();
		//mutex.unlock();
		render();
		std::this_thread::sleep_for(std::chrono::milliseconds(30));
	}
	sf::Text result;
	std::string text;
	if (serversPoints >= maximumPoints)
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

