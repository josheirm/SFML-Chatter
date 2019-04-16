#include "iostream"
#include "client.h"
#include "string.h"

//acer - 3 , emachine 5
#define dlastdigit 3

void client::sendData()
{
	if (socket.send(data, 5) != sf::Socket::Done)
	{
		// error...
	}
}

void client::receiveData()
{
	// TCP socket:
	if (socket.receive(data, 5, received) != sf::Socket::Done)
	{
		std::cout << "failed recieve data\n";
		// error...
	}
	else
	{
		std::cout << "data: "<<data<<"\n";
	}
	//std::cout << "Received " << received << " bytes" << std::endl;


}

sf::TcpSocket& client::getClientSocket()
{
	return(socket);
}


void client::getLocalAddress()
{
	sf::IpAddress address(0,0,0,0);
	//static sf::IpAddress address
	address = sf::IpAddress::getLocalAddress();
	//std::string = 
	std::string address_ = address.toString();
	fprintf(stderr, ":  %s", address_.c_str());
	
}
client::client()
{
	strcpy_s(data, "test");
	//input_Box * socket = new input_Box();
	//data[5] = "test\0";
}

sf::TcpSocket& client::getSocket()
{
	return(socket);
}

client::~client()
{
}

int client::clientConnect()
{
	//sf::TcpSocket socket;
	//acer - 3, emachine - 5
	//sf::Socket::Status status = socket.connect("0.0.0.3", 53000);
	
	//connect to server - emachine
	sf::Socket::Status status = socket.connect("10.0.0.5", 53000);
	
	if (status != sf::Socket::Done)
	{
		// error...
		//std::cout << "failed connect\n";
		return(0);
	}
	else
	{
		std::cout << "passed connect\n";
		return(1);
	}

}