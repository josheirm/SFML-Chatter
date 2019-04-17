#include "inputBox.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
//#include <TGUI/Widgets/Button.hpp>

//externed
//extern bool g_sendTexttoServerFlag;




input_Box::input_Box()
{
	g_sendTexttoServerFlag = false;
}

void input_Box::setisMessage(bool value)
{
	g_sendTexttoServerFlag = value;
}
bool input_Box::getisMessage()
{
	if (g_sendTexttoServerFlag)
	{
		return(true);
	}
	else
	{
		return(false);
	}
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
 
 const sf::String  input_Box::getTextFunct()
{
	 
	
	const sf::String& stringx = inputTextBox->getText();
	//sf::String string[1] = stringx ;
	
	return(stringx);

	
	
	
	
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
	//sf::String  tempstring = getTextFunct();
	//std::string s1 = tempstring;

	const sf::String   tempstring = getTextFunct();
	
	//eraseText();
	//sf::String::String(tempstring);


	chatBox.addTexttoChatBox(tempstring);
	//g_sendTexttoServerFlag;
	
	// addLine();
	
	return(1);
}