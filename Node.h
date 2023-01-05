#pragma once
struct Position {
	int x, y;
};
struct Node {
	int value;
	Position currPosition;
	Position defaultPosition;
	bool isHovered = false;
};
struct Edge {
	Position start;
	Position end;
	Node to;
	int cost;
};
struct OrientatedEdge {
	Position start;
	Position end;
	Node to;
	int cost;
};

