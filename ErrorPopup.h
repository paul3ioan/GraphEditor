#pragma once
#include <vector>
#include "graphics.h"
#include "Translations.h"
#include "GeneralHelpers.h"
#include "ColorsPallete.h"
#include "Interface.h"
#include "Interface_Constants.h"

namespace ErrorPopup {
	enum Options {
		exitt
	};
	struct ErrorButtons {
		std::vector<Button::Button> optionButton;
	};
	void errorClosePopup(int main, int popup);
	void errorShowMsg(char* msg);
	bool errorIsButtonPressed(int x, int y, int x2, int y2, int xMouse, int yMouse);
	void errorShowTitle(char* title);
	int errorFindButton(int x, int y, ErrorButtons optionsButtons);
	Button::Button errorCreateButton(int y, char* label, bool isHovered);
	void errorInitInterface(ErrorButtons& optionButtons);
	void errorDrawInterface(ErrorButtons& optionButtons, char* title, char* msg);
	void errorChangeButtonHovered(ErrorButtons& optionButtons, int index);
	void errorInitPopup(char* title, char* msg);
}