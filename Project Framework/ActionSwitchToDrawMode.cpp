#include "ActionSwitchToDrawMode.h"

#include "ApplicationManager.h"


#include ".\GUI\GUI.h"

ActionSwitchToDrawMode::ActionSwitchToDrawMode(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionSwitchToDrawMode::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	pGUI->ClearToolBar();
	pGUI->CreateDrawToolBar();
	pManager->restoreHiddenShapes();
}
