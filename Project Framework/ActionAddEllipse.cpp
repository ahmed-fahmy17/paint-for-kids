#include "ActionAddEllipse.h"
#include "CEllipse.h"

#include ".\ApplicationManager.h"

#include ".\GUI\GUI.h"

ActionAddEllipse::ActionAddEllipse(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddEllipse::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo EllipseGfxInfo;
	EllipseGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	EllipseGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	EllipseGfxInfo.FillClr = pGUI->getCrntFillColor();
	EllipseGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Ellipse data from the user

	pGUI->PrintMessage("New Ellipse: Click at first point");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->PrintMessage("New Ellipse: Click at second point");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);

	pGUI->ClearStatusBar();


	//Step 2 - prepare Ellipse data
	//User has entered two points P1&P2
	//2.1- Identify the Top left corner of the square
	Point topLeft;
	topLeft.x = P1.x < P2.x ? P1.x : P2.x;
	topLeft.y = P1.y < P2.y ? P1.y : P2.y;
	Point bottomRight;
	bottomRight.x = P1.x> P2.x ? P1.x : P2.x;
	bottomRight.y = P1.y > P2.y ? P1.y : P2.y;

	//Step 3 - Create a Ellipse with the parameters read from the user
	if (topLeft.y <= UI.ToolBarHeight || topLeft.y >= UI.height - UI.StatusBarHeight || bottomRight.y <= UI.ToolBarHeight || bottomRight.y >= UI.height - UI.StatusBarHeight) {
		pGUI->PrintMessage("ELLIPSE IS OUTSIDE DRAWING AREA");
		return;
	}
	CEllipse* R = new CEllipse(topLeft, bottomRight, EllipseGfxInfo);

	//Step 4 - Add the Ellipse to the list of figures
	pManager->AddFigure(R);
}
