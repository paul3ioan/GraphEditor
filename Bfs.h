#pragma once
#include "Button.h"
#include "Graph.h"
namespace Bfs
{
	struct OptionsButtons {
		std::vector<Button::Button> optionButton;
	};
	enum Options {
		retry,
		exitt,
	};
	int initPopup(Graph&);
	void startBfs(Graph&);
	void highlightEdge(Graph&, std::pair<int, int>);
	int findButton(int x, int y, OptionsButtons optionsButtons);
	void closePopup(int, int);
	bool isButtonPressed(int x, int y, int x2, int y2, int xMouse, int yMouse);
	void drawInterface(OptionsButtons& optionButtons, bool isInputActive);
	void initInterface(OptionsButtons& optionButtons);
	Button::Button createButton(int y, char* label, bool isHovered);
	void changeButtonHovered(OptionsButtons& optionButtons, int index, bool isInputActive);
};

