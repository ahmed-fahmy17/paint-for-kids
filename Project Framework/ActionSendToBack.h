#pragma once

#include ".\Actions\Action.h"
#include ".\Figures\CFigure.h"

class ActionSendToBack : public Action
{
public:
	ActionSendToBack(ApplicationManager* pApp);
	virtual void Execute();
};
