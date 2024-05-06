#pragma once
#ifndef ACTION_SELECT_H
#define ACTION_SELECT_H

#include ".\Actions\Action.h"
#include ".\Figures\CFigure.h"

class ActionSelect : public Action
{
public:
	ActionSelect(ApplicationManager* pApp);
	virtual void Execute();
};

#endif
