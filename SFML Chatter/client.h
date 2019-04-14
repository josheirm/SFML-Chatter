#include "SFML/Network.hpp"
#include <SFML/Network/IpAddress.hpp>
#pragma once
class client
{



public:
	//lpAddress = 0;

	void getLocalAddress();

	void connect();
	client();
	~client();
};

