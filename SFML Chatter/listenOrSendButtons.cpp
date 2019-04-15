#include "listenOrSendButtons.h"
//externed




void listenorSendButtons::drawtheButtons(tgui::Gui& gui)
{
	
	buttonListen = button_Listen.create("a");

	//button->setRenderer(theme.getRenderer("Button"));
	buttonListen->setPosition(280, 50);
	buttonListen->setText("You're the Client");
	buttonListen->setSize(150, 30);
	buttonListen->connect("pressed", [=]() { setListen(); });
	//child->add(button);
	gui.add(buttonListen);

	
	buttonStart = button_Receive.create("a");

	//button->setRenderer(theme.getRenderer("Button"));
	buttonStart->setPosition(480, 50);
	buttonStart->setText("Stopped");
	buttonStart->setSize(100, 30);
	buttonStart->connect("pressed", [=]() { setStart(); });
	//
	////child->add(button);
	gui.add(buttonStart);

}

listenorSendButtons::listenorSendButtons()
{
	
	g_isListener = false;
	g_isStarted = false;
}


listenorSendButtons::~listenorSendButtons()
{
}

void listenorSendButtons::setListen()
{
	//starts as the server  (true)
	if (g_isListener)
	{
		buttonListen->setText("You're the Client");
		g_isListener = false;
		IS_SERVER = 0;

	}
	//starts as listening
	else
	{
		buttonListen->setText("You're the Server");
		g_isListener = true;
		IS_SERVER = 1;

	}
}
void listenorSendButtons::setStart()
{
	if (g_isStarted == true)
	{
		buttonStart->setText("Stopped");
		g_isStarted = false;
	}else
	{
		buttonStart->setText("Started");
		g_isStarted = true;
	}

	

}