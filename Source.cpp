#include <iostream>
#include "Translations.h"
#include "graphics.h"
#include "Graph.h"
#include "Node.h"
#include "GraphTests.h"
#include "GeneralHelpers.h"
#include "GraphHelpers.h"
#include "MainMenu.h"
#include "Interface.h"
#include "ColorsPallete.h"
#include "MouseEvents.h"
#include "GraphHelpers.h"
Translations::Translate translations;
ColorsPallete::Pallete pallete;
int main() {
	srand(time(nullptr));
	Translations::initTranslation(translations);
	ColorsPallete::initColorMode(pallete);
	MainMenu::MainMenu mainMenu;
	Graph graph;
	Interface::initInterface(mainMenu);
	MouseEvents::initMouseEvents(mainMenu, graph);
	//principalTest();
}