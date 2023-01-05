#pragma once
#include <cstring>
namespace Translations
{
	struct English {
		char* programTitle = "Graph editor";
		char* fileButton = "File";
		char* functionsButton = "Functions";
		char* helpButton = "Help";
		char* preferencesButton = "Preferences";
		char* moreInfoButton = "More Info";

		char* addNodeTitle = "Add node options";
		char* addNodeAutoButton = "Add auto";
		char* addNodeInputButton = "Input";
		char* addNodeInputLabel = "Please input node value";
		char* addNodeInputError = "Please input a number from 1 to 100";
		
		char* preferenceTitle = "Preference";
		char* romanian = "Romanian";
		char* english = "English";
		char* french = "French";
		char* lightMode = "Light mode";
		char* darkMode = "Dark mode";
		char* languageLabel = "Change language";
		char* visualLabel = "Change visual mode";

		char* inputTitleError = "Input error";
		char* addNodeNodeInList = "The number is already on a node or number is not from 1 to 100";

		char* outOfWorkZoneClickTitle = "Click error";
		char* outOfWorkZoneClickMessage = "Click must be inside of the working zone";
		char* clickOnANodeMessage = "Click should not be on a existing node";
		char* notEnoughNodesTitle = "Logic error";
		char* notEnoughNodesMessage = "You must have at least 2 nodes to draw a edge";
		char* noGraphToDeleteTitle = "Graph empty";
		char* noGraphToDeleteMessage = "No graph to be deleted";

		char* deleteGraphPopupTitle = "Graph delete";
		char* deleteGraphTitle = "Delete graph";
		char* deleteGraphMessage = "Are you sure you want to delete the graph?";
		char* deleteGraphConfirm = "Confirm";

		char* addEdgeInputLabel = "Insert the value of the edge";
		char* addEdgeInputError = "Value must be from 1 to 100";
		char* addAutoEdgeInfo = "It will add a random value from 1 to 100";
		char* addEdgeTitle = "Add edge";

		char* nodeOptionsTitle = "Node options";
		char* nodeOptionsDelete = "Delete node";
		char* nodeOptionsMove = "Move node";

		char* functionsDfsLabel = "DFS";
		char* functionsBfsLabel = "BFS";
		char* functionsBellmanLabel = "Bellman";
		char* functionsTitle = "Functions";

		char* notImplementedTitle = "Not implemented";
		char* notImplementedMessage = "Sorry feature is not implemented";
		char* generalExit = "Exit";
	};
	struct French {
		char* programTitle = "[FR] Graph editor";
		char* fileButton = "[FR] File";
		char* functionsButton = "[FR] Functions";
		char* helpButton = "[FR] Help";
		char* preferencesButton = "[FR] Preferences";
		char* moreInfoButton = "[FR] More Info";

		char* addNodeTitle = "[FR] Add node options";
		char* addNodeAutoButton = "[FR] Add auto";
		char* addNodeInputButton = "[FR] Input";
		char* addNodeInputLabel = "[FR] Please input node value";
		char* addNodeInputError = "[FR] Please input a number from 1 to 100";

		char* preferenceTitle = "[FR] Preference";
		char* romanian = "[FR] Romanian";
		char* english = "[FR] English";
		char* french = "[FR] French";
		char* lightMode = "[FR] Light mode";
		char* darkMode = "[FR] Dark mode";
		char* languageLabel = "[FR] Change language";
		char* visualLabel = "[FR] Change visual mode";

		char* inputTitleError = "[FR] Input error";
		char* addNodeNodeInList = "[FR] The number is already on a node or number is not from 1 to 100";

		char* outOfWorkZoneClickTitle = "[FR] Click error";
		char* outOfWorkZoneClickMessage = "[FR] Click must be inside of the working zone";
		char* clickOnANodeMessage = "[FR] Click should not be on a existing node";
		char* notEnoughNodesTitle = "[FR] Logic error";
		char* notEnoughNodesMessage = "[FR] You must have at least 2 nodes to draw a edge";
		char* noGraphToDeleteTitle = "[FR] Graph empty";
		char* noGraphToDeleteMessage = "[FR] No graph to be deleted";

		char* deleteGraphPopupTitle = "[FR] Graph delete";
		char* deleteGraphTitle = "[FR] Delete graph";
		char* deleteGraphMessage = "[FR] Are you sure you want to delete the graph?";
		char* deleteGraphConfirm = "[FR] Confirm";

		char* addEdgeInputLabel = "[FR] Insert the value of the edge";
		char* addEdgeInputError = "[FR] Value must be from 1 to 100";
		char* addAutoEdgeInfo = "[FR] It will add a random value from 1 to 100";
		char* addEdgeTitle = "[FR] Add edge";

		char* nodeOptionsTitle = "[FR] Node options";
		char* nodeOptionsDelete = "[FR] Delete node";
		char* nodeOptionsMove = "[FR] Move node";

