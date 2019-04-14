#pragma once
#include <TGUI/TGUI.hpp>
typedef std::shared_ptr< tgui::Button >ConstPtrButton;

class listenorSendButtons
{
public:
	bool g_isListener;
	ConstPtrButton buttonReceive;
	ConstPtrButton buttonListen;
	tgui::Button button_Listen;
	tgui::Button button_Receive;
	void setListen();
	void drawtheButtons(tgui::Gui& gui);

	listenorSendButtons();
	~listenorSendButtons();
};

