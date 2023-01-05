#pragma once
#include <vector>
#include "Node.h"

struct Graph {
	std::vector<Node> nodes;
	std::vector<Edge> edges[101];
	std::vector<OrientatedEdge> orientedEdges[101];
	int adjMatrix[102][102] = {0};
	bool availableNode[102] = {0};
};
void deleteGraph(Graph&);
bool isGraphEmpty(Graph&);
void addNodeToGraph(Graph&, Node newNode);
void removeNodeFromGraph(Graph&, Node removeNode);
void addEdge(Graph&, Node start, Node end, int cost);
void removeEdge(Graph&, Node start, Node end, bool isInternal = false);
void removeOrientatedEdge(Graph&, Node start, Node end, bool isInternal = false);
void addOrientatedEdge(Graph&, Node start, Node end, int cost);