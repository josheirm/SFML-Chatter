#include "inputBox.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
//#include <TGUI/Widgets/Button.hpp>





input_Box::input_Box()
{
	
}

void input_Box::drawWindow(tgui::Gui& gui)
{
	auto picture = tgui::Picture::create("image.jpg");
	picture->setSize({ "100%", "100%" });
	gui.add(picture);


	inputTextBox = text_Box.create();
	inputTextBox->setSize({ "500", "100" });
	inputTextBox->setPosition({ "100", "100" });
	//editBoxUsername->setDefaultText("Username");
	//inputTextBox->setText("a");
	gui.add(inputTextBox);
	//typdef std::shared_ptr<tgui::ChildWindow> tgui::ChildWindow::Ptr a; 
	
	
	
	auto button = button_.create("a");



	//static Button::Ptr tgui::Button::create
	//(
		
	//);

	//button->setRenderer(theme.getRenderer("Button"));
	button->setPosition(100, 200);
	button->setText("Send Text");
	button->setSize(100, 30);
	button->connect("pressed", [=]() { buttonPressed(); });
	//child->add(button);
	gui.add(button);


}

const sf::String input_Box::getTextFunct()
{
	//typedef std::shared_ptr< TextBox >Ptr;
	//const sf::String & a = 

	//typedef std::shared_ptr<tgui::TextBox >Ptr;
	//const sf::String a = " ";
	//sf::String & a;
	const sf::String a = inputTextBox->getText();
	std::string s1 = a;
	//window.draw(a);
	return(a);

	
	
}

//void input_Box::eraseText()
//{
//	sf::String text = "";
//	void setText(const sf::String &text);
//}

void input_Box::eraseText()
{
	sf::String text1 = "";
	inputTextBox->setText(text1);
	
}


input_Box::~input_Box()
{
}

int input_Box::buttonPressed()
{
	const sf::String  tempstring = getTextFunct();
	std::string s1 = tempstring;
	eraseText();
	chat_Box.addTexttoChatBox(tempstring);// addLine();
	
	return(1);
}