#pragma once
#include <vector>
#include "Button.h"
namespace MainMenu
{	
	struct MainMenu {
		std::vector<Button::Button> mainMenuList;
		std::vector<Button::Button> topMenuList;
	};
	void initInterface(MainMenu&);
	void resetAllButtons(MainMenu&);
	void resetSideButtons(MainMenu&);

};

