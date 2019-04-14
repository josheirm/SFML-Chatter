#include "SFML/Network.hpp"
#include <SFML/Network/IpAddress.hpp>
#pragma once
class client
{



public:
	sf::TcpSocket socket;
	std::size_t received;

	char data[5];
	void receiveData();
	//sf::TcpSocket clientSocket;
	sf::TcpSocket& getSocket();
	sf::TcpSocket & getClientSocket();
	void clientConnect();

	
	
	void getLocalAddress();
	void sendData();
	//void connect();
	client();
	~client();
};

