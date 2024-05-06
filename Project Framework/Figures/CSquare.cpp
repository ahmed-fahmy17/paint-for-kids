#include "CSquare.h"
#include "..\Actions\Action.h"
#include"fstream"
#include<string>

CSquare::CSquare() {}

CSquare::CSquare(Point P1, int len, GfxInfo FigureGfxInfo,int id):CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	length = len;
	ID = id;
}
	
bool CSquare::isInside(int x, int y)
{
	if (x >= TopLeftCorner.x && x <= (TopLeftCorner.x + length) && y >= TopLeftCorner.y && y <= (TopLeftCorner.y + length))
	{
		return true;
	}
	return false;
}
string CSquare::getType()
{
	return "Square";
}
void CSquare::resize(double factor) {
	int newlen = length * factor;
	if (TopLeftCorner.x + newlen > UI.width || TopLeftCorner.y + newlen > UI.height - UI.StatusBarHeight || newlen<5) {
		return;
	}
	length *= factor;
}

string CSquare::PrintInfo()
{
	string res = "sqr point x = " + to_string(TopLeftCorner.x) + " point y = " + to_string(TopLeftCorner.y) + " and the Length " + to_string(length);
	return res;


	//return "figure name - p.x - p.y - lenght -col"

}
void CSquare::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawSquare(TopLeftCorner, length, FigGfxInfo, Selected);

}
void CSquare::Save(ofstream& OutFile) {//type id TopLeftPoint length isfilled fillcolor borderwidth selected
	OutFile << "SQR " << to_string(ID) << ' ' << to_string(TopLeftCorner.x) << ' ' << to_string(TopLeftCorner.y) << ' ' << to_string(length) << ' '
		<< to_string(FigGfxInfo.DrawClr.ucRed) << ' ' << to_string(FigGfxInfo.DrawClr.ucGreen) << ' ' << to_string(FigGfxInfo.DrawClr.ucBlue) << ' ' <<
		(FigGfxInfo.isFilled ? "t" : "f") << ' ' << to_string(FigGfxInfo.FillClr.ucRed) << ' ' << to_string(FigGfxInfo.FillClr.ucGreen) << ' ' <<
		to_string(FigGfxInfo.FillClr.ucBlue) << ' ' << to_string(FigGfxInfo.BorderWdth) << ' ' << "f" << ' ' <<
		(figHidden ? "t" : "f") << endl;
}

void CSquare::Load(ifstream& Infile) {
	string x, y, z;
	Infile >> x;
	ID = stoi(x);
	Infile >> x >> y;
	TopLeftCorner.x = stoi(x);
	TopLeftCorner.y = stoi(y);
	Infile >> x;
	length = stoi(x);
	Infile >> x >> y >> z;
	FigGfxInfo.DrawClr = color(stoi(x), stoi(y), stoi(z));
	Infile >> x;
	FigGfxInfo.isFilled = (x == "t");
	Infile >> x >> y >> z;
	FigGfxInfo.FillClr = color(stoi(x), stoi(y), stoi(z));
	Infile >> x;
	FigGfxInfo.BorderWdth = stoi(x);
	Infile >> x;
	Selected = (x == "t");
	Infile >> x;
	figHidden = (x == "t");
}
