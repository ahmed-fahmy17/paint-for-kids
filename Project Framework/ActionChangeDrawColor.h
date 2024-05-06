#ifndef ACTION_CHANGE_DRAW_COLOR_H
#define ACTION_CHANGE_DRAW_COLOR_H
#include "Actions/Action.h""

class ActionChangeDrawColor : public Action
{
public:
	ActionChangeDrawColor(ApplicationManager* pApp);

	virtual void Execute();

};

#endif