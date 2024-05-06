#include "ActionDelete.h"
#include "ApplicationManager.h"
#include ".\GUI\GUI.h"
#include "WinUser.h"
#include <string>
#include <iostream>

ActionDelete::ActionDelete(ApplicationManager* pApp) :Action(pApp)
{}

////////Execute the Action/////////
void ActionDelete::Execute() {
	GUI* pGUI = pManager->GetGUI();
	if (pManager->AnySelected()) {
		int msgBox = MessageBoxW(NULL,
			(LPCWSTR)L"Delete?!\n",
			(LPCWSTR)L"Confirm Delete",
			MB_ICONWARNING | MB_YESNOCANCEL | MB_DEFBUTTON2);
		switch (msgBox)
		{
		case IDYES:
			pGUI->ClearDrawArea();
			pManager->DeleteFig();
			pGUI->ClearStatusBar();
			break;
		case IDCANCEL://case of cnacel or deny the deletion
		case IDNO:
			pGUI->PrintMessage("Delete Operation Cancelled!");
			break;
		}
	}
	else {
		pGUI->PrintMessage("You should select a figure first");
	}

}
