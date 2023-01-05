#include "GraphTests.h"
#include "Graph.h"
Node newNode, newNode1, newNode2;
void createNodes() {

	newNode.currPosition = { 10, 20 };
	newNode.value = 1;
	newNode1.currPosition = { 40, 10 };
	newNode1.value = 2;
	newNode2.currPosition = { 20, 20 };
	newNode2.value = 3;
}
void principalTest() {
	Graph graph;
	createNodes();

	//addNodeToGraph(graph, newNode);
	addNodeToGraph(graph, newNode1);
	addNodeToGraph(graph, newNode2);

	addEdge(graph, newNode, newNode2, 20);
	addEdge(graph, newNode, newNode1, 30);
	addEdge(graph, newNode2, newNode1, 40);
	//removeEdge(graph, newNode, newNode1);

	addOrientatedEdge(graph, newNode1, newNode2, 10);
	addOrientatedEdge(graph, newNode2, newNode1, 10);
	addOrientatedEdge(graph, newNode1, newNode, 20);
	addOrientatedEdge(graph, newNode, newNode2, 50);
	removeOrientatedEdge(graph, newNode, newNode2);
	removeOrientatedEdge(graph, newNode, newNode2);
	removeOrientatedEdge(graph, newNode, newNode2);
	removeNodeFromGraph(graph, newNode);
}