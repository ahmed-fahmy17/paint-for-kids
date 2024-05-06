#include "ActionChangeBKGColor.h"

#include "ApplicationManager.h"

#include "GUI/GUI.h"


ActionChangeBKGColor::ActionChangeBKGColor(ApplicationManager* pApp) : Action(pApp)
{}

//Execute the action
void ActionChangeBKGColor::Execute()
{
	Point P1;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo SqrGfxInfo;


	pGUI->PrintMessage("Choose a new BKG color from the palette");
	pGUI->GetPointClicked(P1.x, P1.y);
	if (P1.y < UI.ToolBarHeight && (P1.x / UI.MenuItemWidth) == 8) {
		UI.BkGrndColor = pGUI->pWind->GetColor(P1.x, P1.y);
		pGUI->ClearDrawArea();
	}
	pGUI->ClearStatusBar();

}
