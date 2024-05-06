#pragma once
#include ".\Actions\Action.h"
#include ".\ApplicationManager.h"
class ActionSave : public Action
{
public:
	ActionSave(ApplicationManager* pApp);

	virtual void Execute();

};
