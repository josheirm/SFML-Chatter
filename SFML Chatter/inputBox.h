#pragma once
#include <TGUI/TGUI.hpp>
//#include <TGUI/Widgets/ClickableWidget.hpp>
//#include <TGUI/Widget.hpp>
#include <TGUI/Widgets/Button.hpp>
//#include <TGUI/Text.hpp>
#include <TGUI/Widgets/TextBox.hpp>
#include <TGUI/Widgets/ChatBox.hpp>
#include "chatBox.h"
#include <SFML/Graphics/Text.hpp>
//Button Button;

typedef std::shared_ptr< tgui::TextBox >ConstPtrTextBox;

//typedef std::shared_ptr< Button >Ptr;
#include <TGUI/TGUI.hpp>
#include <SFML/System/String.hpp>
#include <string.h>

class input_Box
{
public:
	tgui::Button button_;
	tgui::TextBox text_Box;
	ConstPtrTextBox  inputTextBox;
	chat_Box chatBox;

	//bool getisMessage();
	//void setisMessage(bool value);

	bool g_sendTexttoServerFlag;
	int buttonPressed();
	void eraseText();
	//const sf::String &	text = "";
	//static tgui::Button::Ptr tgui::Button::create(text);

	//tgui::Button button = tgui::ChildWindow::create();

	 //const sf::String  & storedString = "";

	void drawWindow(tgui::Gui& gui);
	
	//consider changing this to a reference
	   const sf::String   getTextFunct();
	
	   
	
	//void eraseText();

	input_Box();
	~input_Box();
};

