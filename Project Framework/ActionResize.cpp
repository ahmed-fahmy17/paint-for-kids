#include "ActionResize.h"

#include "ApplicationManager.h"


#include ".\GUI\GUI.h"

ActionResize::ActionResize(ApplicationManager* pApp, double _factor) :Action(pApp)
{
	factor = _factor;
}

//Execute the action
void ActionResize::Execute()
{
	pManager->resizeSelected(factor);
}
