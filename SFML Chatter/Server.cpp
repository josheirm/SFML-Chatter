#include "Server.h"
#include "SFML/Network.hpp"


server::server()
{

	strcpy_s(data, "test");
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

client& server::getClientObject()
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
	// TCP socket:
	if (clientofServer.socket.receive(data, 5, received) != sf::Socket::Done)
	{
		std::cout << "error server received";
	}
	
	//std::cout << "recievd passed - is here!";
	//std::cout << "Received " << received << " bytes" << std::endl;


}
server::~server()
{
}
