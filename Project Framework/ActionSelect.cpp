#include ".\ActionSelect.h"
#include "ApplicationManager.h"
#include ".\GUI\GUI.h"
#include <math.h>


ActionSelect::ActionSelect(ApplicationManager* pApp) :Action(pApp)
{
}

void ActionSelect::Execute()
{
	Point P1;

	GUI* pGUI = pManager->GetGUI();

	if (UI.InterfaceMode == MODE_DRAW) {
		do {
			pGUI->PrintMessage("Click on any shape to select or unselect and click on the select icon in the toolbar to exit select mode");
			pGUI->GetPointClicked(P1.x, P1.y);
			pGUI->ClearStatusBar();


			//Get a Pointer to the selected figure

			CFigure* r = pManager->GetFigure(P1.x, P1.y);

			if (r)
			{
				r->SetSelected(!r->IsSelected());

				if (r->IsSelected())
				{
					pManager->AddSelectedFigure(r);
					pGUI->PrintMessage(r->PrintInfo());
				}
				else {
					pManager->RemoveSelectedFigure(r);
				}

			}
			else if (P1.y >= 0 && P1.y < UI.ToolBarHeight && (P1.x / UI.MenuItemWidth) == ITM_SLCT)
				break;
			pGUI->ClearDrawArea();
			pManager->UpdateInterface();
		} while (true);
	}
	else {
		//pGUI->PrintMessage("Click on the required shapes");
		pGUI->GetPointClicked(P1.x, P1.y);
		pGUI->ClearStatusBar();


		//Get a Pointer to the selected figure

		CFigure* r = pManager->GetFigure(P1.x, P1.y);

		if (r)
		{

			r->SetSelected(!r->IsSelected());

			if (r->IsSelected())
			{
				pManager->AddSelectedFigure(r);
				pGUI->PrintMessage(r->PrintInfo());
			}
			else {
				pManager->RemoveSelectedFigure(r);
			}

		}
		else {
			//EMPTY DRAWING_AREA STATUS
			ActionType ActType = pGUI->MapInputToActionType(true, P1.x, P1.y);
			if (!(ActType == EMPTY || ActType == DRAWING_AREA || ActType == STATUS))
				pGUI->isAction = true;

		}
	}

}