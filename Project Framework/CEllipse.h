#ifndef CELLIPSE_H
#define CELLIPSE_H

#include ".\Figures\CFigure.h"

class CEllipse : public CFigure
{
private:
	Point TopLeftCorner;
	Point BottomRightCorner;
public:
	CEllipse(Point, Point, GfxInfo FigureGfxInfo);
	CEllipse();
	virtual void DrawMe(GUI* pOut) const;
	virtual bool isInside(int x, int y);
	string getType();
	void resize(double factor);
	virtual string PrintInfo();
	virtual void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
};

#endif