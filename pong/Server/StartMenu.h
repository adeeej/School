#pragma once
#include "SFML/Graphics.hpp"
#include <String>
#include <iostream>
#include<sstream>  

#define MENU_OPTIONS 4
#define PADDLE_COLOURS 3

/// <summary>
/// trieda StartMenu, zobrazi graficke okno kde pouzivatel nastavi parametre hry akymi su obtiaznost a farba objektov
/// </summary>
class StartMenu
{
private:
	int indexOfOption;
	sf::Texture texture;
	sf::Font pismo;
	sf::Font amatic;
	sf::Text menu[MENU_OPTIONS];
	sf::CircleShape paddleColours[PADDLE_COLOURS];
	sf::Text header;
	sf::RenderWindow* window;
	sf::Event ev;
	bool running = false;
	sf::Color choosenColor = sf::Color::White;
	bool isChoosenEasyGame = true;
	bool newGamePressed = false;
	sf::Text ipAddText;
	sf::Text portText;

public:
	StartMenu();
	~StartMenu();
	void drawMenu();
	void moveUp();
	void moveDown();
	int getChoosedOption() { return indexOfOption; }
	void pollEvent();
	void initWindow();
	void initMenu();
	void initpaddleColours();
	sf::Color getColor();
	bool isEasyGame();
	bool isNewGame();
	bool isRunning();
	void setIpInfo(std::string ipAddress, int port);
	
};

