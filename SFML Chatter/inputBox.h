#pragma once
#include <TGUI/TGUI.hpp>
//#include <TGUI/Widgets/ClickableWidget.hpp>
//#include <TGUI/Widget.hpp>
#include <TGUI/Widgets/Button.hpp>
//#include <TGUI/Text.hpp>
#include <TGUI/Widgets/TextBox.hpp>
#include <TGUI/Widgets/ChatBox.hpp>
#include "chatBox.h"
//Button Button;

typedef std::shared_ptr< tgui::TextBox >ConstPtrTextBox;

//typedef std::shared_ptr< Button >Ptr;
class input_Box
{
public:
	tgui::Button button_;
	tgui::TextBox text_Box;
	ConstPtrTextBox  inputText;
	chat_Box chat_Box;

	int checkButtonPressed();
	void eraseText();
	const sf::String &	text = "";
	//static tgui::Button::Ptr tgui::Button::create(text);

	//tgui::Button button = tgui::ChildWindow::create();


	void drawWindow(tgui::Gui& gui);
	
	 sf::String & getTextFunct();
	

	
	//void eraseText();

	input_Box();
	~input_Box();
};

