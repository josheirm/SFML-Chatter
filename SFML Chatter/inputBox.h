#pragma once
#include <TGUI/TGUI.hpp>
//#include <TGUI/Widgets/ClickableWidget.hpp>
//#include <TGUI/Widget.hpp>
#include <TGUI/Widgets/Button.hpp>
//#include <TGUI/Text.hpp>
#include <TGUI/Widgets/TextBox.hpp>

//Button Button;



//typedef std::shared_ptr< Button >Ptr;
class input_Box
{
public:
	tgui::Button button_;
	tgui::TextBox  Text_Box;

	const sf::String &	text = "";
	//static tgui::Button::Ptr tgui::Button::create(text);

	//tgui::Button button = tgui::ChildWindow::create();


	void drawWindow(tgui::Gui& gui);
	
	 sf::String & getTextFunct();
	

	
	void eraseTextonReturn();

	input_Box();
	~input_Box();
};

