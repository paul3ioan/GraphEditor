#include "Button.h"
#include "GraphHelpers.h"
#include <iostream>
#include "Interface_Constants.h"
#include "ColorsPallete.h"

void Button::showSimpleButton(Button& button) {
	setusercharsize(1, 2, 1, 2);
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, USER_CHAR_SIZE);
	setlinestyle(SOLID_LINE, 1, NORM_WIDTH);
	setfillstyle(SOLID_FILL, pallete.buttonBackgroundColor);
	setbkcolor(pallete.buttonBackgroundColor);
	setcolor(pallete.buttonLabelColor);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	bar(button.x, button.y, button.x + textwidth(button.label) + PADDING_LEFT, button.y + PADDING_TOP + textheight(button.label));
	outtextxy((button.x + button.x2) / 2, (button.y + button.y2) / 2 + 4, button.label);
}
void isSelected(bool isSelected, bool isHover) {
	if (isSelected) {
		setfillstyle(SOLID_LINE, pallete.sideMenuActiveBackgroundColor);
		setcolor(pallete.sideMenuActiveLabelColor);
	}
	else if(isHover) {
		setfillstyle(SOLID_LINE, pallete.sideMenuHoverBackgroundColor);
		setcolor(pallete.sideMenuHoverLabelColor);
	}
	else {
	setfillstyle(SOLID_LINE, pallete.sideMenuBackgroundColor);
	setcolor(pallete.sideMenuLabelColor);

	}
}
int getAccentColor(Button::Button& button) {
	if (button.isSelected) {
		setcolor(pallete.sideMenuActiveLabelColor);
		setfillstyle(SOLID_FILL, pallete.sideMenuActiveLabelColor);
		return pallete.sideMenuActiveLabelColor;
	}
	if (button.isHovered) {
		setcolor(pallete.sideMenuHoverLabelColor);
		setfillstyle(SOLID_FILL,pallete.sideMenuHoverLabelColor);
		return pallete.sideMenuHoverLabelColor;
	}
	setcolor(pallete.sideMenuLabelColor);
	setfillstyle(SOLID_FILL, pallete.sideMenuLabelColor);
	return pallete.sideMenuLabelColor;
}
void getBackgroundColor(Button::Button& button) {
	if (button.isSelected) {
		setcolor(pallete.sideMenuActiveBackgroundColor);
		setfillstyle(SOLID_FILL, pallete.sideMenuActiveBackgroundColor);
		return;
	}
	if (button.isHovered) {
		setcolor(pallete.sideMenuHoverBackgroundColor);
		setfillstyle(SOLID_FILL, pallete.sideMenuHoverBackgroundColor);
		return;
	}
	setcolor(pallete.sideMenuBackgroundColor);
	setfillstyle(SOLID_FILL, pallete.sideMenuBackgroundColor);
}
void Button::drawButton(Button& button) {
	switch (button.type) {
	case addEdge:
		setlinestyle(SOLID_LINE, 1, 2);
		getBackgroundColor(button);
		bar(50,100, 112, 150);
		getAccentColor(button);
		line(60, 140, 100, 110);
		GraphHelpers::drawTriangle(102, 108, 109, 102, getAccentColor(button));
		break;
	case addNode:
		setlinestyle(SOLID_LINE, 1, 2);
		getBackgroundColor(button);
		bar(50, 200, 112, 250);
		getAccentColor(button);
		circle(81, 225, 20);
		bar(81, 209, 83, 240);
		bar(67, 223, 95, 225);
		break;
		case prettier:
			getBackgroundColor(button);
			bar(50, 300, 112, 350);
			break;
		case orientation:
			getBackgroundColor(button);
			bar(50, 400, 112, 450);
			break;
		case deleteGraph:
			setlinestyle(SOLID_LINE, 1, 2);
			getBackgroundColor(button);
			bar(50, 500, 112, 550);
			getAccentColor(button);
			circle(81, 525, 20);
			line(72, 535, 91, 515);
			line(72, 515, 91, 535);
			break;
	default:
		showSimpleButton(button);
		break;
	}

}