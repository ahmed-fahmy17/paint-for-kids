#include ".\ActionSendToFront.h"
#include "ApplicationManager.h"
#include ".\GUI\GUI.h"
#include <math.h>


ActionSendToFront::ActionSendToFront(ApplicationManager* pApp) :Action(pApp)
{
}

void ActionSendToFront::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	if (pManager->getSelectedFigCount() != 1)
		pGUI->PrintMessage("you should select exactly one figure");
	else {
		pManager->sendToFront();
	}

}