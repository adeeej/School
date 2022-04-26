#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <csignal>
#include <atomic>
#include <string>
#include <mutex>
#include <condition_variable>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <vector>
#include "ClientMenu.h"

#define NUM_OF_PLAYERS 2

#define BALL_RADIUS 20.0f
#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800
#define FPS 60
#define BARS_START_Y 230.0f
#define SPEED_BARS 10.0f
#define BAR_WIDTH 30.0f
#define BAR_HEIGHT 100.0f
#define LEFT_BAR_X 50.0f
#define RIGHT_BAR_X WINDOW_WIDTH - LEFT_BAR_X - BAR_WIDTH

using namespace std::string_literals;

namespace
{
	volatile std::atomic<bool> running = true;

	void signal_handler(int)
	{
		running = false;
	}

	enum class CommunicationState
	{
		Send,
		Receive
	};
}

/// <summary>
/// Trieda Client, reprezentujuca klienta, cita vstup od pouzivatela, komunikuje so serverom a vykresluje hru v grafickom prostredi
/// </summary>
class Client
{
private:
	float speedBar = SPEED_BARS;
	int windowHeight = WINDOW_HEIGHT;
	int windowWidth = WINDOW_WIDTH;
	float leftBarX = LEFT_BAR_X;
	float rightBarX = RIGHT_BAR_X;
	float barHeight = BAR_HEIGHT;
	float bar1posY, bar2posY;
	float ballX, ballY;
	std::string title;
	sf::RenderWindow* window;
	sf::Event ev;
	sf::RectangleShape barLeft;
	sf::RectangleShape barRight;
	sf::CircleShape ball;
	sf::UdpSocket socket;
	sf::IpAddress ServerIp = sf::IpAddress::LocalHost;
	int ServerPort = 55000;
	sf::Packet packetForSending;
	sf::Packet packetForRecieving;
	sf::IpAddress ipAddress;
	std::mutex mutex;
	sf::Color colorOfGame = sf::Color::White;
	int maximumPoints = 0;
	bool startNewGame = false;
	int clientsPoints = 0;
	int serversPoints = 0;
	sf::Text points[NUM_OF_PLAYERS];
	sf::Font pismo;
	bool windowRunning;
	bool isValidServerIp = false;

	void initWindow();
	void initBars();
	void initBall();
	void initPoints();
	void initCommunication();
	void setColor(int colorRepresentation);
	void waitForSettings();
	void threadForSending();
	void threadForRecieving();
	void threadForDrawing();
	void isKeyPressed();
	void update();
	void render();
	void runMenu();
public:
	Client();
	~Client();
	void ruhThreads();
};

