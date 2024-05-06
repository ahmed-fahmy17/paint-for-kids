#pragma once
#include"Actions/Action.h"
#include"ApplicationManager.h"
class ActionLoad : public Action
{
public:
	ActionLoad(ApplicationManager* pApp);

	virtual void Execute();

};