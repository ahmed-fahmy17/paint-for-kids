#include "ApplicationManager.h"
#include "Actions\ActionAddSquare.h"
#include".\GUI\GUI.h"
#include ".\ActionSave.h"
#include".\ActionLoad.h"
#include"ActionSelect.h"
#include"ActionDelete.h"
#include"ActionChangeDrawColor.h"
#include"ActionChangeBKGColor.h"
#include"ActionChangeFillColor.h"
#include"ActionAddEllipse.h"
#include"ActionAddHexagon.h"
#include"ActionSendToBack.h"
#include"ActionSendToFront.h"
#include"ActionSwitchToPlayMode.h"
#include"ActionSwitchToResize.h"
#include"ActionSwitchToDrawMode.h"
#include"ActionResize.h"
#include"ActionExit.h"
#include"ActionPlayShape.h"
#include"ActionPlayColor.h"
#include"ActionPlayShapeAndColor.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pGUI = new GUI;	
	
	FigCount = 0;
	selectefFigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;
}

void ApplicationManager::Run()
{
	ActionType ActType;
	do
	{		
		//1- Read user action
		ActType = pGUI->MapInputToActionType(false, 0, 0);

		//2- Create the corresponding Action
		Action *pAct = CreateAction(ActType);
		
		//3- Execute the action
		ExecuteAction(pAct);

		pGUI->ClearDrawArea();
		//4- Update the interface
		UpdateInterface();

	}while(ActType != EXIT);
	
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
//Creates an action
Action* ApplicationManager::CreateAction(ActionType ActType) 
{
	Action* newAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_SQUARE:
			newAct = new ActionAddSquare(this);
			break;
		case DRAW_ELPS:
			newAct = new ActionAddEllipse(this);
			break;
		case DRAW_HEX:
			newAct = new ActionAddHexagon(this);
			break;
		case SELECT:
			newAct = new ActionSelect(this);
			break;
		case DEL:
			newAct = new ActionDelete(this);
			break;
		case CHNG_DRAW_CLR:
			newAct = new ActionChangeDrawColor(this);
			break;
		case CHNG_FILL_CLR:
			newAct = new ActionChangeFillColor(this);
			break;
		case CHNG_BK_CLR:
			newAct = new ActionChangeBKGColor(this);
			break;
		case SEND_BACK:
			newAct = new ActionSendToBack(this);
			break;
		case BRNG_FRNT:
			newAct = new ActionSendToFront(this);
			break;
		case SAVE:
			newAct = new ActionSave(this);
			break;
		case LOAD:
			newAct = new ActionLoad(this);
			break;
		case TO_PLAY:
			newAct = new ActionSwitchToPlayMode(this);
			break;
		case TO_DRAW:
			newAct = new ActionSwitchToDrawMode(this);
			break;
		case TO_RESIZE:
			newAct = new ActionSwitchToResize(this);
			break;
		case RESIZEHALF:
			newAct = new ActionResize(this,0.5);
			break;
		case RESIZE75:
			newAct = new ActionResize(this, 0.75);
			break;
		case RESIZE2:
			newAct = new ActionResize(this, 2);
			break;
		case RESIZE4:
			newAct = new ActionResize(this, 4);
			break;
		case PLAY_SHAPES:
			newAct = new ActionPlayShape(this);
			break;
		case PLAY_COLORS:
			newAct = new ActionPlayColor(this);
			break;
		case PLAY_SHAPES_COLORS:
			newAct = new ActionPlayShapeAndColor(this);
			break;
		case EXIT:
			newAct = new ActionExit(this);
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return NULL;
			break;
	}	
	return newAct;
}
//////////////////////////////////////////////////////////////////////
//Executes the created Action
void ApplicationManager::ExecuteAction(Action* &pAct) 
{	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount) {
		FigList[FigCount++] = pFig;	
		FigList[FigCount - 1]->SetID(FigCount - 1);
	}
}
void ApplicationManager::resizeSelected(double factor) {
	for (int i = 0; i < selectefFigCount; i++)
		arrSelected[i]->resize(factor);
}
void ApplicationManager::AddSelectedFigure(CFigure* pFig)
{
	if (selectefFigCount < MaxFigCount)
		arrSelected[selectefFigCount++] = pFig;
}
void ApplicationManager::RemoveSelectedFigure(CFigure* pFig)
{
	bool found = false;
	for (int i = 0; i < selectefFigCount - 1; i++) {
		if (arrSelected[i] == pFig || found) {
			found = true;
			arrSelected[i] = arrSelected[i + 1];
		}
	}
	selectefFigCount--;
	pFig->SetSelected(false);
}
void ApplicationManager::RemoveAllSelectedFigures()
{
	while (selectefFigCount)
		RemoveSelectedFigure(arrSelected[0]);
}
void ApplicationManager::sendToBack() {
	int idx = arrSelected[0]->getID();
	if (!idx)
		return;
	FigList[0]->SetID(idx);
	FigList[idx]->SetID(0);
	swap(FigList[0], FigList[idx]);
	for (int i = idx; i > 1; i--) {
		FigList[i]->SetID(i - 1);
		FigList[i - 1]->SetID(i);
		swap(FigList[i], FigList[i - 1]);
	}
}
void ApplicationManager::sendToFront() {
	int idx = arrSelected[0]->getID();
	if (idx == FigCount - 1)
		return;
	FigList[FigCount - 1]->SetID(idx);
	FigList[idx]->SetID(FigCount - 1);
	swap(FigList[FigCount-1], FigList[idx]);
	for (int i = idx; i < FigCount - 2; i++) {
		FigList[i]->SetID(i + 1);
		FigList[i + 1]->SetID(i);
		swap(FigList[i], FigList[i + 1]);
	}
}

