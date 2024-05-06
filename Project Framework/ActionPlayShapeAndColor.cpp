#include".\Actions\Action.h"
#include "ActionPlayShapeAndColor.h"

#include "ApplicationManager.h"

#include "GUI/GUI.h"


ActionPlayShapeAndColor::ActionPlayShapeAndColor(ApplicationManager* pApp) : Action(pApp)
{}

//Execute the action
void ActionPlayShapeAndColor::Execute()
{
	pManager->restoreHiddenShapes();
	pManager->UpdateInterface();
	int cntOfShape, correct = 0, wrong = 0;
	pair<string, color>p = pManager->getRandomShapeColor();
	cntOfShape = pManager->getShapeColorCount(p);
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("Game is on!!, please select all"+p.first+" with fill color with this color , press enter to start", p.second);
	string str = pGUI->GetSrting();
	pGUI->pWind->FlushMouseQueue();
	bool playing = true;

	while (playing)
	{
		Action* newAct = pManager->CreateAction(SELECT);
		pManager->ExecuteAction(newAct);
		delete newAct;
		newAct = NULL;
		if (pGUI->isAction) {
			pGUI->isAction = false;
			break;
		}
		if (!pManager->getSelectedFigCount())
			continue;
		if (pManager->checkShapeColor(p))
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
	pGUI->PrintMessage("Correct selections : " + to_string(correct) + " , Incorrect selections : " + to_string(wrong) + ", your grade is " + to_string(grade) + "%");

}
