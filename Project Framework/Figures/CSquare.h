#ifndef CSQUARE_H
#define CSQUARE_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point TopLeftCorner;
	int length;
public:
	CSquare();
	CSquare(Point , int, GfxInfo FigureGfxInfo,int );
	virtual void DrawMe(GUI* pOut) const;
	virtual bool isInside(int x, int y);
	string getType();
	void resize(double factor);
	string PrintInfo();
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
};

#endif