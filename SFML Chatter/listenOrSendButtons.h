#pragma once
#include <TGUI/TGUI.hpp>

typedef std::shared_ptr<  tgui::Button >PtrButton;

//externed

class listenorSendButtons
{

	
public:
	listenorSendButtons();
	~listenorSendButtons();

	bool g_isListener;
	bool g_isStarted1;
	int IS_SERVER;
	
	
	
	PtrButton buttonStart;
	PtrButton buttonListen;
	//tgui::Button button_Listen;
	//tgui::Button button_Receive;
	
	
	void setListen();
	void drawtheButtons(tgui::Gui& gui);
	void alternateServer();
	int GETISSERVER();
	void setisServer(int value);
	bool getisStarted();
	int setisStarted(bool value);

private:	
	
};

