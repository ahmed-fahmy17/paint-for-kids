#include "Chexagon.h"
#include"ApplicationManager.h"
#include".\GUI\GUI.h"
#include"fstream"
#include<string>

Chexagon::Chexagon() {}

Chexagon::Chexagon(Point P1, int len, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	length = len;
	height = 1.732 * length;
}



void Chexagon::DrawMe(GUI* pGUI) const
{
	pGUI->DrawHexagon(TopLeftCorner, length, FigGfxInfo, Selected);

}

bool Chexagon::isInside(int x, int y) //whether the point is inside the figure or not
{

	// if inside inner rectangle
	if (x >= TopLeftCorner.x && x <= TopLeftCorner.x + length && y >= TopLeftCorner.y && y <= TopLeftCorner.y + height)
		return true;
	double eps = 0.00000006;
	double sideTrianglesArea = AreaTriangle(TopLeftCorner.x, TopLeftCorner.y, TopLeftCorner.x, TopLeftCorner.y + height, TopLeftCorner.x - 0.5 * length, TopLeftCorner.y + 0.5 * height);
	// if inside left side triangle
	// left triangle >> (x,y), (x, y+h), (x-0.5l, y+0.5h)
	double Area1 = AreaTriangle(x, y, TopLeftCorner.x, TopLeftCorner.y + height, TopLeftCorner.x - 0.5 * length, TopLeftCorner.y + 0.5 * height);
	double Area2 = AreaTriangle(TopLeftCorner.x, TopLeftCorner.y, x, y, TopLeftCorner.x - 0.5 * length, TopLeftCorner.y + 0.5 * height);
	double Area3 = AreaTriangle(TopLeftCorner.x, TopLeftCorner.y, TopLeftCorner.x, TopLeftCorner.y + height, x, y);
	if (abs((Area1 + Area2 + Area3) - sideTrianglesArea) <= eps)
		return true;
	// if inside right side triangle

		// sideTrianglesArea = AreaTriangle(TopLeftCorner.x+ length, TopLeftCorner.y, TopLeftCorner.x + length, TopLeftCorner.y + height, TopLeftCorner.x + 1.5 * length, TopLeftCorner.y + 0.5 * height);
	// right triangle >> (x+l,y), (x+l, y+h), (x+1.5l, y+0.5h)

	double Area4 = AreaTriangle(x, y, TopLeftCorner.x + length, TopLeftCorner.y + height, TopLeftCorner.x + 1.5 * length, TopLeftCorner.y + 0.5 * height);
	double Area5 = AreaTriangle(TopLeftCorner.x + length, TopLeftCorner.y, x, y, TopLeftCorner.x + 1.5 * length, TopLeftCorner.y + 0.5 * height);
	double Area6 = AreaTriangle(TopLeftCorner.x + length, TopLeftCorner.y, TopLeftCorner.x + length, TopLeftCorner.y + height, x, y);
	if (abs((Area4 + Area5 + Area6) - sideTrianglesArea) <= eps)
		return true;

	return false;
}

double Chexagon::AreaTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) * 0.5);
}


string Chexagon::getType()
{
	return "Hexagon";
}

void Chexagon::resize(double factor) {
	int newlen = length* factor;
	int newhieght =newlen * 1.732;
	if ( TopLeftCorner.x +1.5 *newlen > UI.width || TopLeftCorner.x - 0.5 * newlen < 0 || newhieght> UI.height - UI.StatusBarHeight) {
		return;
	}
	length *= factor;
}

string Chexagon::PrintInfo() {
	return "";
}

void Chexagon::Save(ofstream& OutFile) {//type id TopLeftPoint length isfilled fillcolor borderwidth selected
	OutFile << "HEX " << to_string(ID) << ' ' << to_string(TopLeftCorner.x) << ' ' << to_string(TopLeftCorner.y) << ' ' << to_string(length) << ' '
		<< to_string(FigGfxInfo.DrawClr.ucRed) << ' ' << to_string(FigGfxInfo.DrawClr.ucGreen) << ' ' << to_string(FigGfxInfo.DrawClr.ucBlue) << ' ' <<
		(FigGfxInfo.isFilled ? "t" : "f") << ' ' << to_string(FigGfxInfo.FillClr.ucRed) << ' ' << to_string(FigGfxInfo.FillClr.ucGreen) << ' ' <<
		to_string(FigGfxInfo.FillClr.ucBlue) << ' ' << to_string(FigGfxInfo.BorderWdth) << ' ' << "f" << ' ' <<
		(figHidden ? "t" : "f") << endl;
}

void Chexagon::Load(ifstream& Infile) {
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