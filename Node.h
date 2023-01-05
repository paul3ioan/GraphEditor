#pragma once
struct Position {
	int x, y;
};
struct Node {
	int value;
	Position currPosition;
	Position defaultPosition;
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

