#pragma once
#include ".\Actions\Action.h"
#include "ApplicationManager.h"

class ActionExit : public Action
{
public:
	ActionExit(ApplicationManager* pApp);

	virtual void Execute();

};
