#pragma once
#include <TGUI/TGUI.hpp>
typedef std::shared_ptr< tgui::Button >ConstPtrButton;
extern int IS_SERVER;


class listenorSendButtons
{
public:
	void setStart();
	bool g_isStarted;
	bool g_isListener;
	ConstPtrButton buttonStart;
	ConstPtrButton buttonListen;
	tgui::Button button_Listen;
	tgui::Button button_Receive;
	void setListen();
	void drawtheButtons(tgui::Gui& gui);

	listenorSendButtons();
	~listenorSendButtons();
};

