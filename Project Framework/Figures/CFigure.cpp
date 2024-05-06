#include "CFigure.h"

void CFigure::SetID(int id)
{
	ID = id;
}

CFigure::CFigure() {}

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	figHidden = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
void CFigure::Hide()
{
	figHidden = true;
}
bool CFigure::isFilled()
{
	return FigGfxInfo.isFilled;
}
color CFigure::getColor()
{
	return FigGfxInfo.FillClr;
}
//Shows Figures
void CFigure::Show()
{
	figHidden = false;
}
//Gives Current Status 
bool CFigure::HiddenStatus() const
{
	return figHidden;
}
