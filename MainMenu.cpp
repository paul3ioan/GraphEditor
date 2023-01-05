#include "MainMenu.h"
#include "Interface_Constants.h"
#include "Translations.h"
#include "ColorsPallete.h"

void MainMenu::initInterface(MainMenu& mainMenu) {
	mainMenu.topMenuList.clear();
	setusercharsize(1, 2, 1, 2);
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, USER_CHAR_SIZE);

	mainMenu.mainMenuList.clear();
	Button::Button newEdgeButton;
	newEdgeButton.isSelected = false;
	newEdgeButton.type = Button::addEdge;
	newEdgeButton.x = 50;
	newEdgeButton.x2 = 112;
	newEdgeButton.y = 100;
	newEdgeButton.y2 = 150;

	Button::Button newNodeButton;
	newNodeButton.isSelected = false;
	newNodeButton.type = Button::addNode;
	newNodeButton.x = 50;
	newNodeButton.x2 = 112;
	newNodeButton.y = 200;
	newNodeButton.y2 = 250;

	Button::Button newPrettierButton;
	newPrettierButton.isSelected = false;
	newPrettierButton.type = Button::prettier;
	newPrettierButton.x = 50;
	newPrettierButton.x2 = 112;
	newPrettierButton.y = 300;
	newPrettierButton.y2 = 350;

	Button::Button newOrientationButton;
	newOrientationButton.isSelected = false;
	newOrientationButton.type = Button::orientation;
	newOrientationButton.x = 50;
	newOrientationButton.x2 = 112;
	newOrientationButton.y = 400;
	newOrientationButton.y2 = 450;

	Button::Button newDeleteGraphButton;
	newDeleteGraphButton.isSelected = false;
	newDeleteGraphButton.type = Button::deleteGraph;
	newDeleteGraphButton.x = 50;
	newDeleteGraphButton.x2 = 112;
	newDeleteGraphButton.y = 500;
	newDeleteGraphButton.y2 = 550;

	Button::Button newFileButton;
	newFileButton.isSelected = false;
	newFileButton.type = Button::file;
	newFileButton.x = 170;
	newFileButton.y = 10;
	strcpy(newFileButton.label, translations.fileButton);
	newFileButton.x2 = newFileButton.x + textwidth(newFileButton.label) + PADDING_LEFT;
	newFileButton.y2 = newFileButton.y + textheight(newFileButton.label) + PADDING_TOP;

	Button::Button newFunctionsButton;
	newFunctionsButton.isSelected = false;
	newFunctionsButton.type = Button::functions;
	newFunctionsButton.x = newFileButton.x2 + MARGIN_TOP_MENU;
	newFunctionsButton.y = 10;
	strcpy(newFunctionsButton.label, translations.functionsButton);
	newFunctionsButton.x2 = newFunctionsButton.x + textwidth(newFunctionsButton.label) + PADDING_LEFT;
	newFunctionsButton.y2 = newFunctionsButton.y + textheight(newFunctionsButton.label) + PADDING_TOP;

	Button::Button newPreferences;
	newPreferences.isSelected = false;
	newPreferences.type = Button::preferences;
	newPreferences.x = newFunctionsButton.x2 + MARGIN_TOP_MENU;
	newPreferences.y = 10;
	strcpy(newPreferences.label, translations.preferencesButton);
	newPreferences.x2 = newPreferences.x + textwidth(newPreferences.label) + PADDING_LEFT;
	newPreferences.y2 = newPreferences.y + textheight(newPreferences.label) + PADDING_TOP;

	Button::Button newMoreInfoButton;
	newMoreInfoButton.isSelected = false;
	newMoreInfoButton.type = Button::moreInfo;
	newMoreInfoButton.x = newPreferences.x2 + MARGIN_TOP_MENU;
	newMoreInfoButton.y = 10;
	strcpy(newMoreInfoButton.label, translations.moreInfoButton);
	newMoreInfoButton.x2 = newMoreInfoButton.x + textwidth(newMoreInfoButton.label) + PADDING_LEFT;
	newMoreInfoButton.y2 = newMoreInfoButton.y + textheight(newMoreInfoButton.label) + PADDING_TOP;

	Button::Button newHelpButton;
	newHelpButton.isSelected = false;
	newHelpButton.type = Button::help;
	newHelpButton.x = newMoreInfoButton.x2 + 30;
	newHelpButton.y = 10;
	strcpy(newHelpButton.label, translations.helpButton);
	newHelpButton.x2 = newHelpButton.x + textwidth(newHelpButton.label) + PADDING_LEFT;
	newHelpButton.y2 = newHelpButton.y + textheight(newHelpButton.label) + PADDING_TOP;

	mainMenu.mainMenuList.push_back(newNodeButton);
	mainMenu.mainMenuList.push_back(newEdgeButton);
	mainMenu.mainMenuList.push_back(newPrettierButton);
	mainMenu.mainMenuList.push_back(newOrientationButton);
	mainMenu.mainMenuList.push_back(newDeleteGraphButton);

	mainMenu.topMenuList.push_back(newFileButton);
	mainMenu.topMenuList.push_back(newFunctionsButton);
	mainMenu.topMenuList.push_back(newHelpButton);
	mainMenu.topMenuList.push_back(newPreferences);
	mainMenu.topMenuList.push_back(newMoreInfoButton);
}
void MainMenu::resetAllButtons(MainMenu& menu) {
	setfillstyle(SOLID_FILL, pallete.backgroundColor);
	bar(0, 0, 100, 2000);
	bar(0, 0, 2000, 40);
	for (auto i : menu.mainMenuList) {
		Button::drawButton(i);
	}
	for (auto i : menu.topMenuList) {
		Button::drawButton(i);
	}
}
void MainMenu::resetSideButtons(MainMenu& menu) {
	setfillstyle(SOLID_FILL, pallete.backgroundColor);
	bar(0, 0, 100, 2000);
	for (auto i : menu.mainMenuList) {
		Button::drawButton(i);
	}
}