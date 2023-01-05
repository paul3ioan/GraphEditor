#include "ColorsPallete.h"

void ColorsPallete::changeColorMode(ColorMode mode, Pallete& pall) {
	ColorsPallete::DarkMode dark;
	ColorsPallete::LightMode light;

	switch (mode)
	{
	case ColorMode::darkMode:
		pall.backgroundColor = dark.backgroundColor;
		pall.graphNodeHighlight = dark.graphNodeHighlight;
		pall.edgeHighlight = dark.edgeHighlight;
		pall.buttonBackgroundColor = dark.buttonBackgroundColor;
		pall.buttonLabelColor = dark.buttonLabelColor;
		pall.buttonBackgroundHoverColor = dark.buttonBackgroundHoverColor;
		pall.buttonLabelHoverColor = dark.buttonLabelHoverColor;
		pall.buttonBackgroundActiveColor = dark.buttonBackgroundActiveColor;
		pall.buttonLabelActiveColor = dark.buttonLabelActiveColor;
		pall.graphNodeBackgroundColor = dark.graphNodeBackgroundColor;
		pall.graphNodeLabelColor = dark.graphNodeLabelColor;
		pall.exitBackgroundColor = dark.exitBackgroundColor;
		pall.exitTextColor = dark.exitTextColor;
		pall.sideMenuActiveBackgroundColor = dark.sideMenuActiveBackgroundColor;
		pall.sideMenuActiveLabelColor = dark.sideMenuActiveLabelColor;
		pall.sideMenuHoverBackgroundColor = dark.sideMenuHoverBackgroundColor;
		pall.sideMenuBackgroundColor = dark.sideMenuBackgroundColor;
		pall.sideMenuLabelColor = dark.sideMenuLabelColor;
		pall.sideMenuHoverLabelColor = dark.sideMenuHoverLabelColor;
		pall.additionalInfoColor = dark.additionalInfoColor;
		pall.errorMessageColor = dark.errorMessageColor;
		pall.errorTitleColor = dark.errorTitleColor;
		pall.edgeColor = dark.edgeColor;
		pall.edgeValueColor = dark.edgeValueColor;
		pall.mode = ColorMode::darkMode;

		break;
	case ColorMode::lightMode:
		pall.graphNodeHighlight = light.graphNodeHighlight;
		pall.edgeHighlight = light.edgeHighlight;
		pall.backgroundColor = light.backgroundColor;
		pall.buttonBackgroundColor = light.buttonBackgroundColor;
		pall.buttonLabelColor = light.buttonLabelColor;
		pall.buttonBackgroundHoverColor = light.buttonBackgroundHoverColor;
		pall.buttonLabelHoverColor = light.buttonLabelHoverColor;
		pall.buttonBackgroundActiveColor = light.buttonBackgroundActiveColor;
		pall.buttonLabelActiveColor = light.buttonLabelActiveColor;
		pall.graphNodeBackgroundColor = light.graphNodeBackgroundColor;
		pall.graphNodeLabelColor = light.graphNodeLabelColor;
		pall.exitBackgroundColor = light.exitBackgroundColor;
		pall.exitTextColor = light.exitTextColor;
		pall.sideMenuActiveBackgroundColor = light.sideMenuActiveBackgroundColor;
		pall.sideMenuActiveLabelColor = light.sideMenuActiveLabelColor;
		pall.sideMenuHoverBackgroundColor = light.sideMenuHoverBackgroundColor;
		pall.sideMenuHoverLabelColor = light.sideMenuHoverLabelColor;
		pall.sideMenuBackgroundColor = light.sideMenuBackgroundColor;
		pall.sideMenuLabelColor = light.sideMenuLabelColor;
		pall.additionalInfoColor = light.additionalInfoColor;
		pall.errorMessageColor = light.errorMessageColor;
		pall.errorTitleColor = light.errorTitleColor;
		pall.edgeValueColor = light.edgeValueColor;
		pall.edgeColor = light.edgeColor;
		pall.mode = ColorMode::lightMode;
		break;
	default:
		break;
	}
}
void ColorsPallete::initColorMode(Pallete& pall) {
	changeColorMode(darkMode, pall);
}