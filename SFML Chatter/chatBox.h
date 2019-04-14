#pragma once
#include <TGUI/TGUI.hpp>
#include "chatBox.h"

typedef std::shared_ptr< tgui::ChatBox >ConstPtrChatBox;

class chat_Box
{
public:
	
	ConstPtrChatBox chatbox;



	void addTexttoChatBox(sf::String string);
	void drawChatBox(tgui::Gui& gui);
	

	chat_Box();
	~chat_Box();
};

