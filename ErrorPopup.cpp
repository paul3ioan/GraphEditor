#include "ErrorPopup.h"
void ErrorPopup::errorClosePopup(int main, int popup) {
	setactivepage(main);
	setcurrentwindow(main);
	closegraph(popup);
}
void ErrorPopup::errorShowMsg(char* msg) {
	settextjustify(LEFT_TEXT, CENTER_TEXT);
	setcolor(pallete.errorMessageColor);
	setbkcolor(pallete.backgroundColor);
	setfillstyle(SOLID_FILL, pallete.backgroundColor);
	for (int i = 0; i < strlen(msg); i += 26) {
		char aux[30];
		strncpy(aux, msg + i, 26);
		aux[26] = '\0';
		int y = 36;
		if (i == 0)
			y = 50;
		outtextxy(20, y * (i / 26 + 1), aux);
	}
}
bool  ErrorPopup::errorIsButtonPressed(int x, int y, int x2, int y2, int xMouse, int yMouse) {
	return x <= xMouse && x2 >= xMouse && y <= yMouse && y2 >= yMouse;
}
void ErrorPopup::errorShowTitle(char* title) {
	settextjustify(LEFT_TEXT, CENTER_TEXT);
	setcolor(pallete.errorTitleColor);
	setbkcolor(pallete.backgroundColor);
	setfillstyle(SOLID_FILL, pallete.backgroundColor);
	outtextxy(170 - textwidth(title), 22, title);
}
int  ErrorPopup::errorFindButton(int x, int y,ErrorButtons optionsButtons)
{
	int index = 0;
	for (auto i : optionsButtons.optionButton)
	{
		if (errorIsButtonPressed(i.x, i.y, i.x2, i.y2, x, y))
			return index;
		index++;
	}
	return -1;
}
Button::Button ErrorPopup::errorCreateButton(int y, char* label, bool isHovered = false) {
	Button::Button newButton;
	newButton.x = 30;
	newButton.y = y;
	newButton.isHovered = isHovered;
	strcpy(newButton.label, label);
	newButton.x2 = 270;
	newButton.y2 = y + textheight(label) + PADDING_TOP;
	return newButton;
}
void ErrorPopup::errorInitInterface(ErrorButtons& optionButtons) {
	optionButtons.optionButton.clear();
	optionButtons.optionButton.push_back(errorCreateButton(120, translations.generalExit));
}
void ErrorPopup::errorDrawInterface(ErrorButtons& optionButtons, char* title, char* msg) {
	setfillstyle(SOLID_FILL, pallete.backgroundColor);
	bar(0, 0, 2000, 2000);
	errorShowTitle(title);
	errorShowMsg(msg);

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
void ErrorPopup::errorChangeButtonHovered(ErrorButtons& optionButtons, int index) {
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
void ErrorPopup::errorInitPopup(char* title, char* msg) {
	int main = getcurrentwindow();
	ErrorButtons optionButtons;
	int popup = initwindow(300, 200, "Error", 450, 170);
	errorInitInterface(optionButtons);
	errorDrawInterface(optionButtons, title, msg);
	int x, y;

	while (true) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			int whichButton = errorFindButton(x, y, optionButtons);
			switch (whichButton) {
			case exitt:
				errorClosePopup(main, popup);
				return;
			default:
				break;
			}
		}
		else
			if (ismouseclick(WM_MOUSEMOVE))
			{
				getmouseclick(WM_MOUSEMOVE, x, y);
				int whichButton = errorFindButton(x, y, optionButtons);
				errorChangeButtonHovered(optionButtons, whichButton);
			}
	}
	getch();

	return;
}