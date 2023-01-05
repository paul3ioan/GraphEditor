#pragma once
#include "graphics.h"
namespace Button
{
	const int addNewEdgeX = 200;
	const int addNewEdgeX2 = 300;
	const int addNewEdgeY = 600;
	const int addNewEdgeY2 = 700;
	enum ButtonType {
		addNode,
		addEdge,
		normal,
		prettier,
		orientation,
		deleteGraph,
		file,
		functions,
		help,
		moreInfo,
		preferences,
	};
	struct Button {
		int x, y, x2, y2;
		char label[100];
		bool isSelected = false;
		bool isHovered = false;
		ButtonType type;
	};
	void showSimpleButton(Button&);
	void drawButton(Button&);
};

