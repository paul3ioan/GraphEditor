#include "MouseEvents.h"
#include "Button.h"
#include "graphics.h"
#include "Interface_Constants.h"
#include "Preferences.h"
#include "MainMenuActions.h"
#include "DeleteGraph.h"
#include "ErrorPopup.h"
#include "Interface.h"
#include <iostream>
bool isButtonPressed(int x, int y, int x2, int y2, int xMouse, int yMouse) {
	return x <= xMouse && x2 >= xMouse && y <= yMouse && y2 >= yMouse;
}
int findButton(int x, int y, MainMenu::MainMenu mainMenu)
{
	int index = 0, finalIndex = 0;
	// check if mouse is on main menu
	for (auto i : mainMenu.mainMenuList)
	{
		if (isButtonPressed(i.x, i.y, i.x2, i.y2, x, y))
			return index;
		index ++;
	}
	for (auto i : mainMenu.topMenuList)
	{
		if (isButtonPressed(i.x, i.y, i.x2, i.y2, x, y))
			return index;
		index++;
	}
	return -1;
}
void update(int& oldPos, int& newPos, int x, int y, MainMenu::MainMenu& mainMenu)
{
	newPos = findButton(x, y, mainMenu);
	if (newPos != oldPos)
	{
		if (oldPos < mainMenu.mainMenuList.size()) {
			mainMenu.mainMenuList[oldPos].isHovered = false;
		}

		if (newPos != -1 && newPos < mainMenu.mainMenuList.size())
		{
			mainMenu.mainMenuList[newPos].isHovered = true;
		}
		oldPos = newPos;
		MainMenu::resetSideButtons(mainMenu);
	}
}
void chooseButton(MainMenu::MainMenu& mainMenu, int oldPos, Graph& graph) {
	std::cout << oldPos<< '\n';
	switch (oldPos) {
	case MouseEvents::addEdge:
		MainMenuActions::addEdgeInterface(mainMenu, graph);
		break;
	case MouseEvents::addNode:
		std::cout << "add node";
		MainMenuActions::addNodeInterface(mainMenu, graph);
		break;
	case MouseEvents::prettier:
		std::cout << "Add Prettier\n";
		break;
	case MouseEvents::orientation:
		std::cout << "Orientation\n";
		break;
	case MouseEvents::prefernces:
		Preference::initPopup(mainMenu, graph);
		break;
	case MouseEvents::deleteGraph:
		if (isGraphEmpty(graph))
		{
			ErrorPopup::errorInitPopup(translations.noGraphToDeleteTitle, translations.noGraphToDeleteMessage);
			break;
		}
		DeleteGraph::initPopup(mainMenu, graph);
		break;
	}
}
void MouseEvents::initMouseEvents(MainMenu::MainMenu& mainMenu, Graph& graph)
{
	int looped;
	int x, y;
	int newPos(-1), oldPos(-1);
	while (1)
	{
		if (ismouseclick(WM_MOUSEMOVE))
		{
			getmouseclick(WM_MOUSEMOVE, x, y);
			//std::cout <<"Mouse movements: "<< x << " " << y << '\n';
			// de verificat de ce more info and so on doesnt work
			update(oldPos, newPos, x, y, mainMenu);
		}
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			clearmouseclick(WM_LBUTTONDOWN);
			if (newPos != -1)
			{
				chooseButton(mainMenu, oldPos, graph);
			}
			oldPos = -1;
			update(oldPos, newPos, mousex(), mousey(), mainMenu);
		}
	///	std::cout << oldPos << " " << newPos << '\n';
	}
}