#include "ActionAddHexagon.h"
#include"Chexagon.h"
#include ".\ApplicationManager.h"

#include ".\GUI\GUI.h"

ActionAddHexagon::ActionAddHexagon(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddHexagon::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo HexaGfxInfo;
	HexaGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexaGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	HexaGfxInfo.FillClr = pGUI->getCrntFillColor();
	HexaGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Hexagon data from the user

	pGUI->PrintMessage("New Hexagon: Click at first point");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->PrintMessage("New Hexagon: Click at second point");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);

	pGUI->ClearStatusBar();


	//Step 2 - prepare Hexagon data
	//User has entered two points P1&P2
	//2.1- Identify the Top left corner of the Hexagon
	Point topLeft;
	topLeft.x = P1.x < P2.x ? P1.x : P2.x;
	topLeft.y = P1.y < P2.y ? P1.y : P2.y;

	//2.2- Calcuate Hexagon side legnth
	int SideLength = max(abs(P1.x - P2.x), abs(P1.y - P2.y));
	double hieght = SideLength * 1.732;

	if (topLeft.y <= UI.ToolBarHeight || topLeft.y >= UI.height - UI.StatusBarHeight ||topLeft.x + 1.5 * SideLength > UI.width || topLeft.x - 0.5 * SideLength < 0 || topLeft.y+hieght> UI.height - UI.StatusBarHeight) {
		pGUI->PrintMessage("HEXAGON IS OUTSIDE DRAWING AREA");
		return;
	}
	//Step 3 - Create a Hexagon with the parameters read from the user
	Chexagon* H = new Chexagon(topLeft, SideLength, HexaGfxInfo);

	//Step 4 - Add the Hexagon to the list of figures
	pManager->AddFigure(H);
}