#include "FileServices.h"
#include "Translations.h"
#include "ColorsPallete.h"
#include <cstring>
#include <fstream>
using namespace std;

void FileServices::saveData(Graph& graph) {
	std::string output;
	ofstream fout("saved_data.out");
	switch (pallete.mode) {
	case ColorsPallete::darkMode:
		output += "d ";
		break;
	case ColorsPallete::lightMode:
		output += "l ";
		break;
	}
	switch (translations.lang)
	{
	case Translations::english:
		output += "en ";
		break;
	case Translations::french:
		output += "fr ";
		break;
	case Translations::romanian:
		output += "ro ";
		break;
	default:
		break;
	}
	fout << output << '\n';
	fout << graph.nodes.size() << '\n';
	for (auto i : graph.nodes) {
		fout << i.value << " " << i.currPosition.x << " " << i.currPosition.y << '\n';
	}
	for (int i = 0; i < 100; i ++) {
		Node selectedNode;
		for (auto j : graph.nodes) {
			if (i == j.value) {
				selectedNode = j;
				break;
			}
		}
		for (auto edge : graph.orientedEdges[i])
			fout << i << " " << edge.cost << " " << selectedNode.value << " " << selectedNode.currPosition.x << " " << selectedNode.currPosition.y << " " << edge.to.value << " " << edge.to.currPosition.x << " " << edge.to.currPosition.y << '\n';
	}
	fout.close();
}
void FileServices::configureData(Graph& graph) {
	loadPreferences();
	loadGraph(graph);
}
void FileServices::loadPreferences() {
	ifstream fin("saved_data.out");
	char s[250];
	bool colorSet = false, languageSet = false;
	fin.getline(s, 250);
	char* p = strtok(s, " ");
	while (p) {
		if (strcmp(p, "d") == 0) {
			ColorsPallete::changeColorMode(ColorsPallete::darkMode, pallete);
			colorSet = true;
		}
		if (strcmp(p, "l") == 0) {
			ColorsPallete::changeColorMode(ColorsPallete::lightMode, pallete);
			colorSet = true;
		}
		if (strcmp(p, "ro") == 0) {
			Translations::changeTranslation(Translations::romanian, translations);
			languageSet = true;
		}
		if (strcmp(p, "en") == 0) {
			Translations::changeTranslation(Translations::english, translations);
			languageSet = true;
		}
		if (strcmp(p, "fr") == 0) {
			Translations::changeTranslation(Translations::french, translations);
			languageSet = true;
		}
		p = strtok(NULL, " ");
	}
	if (!colorSet) {
		ColorsPallete::changeColorMode(ColorsPallete::darkMode, pallete);
	}
	if (!languageSet) {
		Translations::changeTranslation(Translations::english, translations);
	}
}
void FileServices::loadGraph(Graph& graph) {
	int numberOfNodes, value, x, y;
	char s[250];
	ifstream fin("saved_data.out");
	fin.getline(s, 250);
	fin >> numberOfNodes;
	deleteGraph(graph);
	for (int i = 0; i < numberOfNodes; i++) {
		fin >> value >> x >> y;
		Node newNode;
		newNode.value = value;
		newNode.currPosition = { x, y };
		addNodeToGraph(graph, newNode);
	}
	int fromNode, fromValue, fromX, fromY, cost, toValue, toX, toY;
	while (fin >> fromNode) {
		fin >> cost >> fromValue >> fromX >> fromY >> toValue >> toX >> toY;
		Node froNode, toNode;
		froNode.value = fromValue;
		froNode.currPosition = { fromX, fromY };
		toNode.value = toValue;
		toNode.currPosition = { toX, toY };
		addOrientatedEdge(graph, froNode, toNode, cost);
	}
	fin.close();
}