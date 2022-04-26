#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <SFML/Network.hpp>
#include <iostream>
#include <csignal>
#include <atomic>
#include <string>
#include <mutex>
#include <stdio.h>
#include <stdlib.h>
#include "StartMenu.h"

#define PORT 55000
#define BALL_RADIUS 20.0f
#define NUM_OF_PLAYERS 2
#define MAXIMUM_POINTS 5
#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800
#define FPS 60
#define SPEED_BARS 10.0f
#define BARS_START_Y 230.0f
#define BAR_WIDTH 30.0f
#define BAR_HEIGHT 100.0f
#define LEFT_BAR_X 50.0f
#define RIGHT_BAR_X WINDOW_WIDTH - LEFT_BAR_X - BAR_WIDTH

using namespace std::string_literals;

struct Connection
{
	sf::IpAddress IpAddress;
	unsigned short Port;
};

namespace {
	volatile std::atomic<bool> running = true;
	void signal_handler(int)
	{
		running = false;
	}
}

/// <summary>
/// trieda Server, vykresli menu pre nastavenia hry, komunikuje s klientom, spracuvava data hry a vykresluje graficke zobrazenie
/// </summary>
class Server
{
private:
	float bar1posY, bar2posY;
	int windowHeight = WINDOW_HEIGHT;
	int windowWidth = WINDOW_WIDTH;
	float ballRadius = BALL_RADIUS;
	float barWidth = BAR_WIDTH;
	float barHeight = BAR_HEIGHT;
	float leftBarX = LEFT_BAR_X;
	float rightBarX = RIGHT_BAR_X;
	float speedBar = SPEED_BARS;
	int maximumPoints = MAXIMUM_POINTS;
	float dxBall, dyBall, XBall, YBall, delta;
	sf::RenderWindow* window;
	sf::CircleShape ball;
	sf::Event ev;
	sf::RectangleShape barLeft;
	sf::RectangleShape barRight;
	sf::Font pismo;
	std::string title;

	const sf::IpAddress ServerIp = sf::IpAddress::Any;
	const int ServerPort = PORT;
	sf::UdpSocket socket;
	Connection connection = Connection{};
	sf::Packet packetForSending = sf::Packet{};
	sf::Packet packetForRecieving = sf::Packet{};
	std::mutex mutex;
	bool startNewGame = false;
	bool isEasyGame = true;
	sf::Color colorOfBars;
	int clientsPoints = 0;
	int serversPoints = 0;
	sf::Text points[NUM_OF_PLAYERS];
	bool windowRunning;
	bool exitPressed = false;

	void initWindow();
	void initBall();
	void initBars();
	void initPoints();
	void initCommunication();
	bool bindPort();
	bool waitForClient();
	void setGameDifficulty();
	int getColorInInt();
	void sendSettings();
	void threadForSending();
	void threadForRecieving();
	void threadForConsuming();
	void isKeyPressed();
	void controlColisions();
	void moveBall();
	void update();
	void render();

public:
	Server();
	~Server();
	void runMenu();
	void runThreads();
};
