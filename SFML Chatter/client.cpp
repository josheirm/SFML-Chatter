#include "client.h"
#include "string.h"

//acer - 3 , emachine 5
#define dlastdigit 3


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
}


client::~client()
{
}

void client::connect()
{
	sf::TcpSocket socket;
	//acer - 3, emachine - 5
	sf::Socket::Status status = socket.connect("0.0.0.dlastdigit", 53000);
	
	if (status != sf::Socket::Done)
	{
		// error...
	}

}