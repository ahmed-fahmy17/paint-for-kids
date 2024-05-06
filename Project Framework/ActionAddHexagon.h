#ifndef ACTION_ADD_HEXA_H
#define ACTION_ADD_HEXA_H

#include ".\Actions\Action.h"

//Add Hexagon Action class
class ActionAddHexagon : public Action
{
public:
	ActionAddHexagon(ApplicationManager* pApp);

	//Add Hexagon to the ApplicationManager
	virtual void Execute();

};

#endif