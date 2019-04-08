#include "Keyboard.h"
#include <SFML/Window.hpp>
//#include <SFML/Graphics.hpp>
//#include <vector>


Keyboard::Keyboard()
{
	if (!font.loadFromFile("arial.ttf"))
	{
		fprintf(stderr, "error!\n");
	}

	text.setFont(font);
	chatString = { NULL };
	sendIt = 0;
	
}


Keyboard::~Keyboard()
{
}


int Keyboard::getKey()
{
	// TODO: Add your implementation code here.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		chatString = chatString + "A";
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	{
		chatString = chatString + "B";
	}
	
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	{
		chatString = chatString + "C";
	}
	
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		sendIt = 1;
	}
	

	return 0;
}
