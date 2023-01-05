#include "Bfs.h"
#include "ErrorPopup.h"
#include <vector>
#include "graphics.h"
#include <iostream>
#include "Graph.h"
#include "GraphHelpers.h"
#include "Interface_Constants.h"
#include "FileServices.h"
#include "GraphHelpers.h"
#include "Translations.h"
#include "Interface.h"
#include "ColorsPallete.h"
#include "GeneralHelpers.h"
#include <queue>

void Bfs::closePopup(int main, int popup) {
	setactivepage(main);
	setcurrentwindow(main);
	closegraph(popup);
}
bool Bfs::isButtonPressed(int x, int y, int x2, int y2, int xMouse, int yMouse) {
	return x <= xMouse && x2 >= xMouse && y <= yMouse && y2 >= yMouse;
}
int Bfs::findButton(int x, int y, OptionsButtons optionsButtons)
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
Button::Button Bfs::createButton(int x, char* label, bool isHovered = false) {
	Button::Button newButton;
	newButton.x = x;
	newButton.y = 10;
	newButton.isHovered = isHovered;
	strcpy(newButton.label, label);
	newButton.x2 = x + textwidth(label) + 30;
	newButton.y2 = 10 + textheight(label) + PADDING_TOP;
	return newButton;
}
void Bfs::initInterface(OptionsButtons& optionButtons) {
	optionButtons.optionButton.push_back(createButton(200, translations.rewatch));
	optionButtons.optionButton.push_back(createButton(300, translations.generalExit));
}
void Bfs::changeButtonHovered(OptionsButtons& optionButtons, int index, bool isInputActive = false) {
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
void Bfs::drawInterface(OptionsButtons& optionButtons, bool isInputActive = false) {
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
void Bfs::highlightEdge(Graph& graph, std::pair<int, int> coloredEdge) {
	for (int i = 0; i < graph.orientedEdges[coloredEdge.first].size(); i++) {
		if (graph.orientedEdges[coloredEdge.first][i].to.value == coloredEdge.second) {
			graph.orientedEdges[coloredEdge.first][i].isHighlighted = true;
		}
	}
}
void Bfs::startBfs(Graph& graph) {
	int fr[100] = { 0 };
	GraphHelpers::drawGraph(graph);
	delay(500);
	for (int i = 0; i < 100; i++) {
		if (!fr[i] && graph.availableNode[i]) {
			std::queue<int> q;
			q.push(i);
			std::queue<std::pair<int, int>> edges;
			while (!q.empty()) {
				int aux = q.front();
				fr[aux] = 1;
				q.pop();
				if (!edges.empty()) {
					auto coloredEdge = edges.front();
					edges.pop();
					highlightEdge(graph, coloredEdge);
				}
				for (int i = 0; i < graph.nodes.size(); i ++) {
					if (graph.nodes[i].value == aux) {
						graph.nodes[i].isHovered = true;
						break;
					}	
				}
				for (auto edge : graph.orientedEdges[aux]) {
					if (!fr[edge.to.value]) {
						q.push(edge.to.value);
					}
					edges.push({ aux, edge.to.value });
				}
				GraphHelpers::drawGraph(graph);
				delay(1000);
			}
			while (!edges.empty()) {
				auto coloredEdge = edges.front();
				edges.pop();
				highlightEdge(graph, coloredEdge);
				GraphHelpers::drawGraph(graph);
				delay(1000);
			}
		}
	}
	for (int i = 0; i <= 100;i++) {
		for (int j = 0; j < graph.orientedEdges[i].size(); j++)
			graph.orientedEdges[i][j].isHighlighted = false;
	}
	for (int i = 0; i < graph.nodes.size(); i++) {
		graph.nodes[i].isHovered = false;
	}
}
int Bfs::initPopup(Graph& graph) {
	DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
	int main = getcurrentwindow();
	OptionsButtons optionButtons;
	int popup = initwindow(screenWidth, screenHeight, translations.bfsTitle);
	initInterface(optionButtons);
	setfillstyle(SOLID_FILL, pallete.backgroundColor);
	bar(0, 0, 2000, 2000);
	drawInterface(optionButtons);
	Interface::createLayoutLines();
	int x, y;
	startBfs(graph);
	while (true) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			int whichButton = findButton(x, y, optionButtons);
			switch (whichButton) {
			case retry: 
				startBfs(graph);
				break;
			case exitt:
				closePopup(main, popup);
				return 1;
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
