#define _USE_MATH_DEFINES
#include "GraphHelpers.h"
#include "graphics.h"
#include "GeneralHelpers.h"
#include <windows.h>
#include "ColorsPallete.h"
#include "Node.h"
#include "Interface_Constants.h"
#include <cmath>
struct CalcPosition {
	float x, y;
};
enum workingZone
{
	wLEFT = 355, wbLEFT = 417,
	wTOP = 20,
	wRIGHT = 1000 - 10,
	wBOTTOM = 500
};
void GraphHelpers::printWeight(int x, int y, int w)
{
	setcolor(pallete.edgeValueColor);
	setbkcolor(pallete.backgroundColor);
	setusercharsize(10, 15, 10, 15);
	settextstyle(BOLD_FONT, HORIZ_DIR, 1);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	char str[100];
	strcpy(str, GeneralHelpers::fromIntToCharArray(w));
	outtextxy(x, y, str);
}
void GraphHelpers::drawTriangle(int x1, int y1, int x2, int y2, int color)
{

	setlinestyle(SOLID_LINE, 0, 2);
	setfillstyle(SOLID_FILL, color);
	int a[8];
	a[0] = x1 + y2 - y1;
	a[1] = y1 + x1 - x2;
	a[2] = x1 - y2 + y1;
	a[3] = y1 - x1 + x2;
	a[4] = x2; a[5] = y2;
	a[6] = a[0]; a[7] = a[1];
	setcolor(color);
	fillpoly(4, a);
}
void GraphHelpers::drawArrow(int x1, int y1, int x2, int y2, int color, int w)
{
	float corner = atan(float(abs(y1 - y2)) / abs(x1 - x2));
	float Rsin = RADIUS_VALUE * sin(corner);
	float Rcos = RADIUS_VALUE * cos(corner);
	int x11 = x1 + Rcos;
	int y11 = y1 + Rsin;
	int x22 = x2 - Rcos;
	int y22 = y2 - Rsin;
	if (x1 > x2)
	{
		x11 = x1 - Rcos;
		x22 = x2 + Rcos;
	}
	if (y1 > y2)
	{
		y11 = y1 - Rsin;
		y22 = y2 + Rsin;
	}
	setlinestyle(SOLID_LINE, 1, 2);
	setcolor(color);
	line(x11, y11, x22, y22);
	drawTriangle(2 * x22 - (x2 + x22) / 2, 2 * y22 - (y22 + y2) / 2, x22, y22, color);
	printWeight((x1 + x2) / 2, (y1 + y2) / 2, w);
}
void GraphHelpers::drawCurvedLine2(int x1, int y1, int x2, int y2, int color, int w)
{
	float xO = (x1 + x2) / 2 + (y1 - y2) / M_SQRT2; // or +
	float yO = (y1 + y2) / 2 + (x2 - x1) / M_SQRT2; // or +
	float r = sqrt(pow(xO - x1, 2) + pow(yO - y1, 2));
	float d = sqrt(pow(x1 - xO, 2) + pow(y1 - yO, 2));
	float a = (pow(r, 2) - pow(RADIUS_VALUE, 2) + pow(d, 2)) / (2 * d);
	float h = sqrt(r * r - a * a);								//					 
	float tmpx1 = xO + a * (x1 - xO) / d;						//					   xT		  
	float tmpx2 = xO + a * (x2 - xO) / d;						//        *  * x3             x4*  *
	float tmpy1 = yO + a * (y1 - yO) / d;						//     *        *            *        *
	float tmpy2 = yO + a * (y2 - yO) / d;						//    *    x1    *          *     x2   *
	int x3 = tmpx1 - h * (y1 - yO) / d;   // -h					//    *          *          *          *
	int x4 = tmpx2 + h * (y2 - yO) / d;   // +h					//     *        *            *        *
	int y3 = tmpy1 + h * (x1 - xO) / d;  // 					//        *  *                  *  *
	int y4 = tmpy2 - h * (x2 - xO) / d;  // 					//				 	   xO          
	float stangle, endangle;									//					 
	float angle1 = float(x1 - xO) / r;
	float angle2 = 1 - float(pow(RADIUS_VALUE, 2)) / (2 * pow(r, 2));
	if (angle1 < -1 || angle1 > 1) angle1 = int(angle1);
	if (angle2 < -1 || angle2 > 1) angle2 = int(angle2);
	angle1 = acos(angle1) * 180 / M_PI;
	angle2 = acos(angle2) * 180 / M_PI;
	if (y1 >= yO) angle1 = 360 - angle1;
	stangle = angle1 + angle2;
	angle1 = acos(1 - pow(sqrt(pow(x3 - x4, 2) + pow(y3 - y4, 2)), 2) / (2 * pow(r, 2)));
	angle1 = angle1 * 180 / M_PI;
	stangle = stangle - angle1 - 2 * angle2;
	endangle = stangle + angle1;
	float theta = atan2((y1 + y2) / 2 - yO, (x1 + x2) / 2 - xO);
	float xT = xO + r * cos(theta);
	float yT = yO + r * sin(theta);
	setcolor(color);
	setlinestyle(SOLID_LINE, 1, 2);
	arc(xO, yO, stangle, endangle, r);
	drawTriangle(2 * x4 - (x2 + x4) / 2, 2 * y4 - (y2 + y4) / 2, x4, y4, color); // FINALY
	printWeight(xT, yT, w);
}
void GraphHelpers::drawCurvedLine(int x1, int y1, int x2, int y2, int color, int w)
{
	float xO = (x1 + x2) / 2 + (y1 - y2) / -M_SQRT2; // or +
	float yO = (y1 + y2) / 2 + (x2 - x1) / -M_SQRT2; // or +
	float r = sqrt(pow(xO - x1, 2) + pow(yO - y1, 2));
	float d = sqrt(pow(x1 - xO, 2) + pow(y1 - yO, 2));
	float a = (pow(r, 2) - pow(RADIUS_VALUE, 2) + pow(d, 2)) / (2 * d);
	float h = sqrt(r * r - a * a);								//					 
	float tmpx1 = xO + a * (x1 - xO) / d;						//					   xT		  
	float tmpx2 = xO + a * (x2 - xO) / d;						//        *  * x3             x4*  *
	float tmpy1 = yO + a * (y1 - yO) / d;						//     *        *            *        *
	float tmpy2 = yO + a * (y2 - yO) / d;						//    *    x1    *          *     x2   *
	int x3 = tmpx1 + h * (y1 - yO) / d;   // -h					//    *          *          *          *
	int x4 = tmpx2 - h * (y2 - yO) / d;   // +h					//     *        *            *        *
	int y3 = tmpy1 - h * (x1 - xO) / d;  // 					//        *  *                  *  *
	int y4 = tmpy2 + h * (x2 - xO) / d;  // 					//				 	   xO          
	float stangle, endangle;									//					 
	float angle1 = float(x1 - xO) / r;
	float angle2 = 1 - float(pow(RADIUS_VALUE, 2)) / (2 * pow(r, 2));
	if (angle1 < -1 || angle1 > 1) angle1 = int(angle1);
	if (angle2 < -1 || angle2 > 1) angle2 = int(angle2);
	angle1 = acos(angle1) * 180 / M_PI;
	angle2 = acos(angle2) * 180 / M_PI;
	if (y1 >= yO) angle1 = 360 - angle1;
	stangle = angle1 + angle2;
	angle1 = acos(1 - pow(sqrt(pow(x3 - x4, 2) + pow(y3 - y4, 2)), 2) / (2 * pow(r, 2)));
	angle1 = angle1 * 180 / M_PI;
	endangle = stangle + angle1;
	float theta = atan2((y1 + y2) / 2 - yO, (x1 + x2) / 2 - xO);
	float xT = xO + r * cos(theta);
	float yT = yO + r * sin(theta);
	if (xT <= wbLEFT || xT >= wRIGHT || yT <= wTOP || yT >= wBOTTOM)
		return drawCurvedLine2(x1, y1, x2, y2, color, w);
	setcolor(color);
	setlinestyle(SOLID_LINE, 1, 2);
	arc(xO, yO, stangle, endangle, r);
	drawTriangle(2 * x4 - (x2 + x4) / 2, 2 * y4 - (y2 + y4) / 2, x4, y4, color); // FINALY
	printWeight(xT, yT, w);
}
void GraphHelpers::showName(int textColor, int x, int y, char* number)
{
	setcolor(textColor);
	setbkcolor(pallete.graphNodeBackgroundColor);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	if (strlen(number) < 3)
	{
		setusercharsize(3, 5, 3, 5);
		settextstyle(SANS_SERIF_FONT, HORIZ_DIR, USER_CHAR_SIZE);
	}
	else
		settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
	outtextxy(x, y + 5, number);
}
void GraphHelpers::drawNode(int x, int y, char* value, bool isSelected = false)
{
	setlinestyle(SOLID_LINE, 1, NORM_WIDTH);
	if (isSelected) {
		setcolor(BLACK);
		setfillstyle(SOLID_FILL, RED);

	}
	else {
	setcolor(pallete.graphNodeBackgroundColor);
	setfillstyle(SOLID_FILL, pallete.graphNodeBackgroundColor);
	}
	circle(x, y, RADIUS_VALUE);
	if (isSelected) {
		floodfill(x, y, RED);
	}
	else {
		floodfill(x, y, pallete.graphNodeBackgroundColor);
	}
	showName(pallete.graphNodeLabelColor, x, y, value);
}
void GraphHelpers::drawGraph(Graph& graph) {
	setfillstyle(SOLID_FILL, pallete.backgroundColor);
	bar(150, 80, 2000, 2000);
	for (auto i : graph.nodes) {
		char label[100];
		strcpy(label, GeneralHelpers::fromIntToCharArray(i.value));
		drawNode(i.currPosition.x, i.currPosition.y, label);
	}
	for (int i = 0; i < 101; i ++) {
		for (auto node: graph.orientedEdges[i]) {
			Position from = node.start, to = node.end;
			if (i > node.to.value) {
					drawArrow(from.x, from.y, to.x, to.y, pallete.edgeColor, node.cost);
				continue;
			}
			if (graph.adjMatrix[node.to.value][i]) {
				drawCurvedLine(from.x, from.y, to.x, to.y, pallete.edgeColor, node.cost);
			}
			else {
				drawArrow(from.x, from.y, to.x, to.y, pallete.edgeColor, node.cost);
			}
		}
	}
}