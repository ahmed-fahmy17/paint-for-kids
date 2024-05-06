#include "ActionExit.h"
#include ".\ApplicationManager.h"
#include".\GUI\GUI.h"
ActionExit::ActionExit(ApplicationManager* pApp) :Action(pApp) {}

void ActionExit::Execute() {
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("press 'y' to save the current graph bfore exit or any other key to just exit");
	string msg = pGUI->GetSrting();
	if (msg == "y" || msg == "Y") {
		Action* pAct = pManager->CreateAction(SAVE);
		pManager->ExecuteAction(pAct);
	}
}