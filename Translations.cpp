#include "Translations.h"
void Translations::changeTranslation(Languages lang, Translate& translation) {
	Translations::English en;
	Translations::French fr;
	Translations::Romanian ro;
	switch (lang)
	{
	case Translations::english:
		strcpy(translation.programTitle, en.programTitle);
		strcpy(translation.fileButton, en.fileButton);
		strcpy(translation.inputTitleError, en.inputTitleError);
		strcpy(translation.functionsButton, en.functionsButton);
		strcpy(translation.helpButton, en.helpButton);
		strcpy(translation.preferencesButton, en.preferencesButton);
		strcpy(translation.moreInfoButton, en.moreInfoButton);
		strcpy(translation.addNodeTitle, en.addNodeTitle);
		strcpy(translation.addNodeNodeInList, en.addNodeNodeInList);
		strcpy(translation.addNodeAutoButton, en.addNodeAutoButton);
		strcpy(translation.addNodeInputButton, en.addNodeInputButton);
		strcpy(translation.addNodeInputError, en.addNodeInputError);
		strcpy(translation.addNodeInputLabel, en.addNodeInputLabel);
		strcpy(translation.preferenceTitle, en.preferenceTitle);
		strcpy(translation.darkMode, en.darkMode);
		strcpy(translation.lightMode, en.lightMode);
		strcpy(translation.english, en.english);
		strcpy(translation.french, en.french);
		strcpy(translation.romanian, en.romanian);
		strcpy(translation.visualLabel, en.visualLabel);
		strcpy(translation.languageLabel, en.languageLabel);
		strcpy(translation.outOfWorkZoneClickMessage, en.outOfWorkZoneClickMessage);
		strcpy(translation.outOfWorkZoneClickTitle, en.outOfWorkZoneClickTitle);
		strcpy(translation.notEnoughNodesTitle, en.notEnoughNodesTitle);
		strcpy(translation.notEnoughNodesMessage, en.notEnoughNodesMessage);
		strcpy(translation.clickOnANodeMessage, en.clickOnANodeMessage);
		strcpy(translation.noGraphToDeleteMessage, en.noGraphToDeleteMessage);
		strcpy(translation.noGraphToDeleteTitle, en.noGraphToDeleteTitle);
		strcpy(translation.deleteGraphConfirm, en.deleteGraphConfirm);
		strcpy(translation.deleteGraphMessage, en.deleteGraphMessage);
		strcpy(translation.deleteGraphPopupTitle, en.deleteGraphPopupTitle);
		strcpy(translation.deleteGraphTitle, en.deleteGraphTitle);
		strcpy(translation.addEdgeInputLabel, en.addEdgeInputLabel);
		strcpy(translation.addEdgeInputError, en.addEdgeInputError);
		strcpy(translation.addAutoEdgeInfo, en.addAutoEdgeInfo);
		strcpy(translation.addEdgeTitle, en.addEdgeTitle);
		strcpy(translation.nodeOptionsDelete, en.nodeOptionsDelete);
		strcpy(translation.nodeOptionsMove, en.nodeOptionsMove);
		strcpy(translation.nodeOptionsTitle, en.nodeOptionsTitle);
		strcpy(translation.functionsDfsLabel, en.functionsDfsLabel);
		strcpy(translation.functionsBfsLabel, en.functionsBfsLabel);
		strcpy(translation.functionsBellmanLabel, en.functionsBellmanLabel);
		strcpy(translation.functionsTitle, en.functionsTitle);
		strcpy(translation.notImplementedTitle, en.notImplementedTitle);
		strcpy(translation.notImplementedMessage, en.notImplementedMessage);
		strcpy(translation.fileTitle, en.fileTitle);
		strcpy(translation.fileLoadAll, en.fileLoadAll);
		strcpy(translation.fileLoadGraph, en.fileLoadGraph);
		strcpy(translation.fileLoadPreferences, en.fileLoadPreferences);
		strcpy(translation.fileSave, en.fileSave);
		strcpy(translation.generalExit, en.generalExit);
		strcpy(translation.bfsTitle, en.bfsTitle);
		strcpy(translation.rewatch, en.rewatch);
		strcpy(translation.dfsTitle, en.dfsTitle);

		translation.lang = Translations::english;

		break;
	case Translations::romanian:
		strcpy(translation.programTitle, ro.programTitle);
		strcpy(translation.fileButton, ro.fileButton);
		strcpy(translation.functionsButton, ro.functionsButton);
		strcpy(translation.helpButton, ro.helpButton);
		strcpy(translation.preferencesButton, ro.preferencesButton);
		strcpy(translation.moreInfoButton, ro.moreInfoButton);
		strcpy(translation.addNodeTitle, ro.addNodeTitle);
		strcpy(translation.inputTitleError, ro.inputTitleError);
		strcpy(translation.addNodeAutoButton, ro.addNodeAutoButton);
		strcpy(translation.addNodeInputButton, ro.addNodeInputButton);
		strcpy(translation.addNodeInputError, ro.addNodeInputError);
		strcpy(translation.addNodeInputLabel, ro.addNodeInputLabel);
		strcpy(translation.addNodeNodeInList, ro.addNodeNodeInList);
		strcpy(translation.darkMode, ro.darkMode);
		strcpy(translation.lightMode, ro.lightMode);
		strcpy(translation.english, ro.english);
		strcpy(translation.preferenceTitle, ro.preferenceTitle);
		strcpy(translation.french, ro.french);
		strcpy(translation.romanian, ro.romanian);
		strcpy(translation.visualLabel, ro.visualLabel);
		strcpy(translation.languageLabel, ro.languageLabel);
		strcpy(translation.outOfWorkZoneClickMessage, ro.outOfWorkZoneClickMessage);
		strcpy(translation.outOfWorkZoneClickTitle, ro.outOfWorkZoneClickTitle);
		strcpy(translation.notEnoughNodesTitle, ro.notEnoughNodesTitle);
		strcpy(translation.notEnoughNodesMessage, ro.notEnoughNodesMessage);
		strcpy(translation.clickOnANodeMessage, ro.clickOnANodeMessage);
		strcpy(translation.noGraphToDeleteMessage, ro.noGraphToDeleteMessage);
		strcpy(translation.noGraphToDeleteTitle, ro.noGraphToDeleteTitle);
		strcpy(translation.deleteGraphConfirm, ro.deleteGraphConfirm);
		strcpy(translation.deleteGraphMessage, ro.deleteGraphMessage);
		strcpy(translation.deleteGraphPopupTitle, ro.deleteGraphPopupTitle);
		strcpy(translation.deleteGraphTitle, ro.deleteGraphTitle);
		strcpy(translation.addEdgeInputLabel, ro.addEdgeInputLabel);
		strcpy(translation.addEdgeInputError, ro.addEdgeInputError);
		strcpy(translation.addAutoEdgeInfo, ro.addAutoEdgeInfo);
		strcpy(translation.addEdgeTitle, ro.addEdgeTitle);
		strcpy(translation.nodeOptionsDelete, ro.nodeOptionsDelete);
		strcpy(translation.nodeOptionsMove, ro.nodeOptionsMove);
		strcpy(translation.nodeOptionsTitle, ro.nodeOptionsTitle);
		strcpy(translation.functionsDfsLabel, ro.functionsDfsLabel);
		strcpy(translation.functionsBfsLabel, ro.functionsBfsLabel);
		strcpy(translation.functionsBellmanLabel, ro.functionsBellmanLabel);
		strcpy(translation.functionsTitle, ro.functionsTitle);
		strcpy(translation.notImplementedTitle, ro.notImplementedTitle);
		strcpy(translation.notImplementedMessage, ro.notImplementedMessage);
		strcpy(translation.fileTitle, ro.fileTitle);
		strcpy(translation.fileLoadAll, ro.fileLoadAll);
		strcpy(translation.fileLoadGraph, ro.fileLoadGraph);
		strcpy(translation.fileLoadPreferences, ro.fileLoadPreferences);
		strcpy(translation.fileSave, ro.fileSave);
		strcpy(translation.generalExit, ro.generalExit);
		strcpy(translation.bfsTitle, ro.bfsTitle);
		strcpy(translation.rewatch, ro.rewatch);
		strcpy(translation.dfsTitle, ro.dfsTitle);
		translation.lang = Translations::romanian;

		break;
	case Translations::french:
		strcpy(translation.programTitle, fr.programTitle);
		strcpy(translation.fileButton, fr.fileButton);
		strcpy(translation.functionsButton, fr.functionsButton);
		strcpy(translation.helpButton, fr.helpButton);
		strcpy(translation.inputTitleError, fr.inputTitleError);
		strcpy(translation.preferencesButton, fr.preferencesButton);
		strcpy(translation.moreInfoButton, fr.moreInfoButton);
		strcpy(translation.addNodeTitle, fr.addNodeTitle);
		strcpy(translation.addNodeNodeInList, fr.addNodeNodeInList);
		strcpy(translation.addNodeAutoButton, fr.addNodeAutoButton);
		strcpy(translation.addNodeInputButton, fr.addNodeInputButton);
		strcpy(translation.addNodeInputError, fr.addNodeInputError);
		strcpy(translation.addNodeInputLabel, fr.addNodeInputLabel);
		strcpy(translation.darkMode, fr.darkMode);
		strcpy(translation.lightMode, fr.lightMode);
		strcpy(translation.english, fr.english);
		strcpy(translation.preferenceTitle, fr.preferenceTitle);
		strcpy(translation.french, fr.french);
		strcpy(translation.romanian, fr.romanian);
		strcpy(translation.visualLabel, fr.visualLabel);
		strcpy(translation.languageLabel, fr.languageLabel);
		strcpy(translation.outOfWorkZoneClickMessage, fr.outOfWorkZoneClickMessage);
		strcpy(translation.outOfWorkZoneClickTitle, fr.outOfWorkZoneClickTitle);
		strcpy(translation.notEnoughNodesTitle, fr.notEnoughNodesTitle);
		strcpy(translation.notEnoughNodesMessage, fr.notEnoughNodesMessage);
		strcpy(translation.clickOnANodeMessage, fr.clickOnANodeMessage);
		strcpy(translation.noGraphToDeleteMessage, fr.noGraphToDeleteMessage);
		strcpy(translation.noGraphToDeleteTitle, fr.noGraphToDeleteTitle);
		strcpy(translation.deleteGraphConfirm, fr.deleteGraphConfirm);
		strcpy(translation.deleteGraphMessage, fr.deleteGraphMessage);
		strcpy(translation.deleteGraphPopupTitle, fr.deleteGraphPopupTitle);
		strcpy(translation.deleteGraphTitle, fr.deleteGraphTitle);
		strcpy(translation.addEdgeInputLabel, fr.addEdgeInputLabel);
		strcpy(translation.addEdgeInputError, fr.addEdgeInputError);
		strcpy(translation.addAutoEdgeInfo, fr.addAutoEdgeInfo);
		strcpy(translation.addEdgeTitle, fr.addEdgeTitle);
		strcpy(translation.nodeOptionsDelete, fr.nodeOptionsDelete);
		strcpy(translation.nodeOptionsMove, fr.nodeOptionsMove);
		strcpy(translation.nodeOptionsTitle, fr.nodeOptionsTitle);
		strcpy(translation.functionsDfsLabel, fr.functionsDfsLabel);
		strcpy(translation.functionsBfsLabel, fr.functionsBfsLabel);
		strcpy(translation.functionsBellmanLabel, fr.functionsBellmanLabel);
		strcpy(translation.functionsTitle, fr.functionsTitle);
		strcpy(translation.notImplementedTitle, fr.notImplementedTitle);
		strcpy(translation.notImplementedMessage, fr.notImplementedMessage);
		strcpy(translation.fileTitle, fr.fileTitle);
		strcpy(translation.fileLoadAll, fr.fileLoadAll);
		strcpy(translation.fileLoadGraph, fr.fileLoadGraph);
		strcpy(translation.fileLoadPreferences, fr.fileLoadPreferences);
		strcpy(translation.fileSave, fr.fileSave);
		strcpy(translation.generalExit, fr.generalExit);
		strcpy(translation.bfsTitle, fr.bfsTitle);
		strcpy(translation.rewatch, fr.rewatch);
		strcpy(translation.dfsTitle, fr.dfsTitle);
		translation.lang = Translations::french;

		break;
	default:
		break;
	}
}
void Translations::initTranslation(Translate& trans) {
	changeTranslation(english, trans);
}