#include "SFML/Network.hpp"
#include <SFML/Network/IpAddress.hpp>
#include "inputBox.h"
#pragma once
class client
{



public:

	
	void copyInputBox( input_Box & copy);
	input_Box clientInputBox;
	sf::TcpSocket socket;
	std::size_t received;
	sf::Packet packet;

	char data[5];
	void receiveData();
	//sf::TcpSocket clientSocket;
	sf::TcpSocket& getSocket();
	sf::TcpSocket & getClientSocket();
	int clientConnect();

	
	
	void getLocalAddress();
	void sendData();
	//void connect();
	client();
	~client();
};

