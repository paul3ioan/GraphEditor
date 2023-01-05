#pragma once
#include "Graph.h"
namespace GraphHelpers
{
	void drawNode(int,int, char*, bool);
	void showName(int textColor,int,int, char*, bool);
	void drawCurvedLine(int x1, int y1, int x2, int y2, int color, int w);
	void drawCurvedLine2(int x1, int y1, int x2, int y2, int color, int w);
	void drawArrow(int x1, int y1, int x2, int y2, int color, int w);
	void drawTriangle(int x1, int y1, int x2, int y2, int color);
	void printWeight(int x, int y, int w);
	void drawGraph(Graph&);

};

