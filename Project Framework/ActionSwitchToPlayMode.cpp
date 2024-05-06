#include "ActionSwitchToPlayMode.h"

#include "ApplicationManager.h"


#include ".\GUI\GUI.h"

ActionSwitchToPlayMode::ActionSwitchToPlayMode(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionSwitchToPlayMode::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	if (!pManager->getFigCount()) {
		pGUI->PrintMessage("Draw at least one figure!");
		return;
	}
	pGUI->ClearToolBar();
	pGUI->CreatePlayToolBar();
	pManager->RemoveAllSelectedFigures();
}
