#include".\Actions\Action.h"
#include "ActionPlayShape.h"

#include "ApplicationManager.h"

#include "GUI/GUI.h"


ActionPlayShape::ActionPlayShape(ApplicationManager* pApp) : Action(pApp)
{}

//Execute the action
void ActionPlayShape::Execute()
{
	pManager->restoreHiddenShapes();
	pManager->UpdateInterface();
	string curShape;
	int cntOfShape,correct=0,wrong=0;
	curShape = pManager->getRandomFigure();
	cntOfShape = pManager->getFigureCount(curShape);
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("Game is on!!, please select all " + curShape + "s :) , press enter to start");
	string str = pGUI->GetSrting();
	pGUI->pWind->FlushMouseQueue();

	bool playing = true;
	while (playing)
	{
		Action* newAct = pManager->CreateAction(SELECT);
		pManager->ExecuteAction(newAct);
		if (pGUI->isAction) {
			pGUI->isAction = false;
			break;
		}
		if (!pManager->getSelectedFigCount())
			continue;
		if (pManager->checkFig(curShape))
			correct++;
		else
			wrong++;
		pManager->hideSelectedFig();
		pGUI->ClearDrawArea();
		pManager->UpdateInterface();
		pGUI->PrintMessage("Correct : " + to_string(correct) + ", Wrong : " + to_string(wrong));
		if (correct == cntOfShape)
			playing = false;
	}
	int grade = correct * 100 / max(1, (correct + wrong));
	pGUI->PrintMessage("Correct selections : " + to_string(correct) + " , Incorrect selections : " + to_string(wrong) + ", your grade is " + to_string(grade)+"%");
	
}
ActionPlayShape::~ActionPlayShape() {
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("jnem");
	pManager->restoreHiddenShapes();
}
