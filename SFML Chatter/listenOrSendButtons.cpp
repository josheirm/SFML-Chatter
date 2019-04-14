#include "listenOrSendButtons.h"




void listenorSendButtons::drawtheButtons(tgui::Gui& gui)
{
	buttonListen = button_Listen.create("a");

	//button->setRenderer(theme.getRenderer("Button"));
	buttonListen->setPosition(280, 50);
	buttonListen->setText("You're Listening");
	buttonListen->setSize(150, 30);
	buttonListen->connect("pressed", [=]() { setListen(); });
	//child->add(button);
	gui.add(buttonListen);

	//buttonReceive = button_Receive.create("a");

	////button->setRenderer(theme.getRenderer("Button"));
	//buttonReceive->setPosition(100, 200);
	//buttonReceive->setText("Listener");
	//buttonReceive->setSize(100, 30);
	//buttonReceive->connect("pressed", [=]() { setReceive(); });
	//
	////child->add(button);
	//gui.add(buttonReceive);

}

listenorSendButtons::listenorSendButtons()
{
	g_isListener = true;
}


listenorSendButtons::~listenorSendButtons()
{
}

void listenorSendButtons::setListen()
{
	if (g_isListener)
	{
		buttonListen->setText("You're Recieving");
		g_isListener = false;
	}
	//starts as listening
	else
	{
		buttonListen->setText("You're Listening");
		g_isListener = true;
	}
}
//listenOrSendButtons::setReceive()
//{
//	buttonReceive->setEnabled(false);
//
//}