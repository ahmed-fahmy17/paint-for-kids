#include"ApplicationManager.h"
#include"Actions/Action.h"
#include"ActionLoad.h"
#include".\GUI\GUI.h"
#include"Figures/CSquare.h"
#include"CEllipse.h"
#include"CHexagon.h"
#include"fstream"

ActionLoad::ActionLoad(ApplicationManager* pApp) :Action(pApp) {}

void ActionLoad::Execute() {
	ifstream f;
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("enter the file name");
	string fileName = pGUI->GetSrting();
	f.open("saved/" + fileName + ".txt");
	if (f.is_open()) {
		GUI* pGUI = pManager->GetGUI();
		pManager->reset();
		pGUI->ClearDrawArea();
		pGUI->ClearStatusBar();
		string red, green, blue, numOfFigures,figType;
		f >> red >> green >> blue;
		UI.DrawColor = color(stoi(red), stoi(green), stoi(blue));
		f >> red >> green >> blue;
		UI.FillColor = color(stoi(red), stoi(green), stoi(blue));
		f >> red >> green >> blue;
		UI.BkGrndColor = color(stoi(red), stoi(green), stoi(blue));
		f >> numOfFigures;
		for (int i = 0; i < stoi(numOfFigures); i++) {
			f >> figType;
			if (figType == "SQR") {
				CFigure* r = new CSquare;
				r->Load(f);
				pManager->AddFigure(r);
			}
			else if (figType == "ELLIPSE") {
				CFigure* r = new CEllipse;
				r->Load(f);
				pManager->AddFigure(r);
			}
			else {
				CFigure* r = new Chexagon;
				r->Load(f);
				pManager->AddFigure(r);
			}

		}
		f.close();
	}
	else
		pGUI->PrintMessage("there's no such file");

}