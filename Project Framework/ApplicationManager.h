#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"

class Action;	//Forward Declaration


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	int selectefFigCount;
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* arrSelected[MaxFigCount];

	//Pointers to Input and Output classes
	GUI* pGUI;
	

public:	
	ApplicationManager(); 
	~ApplicationManager();

	void Run();		//to run the application
	
	// -- Action-Related Functions
	Action* CreateAction(ActionType);
	void ExecuteAction(Action*&) ; //Execute an action
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	void resizeSelected(double factor);
	void AddSelectedFigure(CFigure* pFig);
	void RemoveSelectedFigure(CFigure* pFig);
	void RemoveAllSelectedFigures();
	int getFigCount();
	int getSelectedFigCount();
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void sendToBack();
	bool colorEqual(color c1, color c2);
	void sendToFront();
	int getColorCount(color c);
	int getShapeColorCount(pair<string, color> p);
	string getRandomFigure();
	color getRandomColor();
	pair<string, color> getRandomShapeColor();
	int getFigureCount(string type);
	bool checkFig(string type);
	bool checkColor(color c);
	bool checkShapeColor(pair<string, color>p);
	void hideSelectedFig();
		
	// -- Interface Management Functions	
	GUI *GetGUI() const; //Return pointer to the interface
	void changeDrawColorForSelected(color c);
	void changeFillColorForSelected(color c);
	void UpdateInterface() const;	//Redraws all the drawing window
	void reset();
	void restoreHiddenShapes();
	//save
	void DeleteFig();  // Delete Figures
	bool AnySelected(); // To Check if there is figure (or figures) Selected
	void saveAll(ofstream& OutFile);
};

#endif