		char* functionsDfsLabel = "[FR] DFS";
		char* functionsBfsLabel = "[FR] BFS";
		char* functionsBellmanLabel = "[FR] Bellman";
		char* functionsTitle = "[FR] Functions";

		char* notImplementedTitle = "[FR] Not implemented";
		char* notImplementedMessage = "[FR] Sorry feature is not implemented";
		char* generalExit = "[FR] Exit";
	};
	struct Romanian {
		char* programTitle = "[RO] Graph editor";
		char* fileButton = "[RO] File";
		char* functionsButton = "[RO] Functions";
		char* helpButton = "[RO] Help";
		char* preferencesButton = "[RO] Preferences";
		char* moreInfoButton = "[RO] More Info";

		char* addNodeTitle = "[RO] Add node options";
		char* addNodeAutoButton = "[RO] Add auto";
		char* addNodeInputButton = "[RO] Input";
		char* addNodeInputLabel = "[RO] Please input node value";
		char* addNodeInputError = "[RO] Please input a number from 1 to 100";

		char* preferenceTitle = "[RO] Preference";
		char* romanian = "[RO] Romanian";
		char* english = "[RO] English";
		char* french = "[RO] French";
		char* lightMode = "[RO] Light mode";
		char* darkMode = "[RO] Dark mode";
		char* languageLabel = "[RO] Change language";
		char* visualLabel = "[RO] Change visual mode";

		char* outOfWorkZoneClickTitle = "[RO] Click error";
		char* outOfWorkZoneClickMessage = "[RO] Click must be inside of the working zone";
		char* inputTitleError = "[RO] Input error";
		char* addNodeNodeInList = "[RO] The number is already on a node or number is not from 1 to 100";
		char* clickOnANodeMessage = "[RO] Click should not be on a existing node";
		char* notEnoughNodesTitle = "[RO] Logic error";
		char* notEnoughNodesMessage = "[RO] You must have at least 2 nodes to draw a edge";
		char* noGraphToDeleteTitle = "[RO] Graph empty";
		char* noGraphToDeleteMessage = "[RO] No graph to be deleted";

		char* deleteGraphPopupTitle = "[RO] Graph delete";
		char* deleteGraphTitle = "[RO] Delete graph";
		char* deleteGraphMessage = "[RO] Are you sure you want to delete the graph?";
		char* deleteGraphConfirm = "[RO] Confirm";

		char* addEdgeInputLabel = "[RO] Insert the value of the edge";
		char* addEdgeInputError = "[RO] Value must be from 1 to 100";
		char* addAutoEdgeInfo = "[RO] It will add a random value from 1 to 100";
		char* addEdgeTitle = "[RO] Add edge";

		char* nodeOptionsTitle = "[RO] Node options";
		char* nodeOptionsDelete = "[RO] Delete node";
		char* nodeOptionsMove = "[RO] Move node";

		char* functionsDfsLabel = "[RO] DFS";
		char* functionsBfsLabel = "[RO] BFS";
		char* functionsBellmanLabel = "[RO] Bellman";
		char* functionsTitle = "[RO] Functions";

		char* generalExit = "[RO] Exit";
		char* notImplementedTitle = "[RO] Not implemented";
		char* notImplementedMessage = "[RO] Sorry feature is not implemented";
	};
	enum Languages {
		english,
		romanian,
		french,
	};
	struct Translate {
		char programTitle[100];
		char fileButton[100];
		char functionsButton[100];
		char helpButton[100];
		char preferencesButton[100];
		char moreInfoButton[100];

		char addNodeTitle[100];
		char addNodeAutoButton[100];
		char addNodeInputButton[100];
		char addNodeInputLabel[100];
		char addNodeInputError[100];

		char preferenceTitle[100];
		char romanian[100];
		char french[100];
		char english[100];
		char darkMode[100];
		char lightMode[100];
		char languageLabel[100];
		char visualLabel[100];

		char inputTitleError[100];
		char addNodeNodeInList[100];

		char outOfWorkZoneClickTitle[100];
		char outOfWorkZoneClickMessage[100];
		char clickOnANodeMessage[100];
		char notEnoughNodesTitle[100];
		char notEnoughNodesMessage[100];
		char noGraphToDeleteTitle[100];
		char noGraphToDeleteMessage[100];

		char deleteGraphPopupTitle[100];
		char deleteGraphTitle[100];
		char deleteGraphMessage[100];
		char deleteGraphConfirm[100];

		char addEdgeInputLabel[100];
		char addEdgeInputError[100];
		char addAutoEdgeInfo[100];
		char addEdgeTitle[100];

		char nodeOptionsTitle[100];
		char nodeOptionsDelete[100];
		char nodeOptionsMove[100];

		char functionsDfsLabel[100];
		char functionsBfsLabel[100];
		char functionsBellmanLabel[100];
		char functionsTitle[100];

		char notImplementedTitle[100];
		char notImplementedMessage[100];
		char generalExit[100];
	};
	void changeTranslation(Languages lang, Translate&);

	void initTranslation(Translate&);
}	
extern Translations::Translate translations;