#pragma once
#include  <TGUI/TGUI.hpp>
#include <SFML/Network/TcpListener.hpp>
#include "client.h"
#include <iostream>

class server
{
public:
	sf::TcpSocket clientsocket;

	std::size_t received;
	void receiveData();
	client clientofServer;

	sf::TcpListener listener;
	sf::TcpListener & getServerListener();
	void serverListen();

	//sf::TcpSocket socket;
	char data[100] = "test";

	client& getClientObject();
	


	

	//void listenforConnection();
	
	void sendData();

	server();
	~server();
};

