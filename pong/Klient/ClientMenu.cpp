#include "ClientMenu.h"

/// <summary>
/// konstruktor triedy ClientMenu
/// </summary>
ClientMenu::ClientMenu()
{
	initWindow();
	initMenu();

}

/// <summary>
/// destruktor triedy ClientMenu
/// </summary>
ClientMenu::~ClientMenu()
{
	delete window;
}

/// <summary>
/// vykreslenie okna a grafickych objektov
/// </summary>
void ClientMenu::drawMenu()
{
	pollEvent();
	window->clear();

	for (int i = 0; i < MENU_OPTIONS; i++)
	{
		window->draw(menu[i]);
	}

	for (int i = 0; i < IP_PORT; i++)
	{
		window->draw(IP_Port[i]);
	}
	window->draw(header);
	window->draw(headerIP);
	window->draw(headerPort);
	window->draw(valueIP);
	window->draw(valuePort);

	window->display();
}

/// <summary>
/// vyhodnotenie stlacenia klavesy Up
/// </summary>
void ClientMenu::moveUp()
{
	if (indexOfOption - 1 >= 0)
	{

		switch (indexOfOption)
		{
		case 1:
			IP_Port[0].setOutlineColor(sf::Color::White);
			menu[0].setFillColor(sf::Color::Red);
			indexOfOption--;
			break;
		case 2:
			IP_Port[1].setOutlineColor(sf::Color::White);
			IP_Port[0].setOutlineColor(sf::Color::Red);
			indexOfOption--;
			break;
		case 3:
			menu[1].setFillColor(sf::Color::White);
			IP_Port[1].setOutlineColor(sf::Color::Red);
			indexOfOption--;
			break;
		default:
			break;
		}

	}
}

/// <summary>
/// vyhodnotenie stlacenia klavesy Down
/// </summary>
void ClientMenu::moveDown()
{
	if (indexOfOption + 1 < MENU_OPTIONS + IP_PORT)
	{
		switch (indexOfOption)
		{
		case 0:
			menu[0].setFillColor(sf::Color::White);
			IP_Port[0].setOutlineColor(sf::Color::Red);
			indexOfOption++;
			break;
		case 1:
			IP_Port[0].setOutlineColor(sf::Color::White);
			IP_Port[1].setOutlineColor(sf::Color::Red);
			indexOfOption++;
			break;
		case 2:
			IP_Port[1].setOutlineColor(sf::Color::White);
			menu[1].setFillColor(sf::Color::Red);
			indexOfOption++;
			break;
		default:
			break;
		}
	}
}

/// <summary>
/// nastavenie IP adresy na zaklade vstupu cez konzolu
/// </summary>
void ClientMenu::enterIP()
{
	std::cout << "Input IP address : ";
	std::cin >> IP;
	std::cout << "IP adress is set to: " << IP << "\n";
	valueIP.setFont(pismo);
	valueIP.setFillColor(sf::Color::White);
	valueIP.setString(IP);
	valueIP.setCharacterSize(40);
	valueIP.setPosition(289, 319);
}

/// <summary>
/// nastavenie portu na zaklade vstupu cez konzolu
/// </summary>
void ClientMenu::enterPort()
{
	std::cout << "Input Port : ";
	std::cin >> Port;
	std::cout << "Port is set to: " <<  Port << "\n";
	valuePort.setFont(pismo);
	valuePort.setFillColor(sf::Color::White);
	valuePort.setString(Port);
	valuePort.setCharacterSize(40);
	valuePort.setPosition(450, 391);
}

/// <summary>
/// vyhodnocovanie akcii pouzivatela - stlacenie klaves, zavretie okna
/// </summary>
void ClientMenu::pollEvent()
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
					std::cout << "Join game button has been pressed!" << std::endl;
					joinPressed = true;
					window->close();
					running = false;
					break;
				case 1:
					std::cout << "IP button has been pressed!" << std::endl;
					enterIP();
					break;
				case 2:
					std::cout << "Port button has been pressed!" << std::endl;
					enterPort();
					break;
				case 3:
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
void ClientMenu::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "PONG - CLIENT");
	running = true;
}

/// <summary>
/// inicializacia textovych objektov
/// </summary>
void ClientMenu::initMenu()
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

	header.setFont(amatic);
	header.setFillColor(sf::Color::White);
	header.setString("PONG");
	header.setCharacterSize(140);
	header.setPosition(295, 50);

	menu[0].setFont(pismo);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("JOIN GAME");
	menu[0].setCharacterSize(60);
	menu[0].setPosition(220, 230);

	headerIP.setFont(pismo);
	headerIP.setFillColor(sf::Color::White);
	headerIP.setString("IP");
	headerIP.setCharacterSize(60);
	headerIP.setPosition(165, 310);

	valueIP.setFont(pismo);
	valueIP.setFillColor(sf::Color::Black);
	valueIP.setString(IP);
	valueIP.setCharacterSize(0);
	valueIP.setPosition(300, 220);

	headerPort.setFont(pismo);
	headerPort.setFillColor(sf::Color::White);
	headerPort.setString("PORT");
	headerPort.setCharacterSize(60);
	headerPort.setPosition(165, 380);

	valuePort.setFont(pismo);
	valuePort.setFillColor(sf::Color::Black);
	valuePort.setString(Port);
	valuePort.setCharacterSize(0);
	valuePort.setPosition(300, 400);

	IP_Port[0].setSize(sf::Vector2f(350, 50));
	IP_Port[0].setOutlineColor(sf::Color::White);
	IP_Port[0].setOutlineThickness(3);
	IP_Port[0].setFillColor(sf::Color::Black);
	IP_Port[0].setPosition(260, 320);

	IP_Port[1].setSize(sf::Vector2f(200, 50));
	IP_Port[1].setOutlineColor(sf::Color::White);
	IP_Port[1].setOutlineThickness(3);
	IP_Port[1].setFillColor(sf::Color::Black);
	IP_Port[1].setPosition(410, 393);

	menu[1].setFont(pismo);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("EXIT");
	menu[1].setCharacterSize(60);
	menu[1].setPosition(310, 480);

	indexOfOption = 0;
	menu[indexOfOption].setFillColor(sf::Color::Red);
}

/// <summary>
/// zistenie, ci program bezi
/// </summary>
/// <returns>true ak program bezi</returns>
bool ClientMenu::isRunning()
{
	return running;
}

/// <summary>
/// zistenie, ci bolo stlacene Join
/// </summary>
/// <returns>true ak join bolo stlacene</returns>
bool ClientMenu::isJoinPressed()
{
	return joinPressed;
}
/// <summary>
/// getter na zadanu IP adresu
/// </summary>
/// <returns>zadana IP adresa</returns>
sf::IpAddress ClientMenu::getIp()
{
	if (IP.empty())
	{
		return sf::IpAddress::Any;
	}
	sf::IpAddress ip(IP);
	return ip;
}

/// <summary>
/// getter pre zadany port
/// </summary>
/// <returns>zadany port</returns>
int ClientMenu::getPort()
{
	if (Port.empty())
	{
		return 0;
	}
	int port = stoi(Port);
	return port;
}

