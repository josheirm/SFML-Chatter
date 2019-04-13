#include "inputBox.h"
//#include <TGUI/Widgets/Button.hpp>





input_Box::input_Box()
{
	int a;
}

void input_Box::drawWindow(tgui::Gui& gui)
{
	auto picture = tgui::Picture::create("image.jpg");
	picture->setSize({ "100%", "100%" });
	gui.add(picture);


	auto inputText = tgui::TextBox::create();
	inputText->setSize({ "300", "100" });
	inputText->setPosition({ "16.67%", "16.67%" });
	//editBoxUsername->setDefaultText("Username");
	gui.add(inputText);
	//typdef std::shared_ptr<tgui::ChildWindow> tgui::ChildWindow::Ptr a; 
	
	
	
	auto button = button_.create("a");



	//static Button::Ptr tgui::Button::create
	//(
		
	//);

	//button->setRenderer(theme.getRenderer("Button"));
	button->setPosition(100, 200);
	button->setText("Send Text");
	button->setSize(100, 30);
	//button->connect("pressed", [=]() { child->setVisible(false); });
	//child->add(button);
	gui.add(button);


}

sf::String& input_Box::getTextFunct()
{
	//typedef std::shared_ptr< TextBox >Ptr;
	//const sf::String & a = 

	//typedef std::shared_ptr<tgui::TextBox >Ptr;

	sf::String  a = " ";
	return(a = Text_Box.getText());
	
	
}

void input_Box::eraseTextonReturn()
{
	sf::String text = "";
	void setText(const sf::String &text);
}

void checkifButtonPressed()
{

}


input_Box::~input_Box()
{
}
