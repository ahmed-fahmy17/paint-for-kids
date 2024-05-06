#ifndef CHEXAGON_H
#define CHEXAGON_H

#include ".\Figures\CFigure.h"
#include ".\ApplicationManager.h"

class Chexagon : public CFigure
{
private:
	Point TopLeftCorner;
	int length;
	double height;
public:
	ApplicationManager* pManager = NULL;	//Actions needs AppMngr to do their job
	Chexagon();
	Chexagon(Point, int, GfxInfo FigureGfxInfo); // Constructor

	virtual void DrawMe(GUI* pOut) const;
	virtual bool isInside(int x, int y);
	string getType();
	void resize(double factor);
	virtual string PrintInfo();
	virtual void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	double AreaTriangle(double x1, double y1, double x2, double y2, double x3, double y3);
};

#endif