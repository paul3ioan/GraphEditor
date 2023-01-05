#pragma once
#include "MainMenu.h"
#include "Graph.h"
namespace MouseEvents
{
	enum MouseActions {
		addNode,
		addEdge,
		prettier,
		orientation,
		deleteGraph,
		file,
		programs,
		help,
		prefernces,
		moreInfo
	};
	void initMouseEvents(MainMenu::MainMenu&, Graph&);
};

