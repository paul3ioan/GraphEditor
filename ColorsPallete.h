#pragma once
#include "graphics.h"
namespace ColorsPallete
{
	enum ColorMode {
		darkMode,
		lightMode
	};
	struct Pallete {
		int buttonBackgroundColor;
		int buttonLabelColor;
		int buttonBackgroundHoverColor;
		int buttonLabelHoverColor;
		int buttonBackgroundActiveColor;
		int buttonLabelActiveColor;
		int graphNodeBackgroundColor;
		int graphNodeLabelColor;
		int backgroundColor;
		int exitBackgroundColor;
		int exitTextColor;
		int sideMenuBackgroundColor;
		int sideMenuLabelColor;
		int sideMenuActiveBackgroundColor;
		int sideMenuActiveLabelColor;
		int sideMenuHoverBackgroundColor;
		int sideMenuHoverLabelColor;
		int additionalInfoColor;
		int errorTitleColor;
		int errorMessageColor;
		int edgeColor;
		int edgeValueColor;
	};
	struct DarkMode {
		int backgroundColor = RGB(46, 40, 40);
		int buttonBackgroundColor = RGB(65, 162, 113);
		int buttonLabelColor = RGB(239, 242, 240);
		int buttonBackgroundHoverColor = RGB(21,235,128);
		int buttonLabelHoverColor = RGB(86,88,87);
		int buttonBackgroundActiveColor = RGB(145,103,145);
		int buttonLabelActiveColor = RGB(37,19,37);
		int graphNodeBackgroundColor = RGB(86,159,83);
		int graphNodeLabelColor = RGB(0,0,0);
		int exitBackgroundColor = RGB(186, 35, 65);
		int exitTextColor = RGB(111, 100, 102);
		int sideMenuBackgroundColor = RGB(219,219, 219);
		int sideMenuLabelColor = RGB(0,0,0);
		int additionalInfoColor = RGB(240, 240, 240);
		int errorTitleColor = RGB(171, 24, 51);
		int errorMessageColor = RGB(209, 205, 206);
		int sideMenuActiveBackgroundColor = RGB(0,0,0);
		int sideMenuActiveLabelColor = RGB(256,256,256);
		int sideMenuHoverBackgroundColor = RGB(120, 120, 120);
		int sideMenuHoverLabelColor = RGB(20, 20, 20);
		int edgeColor = RGB(239, 242, 240);
		int edgeValueColor = RGB(200, 180, 200);
	};
	struct LightMode {
		int backgroundColor = RGB(241, 241, 241);
		int buttonBackgroundColor = RGB(65, 162, 113);
		int buttonLabelColor = RGB(239, 242, 240);
		int buttonBackgroundHoverColor = RGB(21, 235, 128);
		int buttonLabelHoverColor = RGB(86, 88, 87);
		int buttonBackgroundActiveColor = RGB(145, 103, 145);
		int buttonLabelActiveColor = RGB(37, 19, 37);
		int graphNodeBackgroundColor = RGB(86, 159, 83);
		int graphNodeLabelColor = RGB(0, 0, 0);
		int exitBackgroundColor = RGB(186, 35, 65);
		int exitTextColor = RGB(111, 100, 102);
		int sideMenuBackgroundColor = RGB(219, 219, 219);
		int sideMenuLabelColor = RGB(0, 0, 0);
		int additionalInfoColor = RGB(20, 20, 20);
		int errorTitleColor = RGB(171, 24, 51);
		int errorMessageColor = RGB(23, 20, 21);
		int sideMenuActiveBackgroundColor = RGB(0, 0, 0);
		int sideMenuActiveLabelColor = RGB(256, 256, 256);
		int sideMenuHoverBackgroundColor = RGB(120, 120, 120);
		int sideMenuHoverLabelColor = RGB(20, 20, 20);
		int edgeColor = RGB(0,0,0);
		int edgeValueColor = RGB(50, 50, 50);
	};
	void changeColorMode(ColorMode colorMode, Pallete&);

	void initColorMode(Pallete&);
};

extern ColorsPallete::Pallete pallete;