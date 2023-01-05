#include "NodeInterface.h"
#include "ErrorPopup.h"
#include <vector>
#include "graphics.h"
#include <iostream>
#include "Graph.h"
#include "GraphHelpers.h"
#include "Interface_Constants.h"
#include "Translations.h"
#include "ColorsPallete.h"
#include "GeneralHelpers.h"

void NodeInterface::closePopup(int main, int popup) {
	setactivepage(main);
	setcurrentwindow(main);
	closegraph(popup);
}
bool NodeInterface::isButtonPressed(int x, int y, int x2, int y2, int xMouse, int yMouse) {
	return x <= xMouse && x2 >= xMouse && y <= yMouse && y2 >= yMouse;
}
int NodeInterface::findButton(int x, int y, OptionsButtons optionsButtons)
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
Button::Button NodeInterface::createButton(int y, char* label, bool isHovered = false) {
	Button::Button newButton;
	newButton.x = 30;
	newButton.y = y;
	newButton.isHovered = isHovered;
	strcpy(newButton.label, label);
	newButton.x2 = 270;
	newButton.y2 = y + textheight(label) + PADDING_TOP;
	return newButton;
}
void NodeInterface::initInterface(OptionsButtons& optionButtons) {
	optionButtons.optionButton.push_back(createButton(30, translations.nodeOptionsDelete));
	optionButtons.optionButton.push_back(createButton(70, translations.nodeOptionsMove));
	optionButtons.optionButton.push_back(createButton(150, translations.generalExit));
}
void NodeInterface::changeButtonHovered(OptionsButtons& optionButtons, int index, bool isInputActive = false) {
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
void NodeInterface::drawInterface(OptionsButtons& optionButtons, bool isInputActive = false) {
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
void NodeInterface::showInputField() {
	setbkcolor(pallete.backgroundColor);
	settextjustify(LEFT_TEXT, CENTER_TEXT);
	outtextxy(20, 200, translations.addEdgeInputLabel);
}

void NodeInterface::showError(char* msg) {
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
bool isNodeList(int x, int y, Graph& graph, Node selectedNode) {
	for (auto i : graph.nodes) {
		if (i.value == selectedNode.value) {
			continue;
		}
		Position pos = i.currPosition;
		if (x < pos.x + 2 * RADIUS_VALUE && y < pos.y + 2 * RADIUS_VALUE) {

			if (x + 2 * RADIUS_VALUE < pos.x - 10 || y + 2 * RADIUS_VALUE < pos.y - 10) {
				continue;
			}
			return false;
		}
	}
	return true;
}
int NodeInterface::initPopup(Graph& graph) {
	int main = getcurrentwindow();
	OptionsButtons optionButtons;
	int popup = initwindow(300, 500, translations.nodeOptionsTitle, 450, 170);
	initInterface(optionButtons);
	setfillstyle(SOLID_FILL, pallete.backgroundColor);
	bar(0, 0, 2000, 2000);
	drawInterface(optionButtons);
	int x, y;
	int selectedIndex;

	Node selectedNode;
	for (auto i : graph.nodes) {
		if (i.isHovered) {
			selectedNode = i;
			break;
		}
	}

	while (true) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			int whichButton = findButton(x, y, optionButtons);
			switch (whichButton) {
			case deleteNode:
				removeNodeFromGraph(graph, selectedNode);
				closePopup(main, popup);
				GraphHelpers::drawGraph(graph);
				return 1;
			case moveNode:
				for (int i = 0; i < graph.nodes.size(); i++) {
					if (selectedNode.value == graph.nodes[i].value)
					{
						graph.nodes[i].defaultPosition = graph.nodes[i].currPosition;
						selectedIndex = i;
						break;
					}
				}
				closePopup(main, popup);
				while (true) {
					if (ismouseclick(WM_MOUSEMOVE)) {
						getmouseclick(WM_MOUSEMOVE, x, y);
						if (x < MAX_WORKING_ZONE_LEFT + 20 || y < WORKING_TOP) {
							ErrorPopup::errorInitPopup(translations.outOfWorkZoneClickTitle, translations.outOfWorkZoneClickMessage);
							continue;
						}
						bool isPositionOk = isNodeList(x, y, graph, selectedNode);
						if (!isPositionOk) {
							continue;
						}
						graph.nodes[selectedIndex].currPosition = { x, y };
						for (int i = 0; i < graph.orientedEdges[selectedNode.value].size(); i++) {
							graph.orientedEdges[selectedNode.value][i].start = { x, y };
						}
						for (int i = 0; i < 100 ; i++) {
							for(int j = 0; j < graph.orientedEdges[i].size(); j ++)
								if (graph.orientedEdges[i][j].to.value == selectedNode.value) {
									graph.orientedEdges[i][j].end = { x, y };
								}
						}
						GraphHelpers::drawGraph(graph);
						delay(10);
					}
					if (ismouseclick(WM_LBUTTONDOWN)) {
						break;
					}
				}
				return 1;
			case exitt:
				closePopup(main, popup);
				return -1;
			default:
				break;
			}
		}
		else
			if (ismouseclick(WM_MOUSEMOVE))
			{
				getmouseclick(WM_MOUSEMOVE, x, y);
				int whichButton = findButton(x, y, optionButtons);
				changeButtonHovered(optionButtons, whichButton);
			}
	}

	return 1;
}
