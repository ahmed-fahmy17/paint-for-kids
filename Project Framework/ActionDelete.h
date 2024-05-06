#pragma once
#ifndef ACTION_DELETE_H
#define ACTION_DELETE_H

#include ".\Actions\Action.h"
#include ".\Figures\CFigure.h"


class ActionDelete : public Action
{
public:
	ActionDelete(ApplicationManager* pApp);
	virtual void Execute();

};

#endif#pragma once

