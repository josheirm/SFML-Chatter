#include "Server.h"
#include "SFML/Network.hpp"


server::server()
{
	isMessage = false;

	strcpy_s(data, "zzzz");
	
}

void server::serverListen()
{

	// bind the listener to a port
	if (listener.listen(53000) != sf::Socket::Done)
	{
		// error...
	}

	// accept a new connection
	//client clientofServer;
	if (listener.accept(clientsocket) != sf::Socket::Done)
	{
		// error...
	}

}


sf::TcpListener& server::getServerListener()
{
	return(listener);
}

client &server::getClientObject()
{
	return(clientofServer);
}

void server::sendData()
{
	if (clientofServer.socket.send(data, 5) != sf::Socket::Done)
	{
		// error...
	}


}


void server::receiveData()
{
	sf::String test = "";
	sf::String &  temp = test;

	// TCP socket:
	
	//!= sf::Socket::Done
	clientofServer.socket.receive(packet);
	//{
	//	std::cout << "error server received"<<std::endl;
	//}
	//extract
	packet >>   temp;
	std::string s1 = temp;
	
	if (s1 != "")
	{
		std::cout << ":: " << s1;
		isMessage = true;
		//chatBox->addTexttoChatBox(temp);
		serverInputBox.chatBox.addTexttoChatBox(temp);
	}
	
}
server::~server()
{
}

void server::copyInputBox( input_Box & copy)
{
	serverInputBox = copy;
}
