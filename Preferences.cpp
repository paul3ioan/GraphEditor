#include "Preferences.h"
#include <vector>
#include "graphics.h"
#include "Interface_Constants.h"
#include "Translations.h"
#include <iostream>
#include "GeneralHelpers.h"
#include "ColorsPallete.h"
#include "Interface.h"

void Preference::closePopup(int main, int popup) {
	setactivepage(main);
	setcurrentwindow(main);
	closegraph(popup);
}
int Preference::changeInterface(int main, int popup, MainMenu::MainMenu& mainMenu, Graph& graph, OptionsButtons& optionButtons) {
	closePopup(main, popup);
	Interface::refreshInterface(mainMenu, graph);
	popup = initwindow(300, 400, translations.preferenceTitle, 450, 170);
	initInterface(optionButtons);
	drawInterface(optionButtons);
	return popup;
}
bool Preference::isButtonPressed(int x, int y, int x2, int y2, int xMouse, int yMouse) {
	return x <= xMouse && x2 >= xMouse && y <= yMouse && y2 >= yMouse;
}
int Preference::findButton(int x, int y, OptionsButtons optionsButtons)
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
Button::Button Preference::createButton(int y, char* label, bool isHovered = false) {
	Button::Button newButton;
	newButton.x = 30;
	newButton.y = y;
	newButton.isHovered = isHovered;
	strcpy(newButton.label, label);
	newButton.x2 = 270;
	newButton.y2 = y + textheight(label) + PADDING_TOP;
	return newButton;
}
void Preference::initInterface(OptionsButtons& optionButtons) {
	optionButtons.optionButton.clear();
	optionButtons.optionButton.push_back(createButton(40, translations.romanian));
	optionButtons.optionButton.push_back(createButton(80, translations.french));
	optionButtons.optionButton.push_back(createButton(120, translations.english));
	optionButtons.optionButton.push_back(createButton(200, translations.lightMode));
	optionButtons.optionButton.push_back(createButton(240, translations.darkMode));
	optionButtons.optionButton.push_back(createButton(350, translations.generalExit));
}
void Preference::drawInterface(OptionsButtons& optionButtons) {
	setfillstyle(SOLID_FILL, pallete.backgroundColor);
	bar(0, 0, 2000, 2000);
	showTitle();
	showModes();

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
void Preference::showTitle() {
	settextjustify(LEFT_TEXT, CENTER_TEXT);
	setcolor(pallete.additionalInfoColor);
	setbkcolor(pallete.backgroundColor);
	setfillstyle(SOLID_FILL, pallete.backgroundColor);
	outtextxy(20, 22, translations.languageLabel);
}
void Preference::changeButtonHovered(OptionsButtons& optionButtons, int index) {
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
void Preference::showModes() {
	settextjustify(LEFT_TEXT, CENTER_TEXT);
	setcolor(pallete.additionalInfoColor);
	setbkcolor(pallete.backgroundColor);
	setfillstyle(SOLID_FILL, pallete.backgroundColor);
	outtextxy(20, 180, translations.visualLabel);
}
void Preference::initPopup(MainMenu::MainMenu& mainMenu, Graph& graph) {
	int main = getcurrentwindow();
	OptionsButtons optionButtons;
	int popup = initwindow(300, 400, translations.preferenceTitle, 450, 170);
	initInterface(optionButtons);
	drawInterface(optionButtons);
	int x, y;

	while (true) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			int whichButton = findButton(x, y, optionButtons);
			switch (whichButton) {
			case romanian:
				Translations::changeTranslation(Translations::romanian, translations);
				popup = changeInterface(main, popup, mainMenu, graph, optionButtons);
				break;
			case english:
				Translations::changeTranslation(Translations::english, translations);
				popup = changeInterface(main, popup, mainMenu, graph, optionButtons);
				break;
			case french:
				Translations::changeTranslation(Translations::french, translations);
				popup = changeInterface(main, popup, mainMenu, graph, optionButtons);
				break;
			case darkmode:
				ColorsPallete::changeColorMode(ColorsPallete::darkMode, pallete);
				popup = changeInterface(main, popup, mainMenu, graph, optionButtons);
				break;
			case lightmode:
				ColorsPallete::changeColorMode(ColorsPallete::lightMode, pallete);
				popup = changeInterface(main, popup, mainMenu, graph, optionButtons);
				break;
			case exitt:
				closePopup(main, popup);
				return;
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

	return;
}
