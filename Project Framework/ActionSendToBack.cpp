#include ".\ActionSendToBack.h"
#include "ApplicationManager.h"
#include ".\GUI\GUI.h"
#include <math.h>


ActionSendToBack::ActionSendToBack(ApplicationManager* pApp) :Action(pApp)
{
}

void ActionSendToBack::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	if (pManager->getSelectedFigCount() != 1)
		pGUI->PrintMessage("you should select exactly one figure");
	else {
		pManager->sendToBack();
	}

}