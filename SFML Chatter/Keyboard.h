#pragma once
#include <SFML/Graphics.hpp>
class Keyboard
{
public:
	Keyboard();
	sf::Font font;
	sf::Text text;

	
	~Keyboard();
	int getKey();

private:
	int sendIt;

	std::string chatString;
};

