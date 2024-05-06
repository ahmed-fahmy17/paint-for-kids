#include ".\ActionSave.h"
#include ".\ApplicationManager.h"
#include".\GUI\GUI.h"
#include<string>
#include"fstream"
ActionSave::ActionSave(ApplicationManager* pApp) :Action(pApp) {}

void ActionSave::Execute() {
	ofstream of;
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("enter the file name");
	string fileName = pGUI->GetSrting();
	of.open("saved/" + fileName + ".txt");
	if (of.is_open()) {
		of << to_string(UI.DrawColor.ucRed) << ' ' << to_string(UI.DrawColor.ucGreen) << ' ' << to_string(UI.DrawColor.ucBlue) << ' '
			<< to_string(UI.FillColor.ucRed) << ' ' << to_string(UI.FillColor.ucGreen) << ' ' << to_string(UI.FillColor.ucBlue) << ' '
			<< to_string(UI.BkGrndColor.ucRed) << ' ' << to_string(UI.BkGrndColor.ucGreen) << ' ' << to_string(UI.BkGrndColor.ucBlue) << endl;
		of << to_string(pManager->getFigCount())<<endl;
		pManager->saveAll(of);
		of.close();
		pGUI->PrintMessage("file has been saved successfully :)");
	}
}