string ApplicationManager::getRandomFigure() {
	int idx = rand() % ((FigCount - 1) + 1);
	return FigList[idx]->getType();
}
color ApplicationManager::getRandomColor() {
	CFigure* arr[200];
	int n = 0;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->isFilled()) {
			arr[n++] = FigList[i];
		}
	}
	int idx = rand() % ((n - 1) + 1);
	return arr[idx]->getColor();
}
pair<string,color> ApplicationManager::getRandomShapeColor() {
	CFigure* arr[200];
	int n = 0;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->isFilled()) {
			arr[n++] = FigList[i];
		}
	}
	int idx = rand() % ((n - 1) + 1);
	return { arr[idx]->getType(),arr[idx]->getColor() };
}

int ApplicationManager::getFigureCount(string type) {
	int cnt = 0;
	for (int i = 0; i < FigCount; i++)
		cnt += (FigList[i]->getType() == type);
	return cnt;
}
int ApplicationManager::getColorCount(color c) {
	int cnt = 0;
	for (int i = 0; i < FigCount; i++)
		cnt += (colorEqual(FigList[i]->getColor(), c));
	return cnt;
}
int ApplicationManager::getShapeColorCount(pair<string,color> p) {
	int cnt = 0;
	for (int i = 0; i < FigCount; i++)
		cnt += (colorEqual(FigList[i]->getColor(), p.second) && FigList[i]->getType() == p.first);
	return cnt;
}
bool ApplicationManager::checkFig(string type) {
	return arrSelected[selectefFigCount - 1]->getType() == type;
}
bool  ApplicationManager::colorEqual(color c1, color c2) {
	return c1.ucRed == c2.ucRed &&
		c1.ucGreen == c2.ucGreen &&
		c1.ucBlue == c2.ucBlue;
}
bool ApplicationManager::checkColor(color c) {
	return colorEqual(arrSelected[selectefFigCount - 1]->getColor(), c);
}
bool ApplicationManager::checkShapeColor(pair<string,color>p) {
	return colorEqual(arrSelected[selectefFigCount - 1]->getColor(), p.second) && arrSelected[selectefFigCount - 1]->getType() == p.first;
}
void ApplicationManager::hideSelectedFig() {
	arrSelected[selectefFigCount - 1]->Hide();
	RemoveSelectedFigure(arrSelected[selectefFigCount - 1]);
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	///Add your code here to search for a figure given a point x,y	


	for (int i = FigCount - 1; i >= 0; i--)
	{
		if (FigList[i]->HiddenStatus() == false) {
			if (FigList[i]->isInside(x, y)) {
				FigList[i]->PrintInfo();
				return FigList[i];
			}
		}
	}


	return NULL;
}

/////////////////////////////////////////////////////////////////////////////////////
int ApplicationManager::getFigCount() {
	return FigCount;
}
int ApplicationManager::getSelectedFigCount() {
	return selectefFigCount;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for (int i = 0; i < FigCount; i++) {
		if(!FigList[i]->HiddenStatus())
			FigList[i]->DrawMe(pGUI);
	}
}
/////////////////////////////////////////////////////////////////////////////////////

void ApplicationManager::reset() {
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	FigCount = selectefFigCount = 0;
}
void ApplicationManager::restoreHiddenShapes() {
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Show();
}
void ApplicationManager::changeDrawColorForSelected(color c) {
	for (int i = 0; i < selectefFigCount; i++) {
		arrSelected[i]->ChngDrawClr(c);
	}
	RemoveAllSelectedFigures();
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::changeFillColorForSelected(color c) {
	for (int i = 0; i < selectefFigCount; i++) {
		arrSelected[i]->ChngFillClr(c);
	}
	RemoveAllSelectedFigures();
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the interface
GUI *ApplicationManager::GetGUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pGUI;
	
}

bool ApplicationManager::AnySelected() {
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected()) {
			return true;
		}
	}
	return false;
}
void ApplicationManager::DeleteFig() {
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			for (int j = i; j < FigCount - 1; j++)
			{
				swap(FigList[j], FigList[j + 1]);
			}
			RemoveSelectedFigure(FigList[FigCount - 1]);
			delete FigList[FigCount - 1];
			FigList[FigCount - 1] = NULL;
			this->FigCount--;
			i--;
		}
	}
}

//void saveAll(ofstream& OutFile);
void ApplicationManager::saveAll(ofstream& OutFile) {
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Save(OutFile);
}
