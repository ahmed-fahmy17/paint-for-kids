#include "CEllipse.h"
#include"fstream"
#include<string>

CEllipse::CEllipse() {}

CEllipse::CEllipse(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	BottomRightCorner = P2;
}


void CEllipse::DrawMe(GUI* pGUI) const
{
	pGUI->DrawEllipse(TopLeftCorner, BottomRightCorner, FigGfxInfo, Selected);

}
//virtual bool isInside(int x, int y);
bool CEllipse::isInside(int x, int y) {
	Point center;
	center.x = 0.5 * (TopLeftCorner.x + BottomRightCorner.x);
	center.y = 0.5 * (TopLeftCorner.y + BottomRightCorner.y);
	float a = abs(TopLeftCorner.x - BottomRightCorner.x) / 2;
	float b = abs(TopLeftCorner.y - BottomRightCorner.y) / 2;
	float check = (pow(x - center.x, 2) / pow(a, 2)) + (pow(y - center.y, 2) / pow(b, 2));
	if (check <= 1)
		return true;
	return false;
}

string CEllipse::getType()
{
	return "Ellipse";
}

void CEllipse::resize(double factor) {

	int newx=BottomRightCorner.x * factor;
	int newy =BottomRightCorner.y * factor;
	if (newx > UI.width || newy <= UI.ToolBarHeight|| newy > UI.height - UI.StatusBarHeight || newx<TopLeftCorner.x || newy < TopLeftCorner.y) {
		return;
	}
	BottomRightCorner.y *= factor;
	BottomRightCorner.x *= factor;
}

string CEllipse::PrintInfo() {
	return "";
}
void CEllipse::Save(ofstream& OutFile) {//type id TopLeftPoint BottomRightCorner isfilled fillcolor borderwidth selected
	OutFile << "ELLIPSE " << to_string(ID) << ' ' << to_string(TopLeftCorner.x) << ' ' << to_string(TopLeftCorner.y) << ' ' << to_string(BottomRightCorner.x) << ' '
		<< to_string(BottomRightCorner.y) << ' '
		<< to_string(FigGfxInfo.DrawClr.ucRed) << ' ' << to_string(FigGfxInfo.DrawClr.ucGreen) << ' ' << to_string(FigGfxInfo.DrawClr.ucBlue) << ' ' <<
		(FigGfxInfo.isFilled ? "t" : "f") << ' ' << to_string(FigGfxInfo.FillClr.ucRed) << ' ' << to_string(FigGfxInfo.FillClr.ucGreen) << ' ' <<
		to_string(FigGfxInfo.FillClr.ucBlue) << ' ' << to_string(FigGfxInfo.BorderWdth) << ' ' << "f" << ' ' <<
		(figHidden ? "t" : "f") << endl;
}

void CEllipse::Load(ifstream& Infile) {
	string x, y, z;
	Infile >> x;
	ID = stoi(x);
	Infile >> x >> y;
	TopLeftCorner.x = stoi(x);
	TopLeftCorner.y = stoi(y);
	Infile >> x >> y;
	BottomRightCorner.x = stoi(x);
	BottomRightCorner.y = stoi(y);
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