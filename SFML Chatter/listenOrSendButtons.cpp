
#include "listenOrSendButtons.h"


listenorSendButtons::listenorSendButtons()
{

	g_isListener = false;
	g_isStarted1 = false;
	IS_SERVER = 0;
	
}

listenorSendButtons::~listenorSendButtons()
{
}

void listenorSendButtons::setisServer(int value)
{
	IS_SERVER = value;
}

void listenorSendButtons::drawtheButtons(tgui::Gui& gui)
{
	
	

	buttonListen = tgui::Button::create();
	buttonListen->setPosition(280, 50);
	buttonListen->setText("You're the Client");
	buttonListen->setSize(150, 30);
	buttonListen->connect("pressed", [=]() { setListen(); });
	
	gui.add(buttonListen);

	
	buttonStart = tgui::Button::create();

	
	buttonStart->setPosition(480, 50);
	buttonStart->setText("Stopped");
	buttonStart->setSize(100, 30);
	buttonStart->connect("pressed", [=]() { setisStarted(true); });

	
	
	gui.add(buttonStart);

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
int listenorSendButtons::setisStarted(bool value)
{
	if (g_isStarted1 == 0)
	{
		buttonStart->setText("Started");
		g_isStarted1 = true;
		
	}
	else
	{
		buttonStart->setText("Stopped");
		g_isStarted1 = false;
	}
		return(1);

}

bool listenorSendButtons::getisStarted()
{
	return(g_isStarted1);
		
}

void listenorSendButtons::alternateServer()
{
	if(IS_SERVER == 1)
	{
		IS_SERVER = 0;
	}
	else
	{
		IS_SERVER = 1;
	}
}
int listenorSendButtons::GETISSERVER()
{
	return(IS_SERVER);

}

