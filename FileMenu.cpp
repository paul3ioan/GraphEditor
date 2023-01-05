#include "FileMenu.h"
#include "ErrorPopup.h"
#include <vector>
#include "graphics.h"
#include <iostream>
#include "Graph.h"
#include "GraphHelpers.h"
#include "Interface_Constants.h"
#include "FileServices.h"
#include "Translations.h"
#include "ColorsPallete.h"
#include "GeneralHelpers.h"

void FileMenu::closePopup(int main, int popup) {
	setactivepage(main);
	setcurrentwindow(main);
	closegraph(popup);
}
bool FileMenu::isButtonPressed(int x, int y, int x2, int y2, int xMouse, int yMouse) {
	return x <= xMouse && x2 >= xMouse && y <= yMouse && y2 >= yMouse;
}
int FileMenu::findButton(int x, int y, OptionsButtons optionsButtons)
{
	int index = 0;
	for (auto i : optionsButtons.optionButton)
	{
		if (isButtonPressed(i.x, i.y, i.x2, i.y2, x, y))
			return index;
		index++;
	}
	return -1;
}
Button::Button FileMenu::createButton(int y, char* label, bool isHovered = false) {
	Button::Button newButton;
	newButton.x = 30;
	newButton.y = y;
	newButton.isHovered = isHovered;
	strcpy(newButton.label, label);
	newButton.x2 = 270;
	newButton.y2 = y + textheight(label) + PADDING_TOP;
	return newButton;
}
void FileMenu::initInterface(OptionsButtons& optionButtons) {
	optionButtons.optionButton.push_back(createButton(30, translations.fileSave));
	optionButtons.optionButton.push_back(createButton(60, translations.fileLoadGraph));
	optionButtons.optionButton.push_back(createButton(90, translations.fileLoadPreferences));
	optionButtons.optionButton.push_back(createButton(120, translations.fileLoadAll));
	optionButtons.optionButton.push_back(createButton(200, translations.generalExit));
}
void FileMenu::changeButtonHovered(OptionsButtons& optionButtons, int index, bool isInputActive = false) {
	for (auto i : optionButtons.optionButton) {
		if (i.isHovered) {
			i.isHovered = false;
			if (strcmp(i.label, translations.generalExit) == 0) {
				setfillstyle(SOLID_FILL, pallete.exitBackgroundColor);
				setcolor(pallete.exitTextColor);
				setbkcolor(pallete.exitBackgroundColor);
				settextjustify(CENTER_TEXT, CENTER_TEXT);
			}
			else {
				setfillstyle(SOLID_FILL, pallete.buttonBackgroundColor);
				setcolor(pallete.buttonLabelColor);
				setbkcolor(pallete.buttonBackgroundColor);
				settextjustify(CENTER_TEXT, CENTER_TEXT);
			}
			bar(i.x, i.y, i.x2, i.y2);
			outtextxy((i.x + i.x2) / 2, (i.y + i.y2) / 2 + 4, i.label);
		}
	}
	if (index == -1) {
		return;
	}
	auto i = optionButtons.optionButton[index];
	optionButtons.optionButton[index].isHovered = true;
	if (index == exitt) {
		setfillstyle(SOLID_FILL, pallete.exitBackgroundColor);
		setcolor(pallete.exitTextColor);
		setbkcolor(pallete.exitBackgroundColor);
	}
	else {
		setfillstyle(SOLID_FILL, pallete.buttonBackgroundHoverColor);
		setcolor(pallete.buttonLabelHoverColor);
		setbkcolor(pallete.buttonBackgroundHoverColor);
	}
	bar(i.x, i.y, i.x2, i.y2);
	outtextxy((i.x + i.x2) / 2, (i.y + i.y2) / 2 + 4, i.label);
}
void FileMenu::drawInterface(OptionsButtons& optionButtons, bool isInputActive = false) {
	for (auto i : optionButtons.optionButton) {
		if (i.isHovered) {
			setfillstyle(SOLID_FILL, pallete.buttonBackgroundHoverColor);
			setcolor(pallete.buttonLabelHoverColor);
			setbkcolor(pallete.buttonBackgroundHoverColor);
		}
		else {
			setfillstyle(SOLID_FILL, pallete.buttonBackgroundColor);
			setcolor(pallete.buttonLabelColor);
			setbkcolor(pallete.buttonBackgroundColor);
		}
		settextjustify(CENTER_TEXT, CENTER_TEXT);
		bar(i.x, i.y, i.x2, i.y2);
		outtextxy((i.x + i.x2) / 2, (i.y + i.y2) / 2 + 4, i.label);
	}
	auto exitButton = optionButtons.optionButton[optionButtons.optionButton.size() - 1];
	setfillstyle(SOLID_FILL, pallete.exitBackgroundColor);
	setbkcolor(pallete.exitBackgroundColor);
	setcolor(pallete.exitTextColor);
	bar(exitButton.x, exitButton.y, exitButton.x2, exitButton.y2);
	outtextxy((exitButton.x + exitButton.x2) / 2, (exitButton.y + exitButton.y2) / 2 + 4, exitButton.label);
}

int FileMenu::initPopup(Graph& graph) {
	int main = getcurrentwindow();
	OptionsButtons optionButtons;
	int popup = initwindow(300, 500, translations.fileTitle, 450, 170);
	initInterface(optionButtons);
	setfillstyle(SOLID_FILL, pallete.backgroundColor);
	bar(0, 0, 2000, 2000);
	drawInterface(optionButtons);
	int x, y;

	while (true) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			int whichButton = findButton(x, y, optionButtons);
			switch (whichButton) {
			case save:
				FileServices::saveData(graph);
				closePopup(main, popup);
				return 1;
			case loadGraph:
				FileServices::loadGraph(graph);
				closePopup(main, popup);
				return 1;
			case loadPreferences:
				FileServices::loadPreferences();
				closePopup(main, popup);
				return 1;
			case loadAll:
				FileServices::configureData(graph);
				closePopup(main, popup);
				return 1;
			case exitt:
				closePopup(main, popup);
				return 1;
			default:
				break;
			}
		}
		else
			if (ismouseclick(WM_MOUSEMOVE))
			{
				getmouseclick(WM_MOUSEMOVE, x, y);
				int whichButton = findButton(x, y, optionButtons);
				changeButtonHovered(optionButtons, whichButton);
			}
	}

	return 1;
}
