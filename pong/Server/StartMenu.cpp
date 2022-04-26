#include "StartMenu.h"

/// <summary>
/// konstruktor triedy StartMenu
/// </summary>
StartMenu::StartMenu()
{
	initWindow();
	initMenu();
	initpaddleColours();	
}

/// <summary>
/// destruktor triedy StartMenu
/// </summary>
StartMenu::~StartMenu()
{
	delete window;
}

/// <summary>
/// vykreslenie grafickych objektov v okne
/// </summary>
void StartMenu::drawMenu()
{
	pollEvent();
	window->clear();

	for (int i = 0; i < MENU_OPTIONS; i++)
	{
		window->draw(menu[i]);
	}

	for (int i = 0; i < PADDLE_COLOURS; i++)
	{
		window->draw(paddleColours[i]);
	}
	window->draw(header);
	window->draw(ipAddText);
	window->draw(portText);
	window->display();
}

/// <summary>
/// akcia po stlaceni klavesy Up
/// </summary>
void StartMenu::moveUp()
{
	if (indexOfOption - 1 >= 0)
	{

		switch (indexOfOption)
		{
		case 1:
			menu[1].setFillColor(sf::Color::White);
			menu[0].setFillColor(sf::Color::Red);
			indexOfOption--;
			break;
		case 2:
			menu[2].setFillColor(sf::Color::White);
			menu[1].setFillColor(sf::Color::Red);
			indexOfOption--;
			break;
		case 3:
			paddleColours[0].setOutlineThickness(0);
			menu[2].setFillColor(sf::Color::Red);
			paddleColours[0].setOutlineColor(sf::Color(0, 0, 255));
			indexOfOption--;
			break;
		case 4:
			paddleColours[1].setOutlineThickness(0);
			paddleColours[0].setOutlineThickness(4);
			paddleColours[0].setOutlineColor(sf::Color(0, 0, 255));
			indexOfOption--;
			break;
		case 5:
			paddleColours[2].setOutlineThickness(0);
			paddleColours[1].setOutlineThickness(4);
			paddleColours[1].setOutlineColor(sf::Color(0, 0, 255));
			indexOfOption--;
			break;
		case 6:
			menu[3].setFillColor(sf::Color::White);
			paddleColours[2].setOutlineThickness(4);
			paddleColours[2].setOutlineColor(sf::Color(0, 0, 255));
			indexOfOption--;
			break;
		default:
			break;
		}

	}
}

/// <summary>
/// akcia po stlaceni klavesy Down
/// </summary>
void StartMenu::moveDown()
{
	if (indexOfOption + 1 < MENU_OPTIONS + PADDLE_COLOURS)
	{
		switch (indexOfOption)
		{
		case 0:
			menu[0].setFillColor(sf::Color::White);
			indexOfOption++;
			menu[indexOfOption].setFillColor(sf::Color::Red);
			break;
		case 1:
			menu[1].setFillColor(sf::Color::White);
			indexOfOption++;
			menu[indexOfOption].setFillColor(sf::Color::Red);
			break;
		case 2:
			menu[2].setFillColor(sf::Color::White);
			paddleColours[0].setOutlineThickness(4);
			paddleColours[0].setOutlineColor(sf::Color(0, 0, 255));
			indexOfOption++;
			break;
		case 3:
			paddleColours[0].setOutlineThickness(0);
			paddleColours[1].setOutlineThickness(4);
			paddleColours[1].setOutlineColor(sf::Color(0, 0, 255));
			indexOfOption++;
			break;
		case 4:
			paddleColours[1].setOutlineThickness(0);
			paddleColours[2].setOutlineThickness(4);
			paddleColours[2].setOutlineColor(sf::Color(0, 0, 255));
			indexOfOption++;
			break;
		case 5:
			paddleColours[2].setOutlineThickness(0);
			menu[3].setFillColor(sf::Color::Red);
			indexOfOption++;
			break;
		default:
			break;
		}
	}
}

