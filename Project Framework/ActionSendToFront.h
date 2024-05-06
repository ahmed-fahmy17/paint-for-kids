#pragma once

#include ".\Actions\Action.h"
#include ".\Figures\CFigure.h"

class ActionSendToFront : public Action
{
public:
	ActionSendToFront(ApplicationManager* pApp);
	virtual void Execute();
};
