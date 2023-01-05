#include "MouseEvents.h"
#include "Button.h"
#include "graphics.h"
#include "Interface_Constants.h"
#include "Preferences.h"
#include "NodeInterface.h"
#include "MainMenuActions.h"
#include "DeleteGraph.h"
#include "Functions.h"
#include "ErrorPopup.h"
#include "GraphHelpers.h"
#include "Interface.h"
#include <iostream>

bool isButtonPressed(int x, int y, int x2, int y2, int xMouse, int yMouse) {
	return x <= xMouse && x2 >= xMouse && y <= yMouse && y2 >= yMouse;
}
bool isHoverOnNode(Node node, int x, int y) {
	if (node.currPosition.x - RADIUS_VALUE <= x && node.currPosition.x + RADIUS_VALUE >= x) {
		if (node.currPosition.y - RADIUS_VALUE <= y && node.currPosition.y + RADIUS_VALUE >= y) {
			return true;
		}
	}
	return false;
}
int findNode(int x, int y, Graph& graph) {
	for (auto i : graph.nodes) {
		if (isHoverOnNode(i, x, y)) {
			return i.value + 100;
		}
	}
	return -1;
}
int findButton(int x, int y, MainMenu::MainMenu mainMenu, Graph &graph)
{
	int index = 0, finalIndex = 0;
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
	return findNode(x, y, graph);
}
void update(int& oldPos, int& newPos, int x, int y, MainMenu::MainMenu& mainMenu, Graph& graph)
{
	newPos = findButton(x, y, mainMenu, graph);
	if (newPos != oldPos)
	{
		if (oldPos < mainMenu.mainMenuList.size()) {
			mainMenu.mainMenuList[oldPos].isHovered = false;
		}

		if (newPos != -1 && newPos < mainMenu.mainMenuList.size())
		{
			mainMenu.mainMenuList[newPos].isHovered = true;
			MainMenu::resetSideButtons(mainMenu);
		}
		for (int i = 0; i < graph.nodes.size(); i++) {
			graph.nodes[i].isHovered = false;
		}
		if (newPos >= 100) {
			for (int i = 0; i < graph.nodes.size(); i ++) {
				if (graph.nodes[i].value == newPos - 100) {
					graph.nodes[i].isHovered = true;
				}
			}
		}
		if (oldPos == newPos) {
			return;
		}
		oldPos = newPos;
		MainMenu::resetSideButtons(mainMenu);
		GraphHelpers::drawGraph(graph);
	}
}
void chooseButton(MainMenu::MainMenu& mainMenu, int oldPos, Graph& graph) {
	switch (oldPos) {
	case MouseEvents::addEdge:
		MainMenuActions::addEdgeInterface(mainMenu, graph);
		break;
	case MouseEvents::addNode:
		MainMenuActions::addNodeInterface(mainMenu, graph);
		break;
	case MouseEvents::programs:
		Functions::initPopup(graph);
	case MouseEvents::prettier:
		ErrorPopup::errorInitPopup(translations.notImplementedTitle, translations.notImplementedMessage);
		break;
	case MouseEvents::orientation:
		ErrorPopup::errorInitPopup(translations.notImplementedTitle, translations.notImplementedMessage);
		break;
	case MouseEvents::prefernces:
		Preference::initPopup(mainMenu, graph);
		break;
	case MouseEvents::file:
		ErrorPopup::errorInitPopup(translations.notImplementedTitle, translations.notImplementedMessage);
		break;
	case MouseEvents::moreInfo:
		ErrorPopup::errorInitPopup(translations.notImplementedTitle, translations.notImplementedMessage);
		break;
	case MouseEvents::help:
		ErrorPopup::errorInitPopup(translations.notImplementedTitle, translations.notImplementedMessage);
		break;
	case MouseEvents::deleteGraph:
		if (isGraphEmpty(graph))
		{
			ErrorPopup::errorInitPopup(translations.noGraphToDeleteTitle, translations.noGraphToDeleteMessage);
			break;
		}
		DeleteGraph::initPopup(mainMenu, graph);
		break;
	default:
		if (oldPos != -1) {
			NodeInterface::initPopup(graph);
		}
		break;
	}
	if (oldPos < mainMenu.mainMenuList.size()) {
		mainMenu.mainMenuList[oldPos].isHovered = false;
		MainMenu::resetSideButtons(mainMenu);
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
			update(oldPos, newPos, x, y, mainMenu, graph);
		}
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			clearmouseclick(WM_LBUTTONDOWN);
			if (newPos != -1)
			{
				chooseButton(mainMenu, oldPos, graph);
			}
			oldPos = -1;
			update(oldPos, newPos, mousex(), mousey(), mainMenu, graph);
		}
	}
}