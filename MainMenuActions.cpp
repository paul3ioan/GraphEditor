#include "MainMenuActions.h"
#include "graphics.h"
#include "AddNodeInterface.h"
#include "GraphHelpers.h"
#include "Interface.h"
#include "Interface_Constants.h"
#include "AddEdgeValue.h"
#include <iostream>
#include "ErrorPopup.h"

bool isClickOnNode(Node node, int x, int y) {
	if (node.currPosition.x - RADIUS_VALUE <= x && node.currPosition.x + RADIUS_VALUE >= x) {
		if (node.currPosition.y - RADIUS_VALUE <= y && node.currPosition.y + RADIUS_VALUE >= y) {
			return true;
		}
	}
	return false;
}
bool isNodeInList(int x, int y, Graph& graph) {
	for (auto i : graph.nodes) {
		Position pos = i.currPosition;
		if (x < pos.x + 2 * RADIUS_VALUE && y < pos.y + 2 * RADIUS_VALUE) {

			if (x + 2 * RADIUS_VALUE < pos.x || y + 2 * RADIUS_VALUE < pos.y) {
				continue;
			}
			return false;
		}
	}
	return true;
}
void MainMenuActions::addNodeInterface(MainMenu::MainMenu& mainMenu, Graph& graph) {
	int x, y;
	Button::Button addNodeButton;
	for (auto i : mainMenu.mainMenuList) {
		if (i.type == Button::addNode) {
			addNodeButton = i;
			break;
		}
	}
	while (graph.nodes.size() <= MAX_NODES) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if (x >= addNodeButton.x && x <= addNodeButton.x2 && addNodeButton.y <= y && addNodeButton.y2 >= y) {
				break;
			}
			if (x < MAX_WORKING_ZONE_LEFT || y < WORKING_TOP) {
				ErrorPopup::errorInitPopup(translations.outOfWorkZoneClickTitle, translations.outOfWorkZoneClickMessage);
				continue;
			}
			bool isNode = isNodeInList(x, y, graph);
			if (!isNode) {
				ErrorPopup::errorInitPopup(translations.outOfWorkZoneClickTitle, translations.clickOnANodeMessage);
				continue;
			}
			Node newNode;
			newNode.currPosition.x = x;
			newNode.currPosition.y = y;
			int newValue = AddNodeInterface::initPopup(graph);
			if (newValue == -1) {
				break;
			}
			newNode.value = newValue;
			addNodeToGraph(graph, newNode);
			break;
		}
	}
	Interface::refreshInterface(mainMenu, graph);
}
void MainMenuActions::addEdgeInterface(MainMenu::MainMenu& mainMenu, Graph& graph) {
	if (isGraphEmpty(graph) || graph.nodes.size() < 2) {
		ErrorPopup::errorInitPopup(translations.notEnoughNodesTitle, translations.notEnoughNodesMessage);
		return;
	}
	Button::Button addEdgeButton;
	for (auto i : mainMenu.mainMenuList) {
		if (i.type == Button::addEdge) {
			addEdgeButton = i;
			break;
		}
	}
	int nodeSelected = -1, x, y;
	while (true) {
		nodeSelected = -1;
		while (nodeSelected == -1) {
			if (ismouseclick(WM_LBUTTONDOWN))
			{
				getmouseclick(WM_LBUTTONDOWN, x, y);
				if (x >= addEdgeButton.x && x <= addEdgeButton.x2 && addEdgeButton.y <= y && addEdgeButton.y2 >= y) {
					break;
				}
				if (x < MAX_WORKING_ZONE_LEFT || y < WORKING_TOP) {
					ErrorPopup::errorInitPopup(translations.outOfWorkZoneClickTitle, translations.outOfWorkZoneClickMessage);
					continue;
				}
				for (int i = 0; i < graph.nodes.size(); i ++) {
					if (isClickOnNode(graph.nodes[i], x, y)) {
						nodeSelected = i;
					}
				}
			}
		}
		if (ismouseclick(WM_LBUTTONUP)) clearmouseclick(WM_LBUTTONUP);
		int lastNode = -1;
		while (!ismouseclick(WM_LBUTTONUP))
		{
			lastNode = -1;
			for (int i = 0; i < graph.nodes.size(); i++) {
				if (isClickOnNode(graph.nodes[i], mousex(), mousey())) {
					lastNode = i;
				}
			}
			if (mousex() < MAX_WORKING_ZONE_LEFT || mousey() < WORKING_TOP) {
				ErrorPopup::errorInitPopup(translations.outOfWorkZoneClickTitle, translations.outOfWorkZoneClickMessage);
				break;
			}
			GraphHelpers::drawGraph(graph);
			GraphHelpers::drawArrow(x, y, mousex(), mousey(), pallete.edgeColor, 0);
			delay(100);
		}if (lastNode == -1 || lastNode == nodeSelected) {
			GraphHelpers::drawGraph(graph);
			continue;
		}
		int returnedValue = AddEdgeValue::initPopup(graph);
		if (returnedValue == -1) {
			break;
		}
		addOrientatedEdge(graph, graph.nodes[nodeSelected], graph.nodes[lastNode], returnedValue);
		break;
	}
	Interface::refreshInterface(mainMenu, graph);
}
