#include "ActionChangeDrawColor.h"

#include "ApplicationManager.h"

#include ".\Figures\CFigure.h"

#include"ActionSelect.h"

#include "GUI/GUI.h"


ActionChangeDrawColor::ActionChangeDrawColor(ApplicationManager* pApp) : Action(pApp)
{}

//Execute the action
void ActionChangeDrawColor::Execute()
{
	Point P1;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo SqrGfxInfo;


	pGUI->PrintMessage("Choose a new border color from the palette");
	pGUI->GetPointClicked(P1.x, P1.y);
	if (P1.y < UI.ToolBarHeight && (P1.x / UI.MenuItemWidth) == 8) {
		if (pManager->getSelectedFigCount()) {
			pManager->changeDrawColorForSelected(pGUI->pWind->GetColor(P1.x, P1.y));
			pGUI->ClearStatusBar();
		}
		else {
			UI.DrawColor = pGUI->pWind->GetColor(P1.x, P1.y);
			pGUI->ClearStatusBar();
		}
	}
	else {
		pGUI->PrintMessage("Choosed from outside palette, no color Changed");
	}

}
