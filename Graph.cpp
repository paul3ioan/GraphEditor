#include "Graph.h"
#include "LogicException.h"

void deleteGraph(Graph& graph) {
	graph.nodes.clear();
	for (int i = 0; i <= 100; i++) {
		graph.edges[i].clear();
		graph.orientedEdges[i].clear();
	}
	for (int i = 0; i <= 100; i++) {
		for (int j = 0;j <= 100; j++)
			graph.adjMatrix[i][j] = 0;
	}
}
bool isGraphEmpty(Graph& graph) {
	return graph.nodes.empty();
}

void addNodeToGraph(Graph& graph, Node newNode) {
	graph.nodes.push_back(newNode);
	graph.availableNode[newNode.value] = 1;
}
void removeNodeFromGraph(Graph& graph, Node removeNode) {
	std::vector<Node>::iterator it;
	for (it = graph.nodes.begin(); it != graph.nodes.end(); it++) {
		if ((*it).value == removeNode.value) {
			break;
		}
	}
	if (it == graph.nodes.end()) {
		Exceptions::logError("Try to remove nonexistent node");
		return;
	}
	for (auto& node : graph.nodes) {
		removeEdge(graph, *it, node, true);
		removeEdge(graph, node, *it, true);
		removeOrientatedEdge(graph, *it, node, true);
		removeOrientatedEdge(graph, node, *it, true);
	}
	graph.availableNode[removeNode.value] = 0;
	graph.nodes.erase(it);
}
void addEdge(Graph& graph, Node start, Node end, int cost) {
	Edge newEdge, newReversedEdge;
	newEdge.cost = cost;
	newEdge.start = start.currPosition;
	newEdge.end = end.currPosition;
	newEdge.to = end;

	newReversedEdge.cost = cost;
	newReversedEdge.start = end.currPosition;
	newReversedEdge.end = start.currPosition;
	newReversedEdge.to = start;
	graph.edges[start.value].push_back(newEdge);
	graph.edges[end.value].push_back(newReversedEdge);
	graph.adjMatrix[start.value][end.value] = cost;
	graph.adjMatrix[end.value][start.value] = cost;
}
void removeEdge(Graph& graph, Node start, Node end, bool isInternal) {
	std::vector<Edge>::iterator it;
	bool somethingIsDeleted = false;
	for (it = graph.edges[start.value].begin(); it != graph.edges[start.value].end(); it++) {	
		if ((*it).to.value == end.value) {
			graph.edges[start.value].erase(it);
			somethingIsDeleted = true;
			break;
		}
	}
	for (it = graph.edges[end.value].begin(); it != graph.edges[end.value].end(); it++) {
		if ((*it).to.value == start.value) {
			graph.edges[end.value].erase(it);
			somethingIsDeleted = true;
			break;
		}
	}
	if (!somethingIsDeleted && !isInternal) {
		Exceptions::logError("Try to remove nonexistent edge");
		return;
	}
	graph.adjMatrix[start.value][end.value] = 0;
	graph.adjMatrix[end.value][start.value] = 0;
}
void removeOrientatedEdge(Graph& graph, Node start, Node end, bool isInternal) {
	std::vector<OrientatedEdge>::iterator it;
	bool somethingIsDeleted = false;

	for (it = graph.orientedEdges[start.value].begin(); it != graph.orientedEdges[start.value].end(); it++) {
		if ((*it).to.value == end.value) {
			graph.orientedEdges[start.value].erase(it);
			somethingIsDeleted = true;
			break;
		}
	}
	if (!somethingIsDeleted && !isInternal) {
		Exceptions::logError("Try to remove nonexistent orientated edge");
		return;
	}
	graph.adjMatrix[start.value][end.value] = 0;
}
void addOrientatedEdge(Graph& graph, Node start, Node end, int cost) {
	OrientatedEdge newEdge;
	newEdge.cost = cost;
	newEdge.start = start.currPosition;
	newEdge.end = end.currPosition;
	newEdge.to = end;
	if (graph.adjMatrix[start.value][end.value]) {
		removeOrientatedEdge(graph, start, end);
	}
	graph.orientedEdges[start.value].push_back(newEdge);
	graph.adjMatrix[start.value][end.value] = cost;
}