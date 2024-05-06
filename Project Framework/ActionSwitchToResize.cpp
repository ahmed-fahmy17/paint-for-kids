#include "ActionSwitchToResize.h"

#include "ApplicationManager.h"


#include ".\GUI\GUI.h"

ActionSwitchToResize::ActionSwitchToResize(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionSwitchToResize::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	pGUI->ClearToolBar();
	pGUI->CreateResizeToolBar();
}
