#pragma once
#include "Graph.h"
namespace FileServices
{
	void saveData(Graph& graph);
	void configureData(Graph& graph);
	void loadPreferences();
	void loadGraph(Graph& graph);
};

