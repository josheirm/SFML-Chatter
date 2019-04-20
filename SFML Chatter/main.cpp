#include <TGUI/TGUI.hpp>
#include <iostream>
#include "inputBox.h"
#include "chatBox.h"
#include "client.h"
#include "listenorSendButtons.h"
#include "server.h"
#include <SFML/System/String.hpp>
#include <SFML/Network/Packet.hpp>
//important determiner for running client or server code with same program


////////////////////
//externed


//externed
//bool g_sendTexttoServerFlag = false;
///////////////////



//chat_Box * chatBox = new chat_Box();
input_Box * inputBox = new input_Box;
//client * clientobj = new client();
server * listener_ =  new server;



int main(int argc, char * argv[]) {

	listener_->copyInputBox(*inputBox);

	int gcounter = 1;
	int g_clientReady = 0;
	int g_serverReady = 0;

	listenorSendButtons One;
	listenorSendButtons * listandReceiveButton;
	listandReceiveButton = &One;
	
	//listenorSendButtons * listandReceiveButton = new listenorSendButtons();



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

	inputBox->drawWindow(gui);
	inputBox->chatBox.drawChatBox(gui);
	listandReceiveButton->drawtheButtons(gui);
	


	/*try
	{
		loadWidgets(gui);
	}
	catch (const tgui::Exception& e)
	{
		std::cerr << "Failed to load TGUI widgets: " << e.what() << std::endl;
		return 1;
	}*/



	///listener_->clientofServer.getLocalAddress();
	
	
	//getLocalAddress();
		// Endless loop that waits for new connections
	//while (1)
	//{
		//sf::TcpSocket client;


		//listener_->clientofServer.getLocalAddress();

		

	//}

	while (window.isOpen())
	{

		

		
		//const sf::String & tempString = (inputBox->getTextFunct());

		/////////////
		int value2= (listandReceiveButton->getisStarted());// g_isStarted1;
		
		//is client - connecting
		if ((listandReceiveButton->GETISSERVER() == 0)  && ((listandReceiveButton->getisStarted()) == true))
		{	//acer is client only need to change define
			int flag = 0;

			while (flag == 0)
			{
				flag = listener_->clientofServer.clientConnect();
				
			}
			g_clientReady = 1;

			//turns off
			listandReceiveButton->setisStarted(false);
		}
		
		
		//is server listening
		if (listandReceiveButton->GETISSERVER() == 1 && listandReceiveButton->getisStarted() == true)
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
			listandReceiveButton->setisStarted(false);
			g_serverReady = 1;
		}


		/////////////




		

		//////////////
		//server receives
		if (g_serverReady  && (listandReceiveButton->GETISSERVER() == 1))
		{
			listener_->clientofServer.socket.setBlocking(false);
			listener_->receiveData();
				
				
			
		}
		//////////////


		//client sends a test message
		
		if (inputBox->g_sendTexttoServerFlag && g_clientReady   && (listandReceiveButton->GETISSERVER() == 0))
		{
			listener_->clientofServer.socket.setBlocking(false);

			
			
			sf::Packet packet;

			const sf::String & tempString  = (inputBox->getTextFunct());
			//tempString = "hi";
										//tempString->insert("A");

			packet << tempString;
			
			// do stuff
			//delete[] cstr;
			/////////
				
			
			//USE PACKETS HERE!!!!



			
			//if (listener_->clientofServer.socket.send(tempstring, sizeof(tempstring)) != sf::Socket::Done)
			listener_->clientofServer.socket.send(packet);
			inputBox->g_sendTexttoServerFlag = false;

		}
		



		//////////////////////
		//////////////////////client receive
		if (g_clientReady && (listandReceiveButton->GETISSERVER() == 0))
		{
			listener_->clientofServer.socket.setBlocking(false);
			listener_->receiveData();



		}

		///////////////////////
		///////////////////////server sends

		if (inputBox->g_sendTexttoServerFlag && g_serverReady  && (listandReceiveButton->GETISSERVER() == 1))
		{
			//gcounter++;
			listener_->clientofServer.socket.setBlocking(false);
			sf::Packet packet;

			const sf::String & tempString = (inputBox->getTextFunct());
			//tempString = "hi";
										//tempString->insert("A");

			packet << tempString;

			// do stuff
			//delete[] cstr;
			/////////


			//USE PACKETS HERE!!!!




			//if (listener_->clientofServer.socket.send(tempstring, sizeof(tempstring)) != sf::Socket::Done)
			listener_->clientofServer.socket.send(packet);
			inputBox->g_sendTexttoServerFlag = false;

		}


		///////////////////////
		///////////////////////



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


		//moved
		//window.clear();
		//gui.draw(); // Draw all widgets
		//window.display();
	}
}