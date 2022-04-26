#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include <string>
#include <iostream>

#define MENU_OPTIONS 2
#define IP_PORT 2

/// <summary>
/// trieda ClientMenu, vykresluje graficke okno pre klienta, kde klient zadava IP adresu a port na ktory sa chce pripojit
/// </summary>
class ClientMenu
{
private:
	int indexOfOption;
	sf::Texture texture;
	sf::Font pismo;
	sf::Font amatic;
	sf::Text menu[MENU_OPTIONS];
	sf::RectangleShape IP_Port[IP_PORT];
	sf::Text header;
	sf::Text headerIP;
	sf::Text headerPort;
	std::string IP;
	std::string Port;
	sf::Text valueIP;
	sf::Text valuePort;
	sf::RenderWindow* window;
	sf::Event ev;
	bool running = false;
	bool joinPressed = false;

public:
	ClientMenu();
	~ClientMenu();
	void drawMenu();
	void moveUp();
	void moveDown();
	int getChoosedOption() { return indexOfOption; }
	void enterIP();
	void enterPort();
	void pollEvent();
	void initWindow();
	void initMenu();
	bool isRunning();
	bool isJoinPressed();
	sf::IpAddress getIp();
	int getPort();
};

