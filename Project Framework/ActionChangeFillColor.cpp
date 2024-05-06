#include "ActionChangeFillColor.h"

#include "ApplicationManager.h"

#include ".\Figures\CSquare.h"

#include "GUI/GUI.h"


ActionChangeFillColor::ActionChangeFillColor(ApplicationManager* pApp) : Action(pApp)
{}

//Execute the action
void ActionChangeFillColor::Execute()
{
	Point P1;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo SqrGfxInfo;

	pGUI->PrintMessage("Choose a new filling color from the palette");
	pGUI->GetPointClicked(P1.x, P1.y);
	if (P1.y < UI.ToolBarHeight && (P1.x / UI.MenuItemWidth) == 8) {
		color newColor = pGUI->pWind->GetColor(P1.x, P1.y);

		if (pManager->getSelectedFigCount()) {
			pGUI->PrintMessage("selected");
			pManager->changeFillColorForSelected(newColor);
		}
		
		
	}
	else {
		pGUI->PrintMessage("Choosed from outside palette, no color Changed");
	}
}
