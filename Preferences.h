#pragma once
#include "Button.h"
#include "MainMenu.h"
#include "Graph.h"

namespace Preference {

	struct OptionsButtons {
		std::vector<Button::Button> optionButton;
	};
	enum Options {
		romanian,
		french,
		english,
		lightmode,
		darkmode,
		exitt
	};
	void initPopup(MainMenu::MainMenu& mainMenu, Graph& graph);
	int findButton(int x, int y, OptionsButtons optionsButtons);
	void showTitle();
	void closePopup(int, int);
	int changeInterface(int main, int popup, MainMenu::MainMenu& mainMenu, Graph& graph, OptionsButtons&);
	bool isButtonPressed(int x, int y, int x2, int y2, int xMouse, int yMouse);
	void drawInterface(OptionsButtons& optionButtons);
	void showModes();
	void initInterface(OptionsButtons& optionButtons);
	Button::Button createButton(int y, char* label, bool isHovered);
	void changeButtonHovered(OptionsButtons& optionButtons, int index);
};