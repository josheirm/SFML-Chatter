#include <TGUI/TGUI.hpp>
#include <iostream>
#include "inputBox.h"
#include "chatBox.h"

void loadWidgets(tgui::Gui& gui)
{
	//tgui::Button::Ptr button = tgui::Button::create();

	//gui.add(button);

	

	//auto picture = tgui::Picture::create("image.jpg");
	//picture->setSize({ "100%", "100%" });
	//gui.add(picture);



	auto editBoxUsername = tgui::TextBox::create();
	editBoxUsername->setSize({ "200", "200" });
	editBoxUsername->setPosition({ "16.67%", "16.67%" });
	//editBoxUsername->setDefaultText("Username");
	gui.add(editBoxUsername);
}

//chat_Box * chatBox = new chat_Box();
input_Box * inputBox = new input_Box();


int main()
{
	sf::RenderWindow window{ {700, 600}, "Window" };
	tgui::Gui gui{ window }; // Create the gui and attach it to the window

	input_Box().drawWindow(gui);
	input_Box().chat_Box.drawChatBox(gui);
	
	
	


	/*try
	{
		loadWidgets(gui);
	}
	catch (const tgui::Exception& e)
	{
		std::cerr << "Failed to load TGUI widgets: " << e.what() << std::endl;
		return 1;
	}*/




	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			gui.handleEvent(event); // Pass the event to the widgets
		}

		//int ispressed = inputBox.checkButtonPressed();





		window.clear();
		gui.draw(); // Draw all widgets
		window.display();
	}
}