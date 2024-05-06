#ifndef ACTION_CHANGE_Fill_COLOR_H
#define ACTION_CHANGE_Fill_COLOR_H
#include "Actions/Action.h""

class ActionChangeFillColor : public Action
{
public:
	ActionChangeFillColor(ApplicationManager* pApp);

	virtual void Execute();

};

#endif