/// <summary>
/// funkcia na kontrolu vstupu pouzivatela, stlacenie klaves a uzavretie okna
/// </summary>
void StartMenu::pollEvent()
{
	while (window->pollEvent(ev))
	{
		switch (ev.type)
		{
		case sf::Event::KeyReleased:
			switch (ev.key.code)
			{
			case sf::Keyboard::Up:
				moveUp();
				break;

			case sf::Keyboard::Down:
				moveDown();
				break;

			case sf::Keyboard::Return:
				switch (getChoosedOption())
				{
				case 0:
					std::cout << "New game button has been pressed!" << std::endl;
					newGamePressed = true;
					window->close();
					running = false;
					break;
				case 1:
					std::cout << "Easy button has been pressed!" << std::endl;
					isChoosenEasyGame = true;
					break;
				case 2:
					std::cout << "Hard button has been pressed!" << std::endl;
					isChoosenEasyGame = false;
					break;
				case 3:
					std::cout << "White colour button has been pressed!" << std::endl;
					choosenColor = sf::Color::White;
					break;
				case 4:
					std::cout << "Red colour button has been pressed!" << std::endl;
					choosenColor = sf::Color::Red;
					break;
				case 5:
					std::cout << "Green colour button has been pressed!" << std::endl;
					choosenColor = sf::Color::Green;
					break;
				case 6:
					std::cout << "Exit button has been pressed!" << std::endl;
					window->close();
					running = false;
					break;
				}
				break;
			}
			break;
		case sf::Event::Closed:
			window->close();
			running = false;
			break;
		}
	}
}

/// <summary>
/// inicializacia grafickeho okna
/// </summary>
void StartMenu::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "PONG - SERVER");
	running = true;
}

/// <summary>
/// inicializacia textovych objektov
/// </summary>
void StartMenu::initMenu()
{
	if (!pismo.loadFromFile("arial.ttf"))
	{
		printf("File arial.ttf is missing!\n");
		exit;
	}

	if (!amatic.loadFromFile("Amatic-Bold.ttf"))
	{
		printf("File Amatic-Bold.ttf is missing!\n");
		exit;
	}

	ipAddText.setFont(pismo);
	ipAddText.setFillColor(sf::Color::White);
	ipAddText.setCharacterSize(20);
	ipAddText.setPosition(550, 20);

	portText.setFont(pismo);
	portText.setFillColor(sf::Color::White);
	portText.setCharacterSize(20);
	portText.setPosition(550, 50);

	header.setFont(amatic);
	header.setFillColor(sf::Color::White);
	header.setString("PONG");
	header.setCharacterSize(140);
	header.setPosition(295, 50);
	for (int i = 0; i < MENU_OPTIONS; i++)
	{
		menu[i].setFont(pismo); //nastavenie druhu pisma
		menu[i].setFillColor(sf::Color::White); //nastavenie farbz
		menu[i].setCharacterSize(60);
	}

	menu[0].setString("NEW GAME"); //popis danej moznosti
	menu[0].setPosition(220, 250); //pozicia textu

	menu[1].setString("EASY");
	menu[1].setPosition(200, 330);

	menu[2].setString("HARD");
	menu[2].setPosition(400, 330);
	
	menu[3].setString("EXIT");
	menu[3].setPosition(310, 500);

	indexOfOption = 0;
	menu[indexOfOption].setFillColor(sf::Color::Red);
}

/// <summary>
/// inicializacia grafickych objektov reprezentujucich farby
/// </summary>
void StartMenu::initpaddleColours()
{
	for (int i = 0; i < PADDLE_COLOURS; i++)
	{
		paddleColours[i].setRadius(15);
	}
	paddleColours[0].setFillColor(sf::Color(255, 255, 255));
	paddleColours[0].setPosition(310, 430);

	paddleColours[1].setFillColor(sf::Color(255, 0, 0));
	paddleColours[1].setPosition(370, 430);

	paddleColours[2].setFillColor(sf::Color(0, 255, 0));
	paddleColours[2].setPosition(430, 430);

}

/// <summary>
/// getter pre nastavenu farbu
/// </summary>
/// <returns>zadanu farby hry</returns>
sf::Color StartMenu::getColor()
{
	return choosenColor;
}

/// <summary>
/// getter pre urcenie obtiaznosti hry
/// </summary>
/// <returns>true ak bola zvolena moznost Easy</returns>
bool StartMenu::isEasyGame()
{
	return isChoosenEasyGame;
}

/// <summary>
/// getter pre urcenie, ci bola stlacena moznost zacatia hry
/// </summary>
/// <returns>true ak moznost New Game bola stlacena</returns>
bool StartMenu::isNewGame()
{
	return newGamePressed;
}

/// <summary>
/// getter pre zistenie behu programu
/// </summary>
/// <returns>true ak program bezi</returns>
bool StartMenu::isRunning()
{
	return running;
}

/// <summary>
/// funcia na nastavenie parametrov triedy na zaklade zadanych udajov
/// </summary>
/// <param name="ipAddress">string zadadej ip adresy</param>
/// <param name="port">zadany port</param>
void StartMenu::setIpInfo(std::string ipAddress, int port)
{
	ipAddText.setString("ip-address: " + ipAddress);
	portText.setString("port: " + std::to_string(port));
}
