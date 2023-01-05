#include "Interface.h"
#include "GraphHelpers.h"
#include "Graph.h"
#include "Translations.h"
#include "ColorsPallete.h"

void Interface::createLayoutLines() {
	DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
	setfillstyle(SOLID_FILL, GREEN);
	bar(130, 50, 133, screenHeight);
	bar(130, 50, screenWidth, 53);
}

void Interface::initInterface(MainMenu::MainMenu& mainMenu) {
	DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
	initwindow(screenWidth, screenHeight, translations.programTitle);
	setfillstyle(SOLID_FILL, pallete.backgroundColor);
	bar(0, 0, 3000, 3000);
	MainMenu::initInterface(mainMenu);
	MainMenu::resetAllButtons(mainMenu);
	createLayoutLines();
}

void Interface::refreshInterface(MainMenu::MainMenu& mainMenu, Graph& graph) {
	setfillstyle(SOLID_FILL, pallete.backgroundColor);
	bar(0, 0, 2000, 1000);
	GraphHelpers::drawGraph(graph);
	MainMenu::initInterface(mainMenu);
	MainMenu::resetAllButtons(mainMenu);
	createLayoutLines();
}
