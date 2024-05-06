#include".\Actions\Action.h"
#include "ActionPlayColor.h"

#include "ApplicationManager.h"

#include "GUI/GUI.h"


ActionPlayColor::ActionPlayColor(ApplicationManager* pApp) : Action(pApp)
{}

//Execute the action
void ActionPlayColor::Execute()
{
	pManager->restoreHiddenShapes();
	pManager->UpdateInterface();
	color curColor;
	int cntOfShape, correct = 0, wrong = 0;
	curColor = pManager->getRandomColor();
	cntOfShape = pManager->getColorCount(curColor);
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("Game is on!!, please select all filled shapes with this color , press enter to start", curColor);
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
		if (pManager->checkColor(curColor))
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
