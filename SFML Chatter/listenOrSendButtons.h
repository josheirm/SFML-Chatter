#pragma once
#include <TGUI/TGUI.hpp>
typedef std::shared_ptr< tgui::Button >ConstPtrButton;

//externed

class listenorSendButtons
{
public:
	bool g_isStarted;
	int IS_SERVER;
	ConstPtrButton buttonStart;
	ConstPtrButton buttonListen;
	tgui::Button button_Listen;
	tgui::Button button_Receive;
	listenorSendButtons();
	~listenorSendButtons();
	
	bool g_isListener;
	void setListen();
	void drawtheButtons(tgui::Gui& gui);
	void alternateServer();
	int GETISSERVER();
	bool getisStarted();
	void setisStarted(bool value);
	
	
};

