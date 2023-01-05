#include "ErrorPopup.h"
#include "AddNodeInterface.h"
#include <vector>
#include "graphics.h"
#include <iostream>
#include "Interface_Constants.h"
#include "Translations.h"
#include "ColorsPallete.h"
#include "GeneralHelpers.h"

void AddNodeInterface::closePopup(int main, int popup) {
	setactivepage(main);
	setcurrentwindow(main);
	closegraph(popup);
}
bool AddNodeInterface::isButtonPressed(int x, int y, int x2, int y2, int xMouse, int yMouse) {
	return x <= xMouse && x2 >= xMouse && y <= yMouse && y2 >= yMouse;
}
int AddNodeInterface::findButton(int x, int y, OptionsButtons optionsButtons)
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
Button::Button AddNodeInterface::createButton(int y, char* label, bool isHovered=false) {
	Button::Button newButton;
	newButton.x = 30;
	newButton.y = y;
	newButton.isHovered = isHovered;
	strcpy(newButton.label, label);
	newButton.x2 = 270;
	newButton.y2 = y + textheight(label) + PADDING_TOP;
	return newButton;
}
void AddNodeInterface::initInterface(OptionsButtons& optionButtons) {
	optionButtons.optionButton.push_back(createButton(30, translations.addNodeAutoButton));
	optionButtons.optionButton.push_back(createButton(70, translations.addNodeInputButton));
	optionButtons.optionButton.push_back(createButton(450, translations.generalExit));
}
void AddNodeInterface::changeButtonHovered(OptionsButtons& optionButtons, int index, bool isInputActive=false) {
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
void AddNodeInterface::drawInterface(OptionsButtons& optionButtons, bool isInputActive = false) {
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
void AddNodeInterface::showInputField() {
	setbkcolor(pallete.backgroundColor);
	settextjustify(LEFT_TEXT, CENTER_TEXT);
	outtextxy(20, 200,translations.addNodeInputLabel);
}
void AddNodeInterface::handleInput( int & number) {
	showInputField();
	number = 0;
	while (true) {
		char ch = getch();
		if (ch < '0' || ch > '9') {
			showError("");
			if (ch == '\x1b') {
				number = -1;
				showError("");
				setfillstyle(SOLID_FILL, pallete.backgroundColor);
				bar(0, 180, 1000, 220);
				bar(0, 230, 400, 260);
				return;
			}
			if (ch == '\b') { // check if backspace is presed
				number /= 10;
				if (number == 0) number = 1;
			}
			else if (ch == '\r') { // enter is pressed
				showError("");
				setfillstyle(SOLID_FILL, pallete.backgroundColor);
				bar(0, 180, 1000, 220);
				bar(0, 230, 400, 260);
				return;
			}
			else {
				showError(translations.addNodeInputError);
				continue;
			}
		}
		else {
			number = number * 10 + (ch - '0');
			if (number > 100) {
				number /= 10;
				showError(translations.addNodeInputError);
				continue;
			}
		}
		char msg[100];
		strcpy(msg, GeneralHelpers::fromIntToCharArray(number));
		setfillstyle(SOLID_FILL, pallete.backgroundColor);
		bar(0, 230, 400, 260);
		setcolor(pallete.buttonBackgroundColor);
		outtextxy(80, 250, msg);
	}
}
void AddNodeInterface::showError(char* msg) {
	if (strlen(msg) == 0)
	{
		setfillstyle(SOLID_FILL, pallete.backgroundColor);
		bar(0, 280, 1000, 340);
		return;
	}
	setbkcolor(pallete.backgroundColor);
	setcolor(pallete.errorTitleColor);
	outtextxy(10, 300, msg);
}

int AddNodeInterface::initPopup(Graph& graph) {
	int main = getcurrentwindow();
	OptionsButtons optionButtons;
	int popup = initwindow(300, 500, translations.addNodeTitle, 450, 170);
	initInterface(optionButtons);
	setfillstyle(SOLID_FILL, pallete.backgroundColor);
	bar(0, 0, 2000, 2000);
	drawInterface(optionButtons);
	int x, y;
	int number = 0;

	while (true) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			int whichButton = findButton(x, y, optionButtons);
			switch (whichButton) {
			case addAuto:
				for (int i = 1; i < 100; i++) {
					if (!graph.availableNode[i]) {
						closePopup(main, popup);
						return i;
					}
				}
			case addInput:
				handleInput(number);
				if (number >= 1 && number <= 100) {
					if (!graph.availableNode[number]) {
						graph.availableNode[number] = 1;
						closePopup(main, popup);
						return number;
					}
					else {
						ErrorPopup::errorInitPopup(translations.inputTitleError, translations.addNodeNodeInList);
					}
				}
				break;
			case exitt:
				closePopup(main, popup);
				return -1;
			default:
				break;
			}
		} else
		if (ismouseclick(WM_MOUSEMOVE))
		{
			getmouseclick(WM_MOUSEMOVE, x, y);
			int whichButton = findButton(x, y, optionButtons);
			changeButtonHovered(optionButtons, whichButton);
		}
	}
	getch();
	
	return 1;
}
