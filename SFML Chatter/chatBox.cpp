#include "chatBox.h"



chat_Box::chat_Box()
{
	chatbox = tgui::ChatBox::create();
}

void chat_Box::drawChatBox(tgui::Gui& gui)
{
	{
		
		//chatbox->setRenderer(theme.getRenderer("ChatBox"));
		chatbox->setSize(500, 200);
		chatbox->setTextSize(18);
		chatbox->setPosition(100, 300);
		chatbox->setLinesStartFromTop();
		chatbox->addLine("texus: Hey, this is TGUI!", sf::Color::Green);
		chatbox->addLine("Me: Looks awesome! ;)", sf::Color::Yellow);
		chatbox->addLine("texus: Thanks! :)", sf::Color::Green);
		chatbox->addLine("Me: The widgets rock ^^", sf::Color::Yellow);
		gui.add(chatbox);
		


	}


}

chat_Box::~chat_Box()
{
}

void chat_Box::addTexttoChatBox(sf::String  string)
{
	std::string s1 = string;
	chatbox->addLine(string,  sf::Color::Green);

}