#include <TGUI/TGUI.hpp>
#include <iostream>
#include "inputBox.h"
#include "chatBox.h"
#include "client.h"
#include "listenorSendButtons.h"
#include "server.h"

//important determiner for running client or server code with same program


////////////////////
//externed
int IS_SERVER = 0;
//externed
bool g_isStarted = false;
//externed
bool g_sendTexttoServerFlag = false;
///////////////////

int gcounter = 1;
int g_clientReady = 0;
int g_serverReady = 0;

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
//client * clientobj = new client();
listenorSendButtons * listandReceiveButton = new listenorSendButtons();
server * listener_ =  new server();


int main(int argc, char * argv[]) {

//	if(argc == 2)
//	{
//		if (argv[1] == "client")
//		{
//			#undef isserver
//			#define isserver 0
//		}
//	}


	//char teststring[5];
	//strcpy_s(teststring, "gggg");
	//std::cout <<teststring;

	sf::RenderWindow window{ {700, 600}, "Window" };
	tgui::Gui gui{ window }; // Create the gui and attach it to the window

	input_Box().drawWindow(gui);
	input_Box().chat_Box.drawChatBox(gui);
	listenorSendButtons().drawtheButtons(gui);
	
	


	/*try
	{
		loadWidgets(gui);
	}
	catch (const tgui::Exception& e)
	{
		std::cerr << "Failed to load TGUI widgets: " << e.what() << std::endl;
		return 1;
	}*/



	listener_->clientofServer.getLocalAddress();
	//getLocalAddress();
		// Endless loop that waits for new connections
	//while (1)
	//{
		//sf::TcpSocket client;


		//listener_->clientofServer.getLocalAddress();

		

	//}

	while (window.isOpen())
	{

		window.clear();
		gui.draw(); // Draw all widgets
		window.display();


		/////////////

		//is client
		if (IS_SERVER == 0 && g_isStarted)
		{	//acer is client only need to change define
			int flag = -1;

			while (flag == -1)
			{
				flag = listener_->clientofServer.clientConnect();
				
			}
			g_clientReady = 1;

			g_isStarted = -1;
		}
		if (IS_SERVER == 1 && g_isStarted)
		{
			if (listener_->getServerListener().listen(53000) != sf::Socket::Done)
			{
				std::cout << "error1" << std::endl;
			}

			if (listener_->getServerListener().accept(listener_->clientofServer.socket) != sf::Socket::Done)
			{
				// error...
				std::cout << "error2" << std::endl;
			}
			g_isStarted = -1;
			g_serverReady = 1;
		}


		/////////////






		//////////////
		//receiveData()
		if (g_serverReady == true)
		{
			listener_->receiveData();// receiveData();
		}
		//////////////

		//client sends a test message
		//check extern value
		if (g_clientReady == true  && gcounter == 1 && g_sendTexttoServerFlag == true)
		{
			gcounter++;
			

			std::string tempstring = inputBox->getTextFunct();
			char datatosend[100];
			strncpy_s(datatosend, tempstring.c_str(), sizeof(datatosend));
			datatosend[sizeof(datatosend) - 1] = 0;
			/////
			
			//char datatest[5] = "test";
			//strcpy_s(datatest, "test\0");
			if (listener_->clientofServer.socket.send(datatosend, sizeof(datatosend)) != sf::Socket::Done)
				//clientsocket(datatest, 5) != sf::Socket::Done)
			{
				std::cout << "error - send" << std::endl;
			}

		}
			
		


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			gui.handleEvent(event); // Pass the event to the widgets
		}

		//int ispressed = inputBox.checkButtonPressed();




		//moved
		//window.clear();
		//gui.draw(); // Draw all widgets
		//window.display();
	}
}