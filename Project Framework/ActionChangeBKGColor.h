#ifndef ACTION_CHANGE_BKG_COLOR_H
#define ACTION_CHANGE_BKG_COLOR_H
#include "Actions/Action.h"

class ActionChangeBKGColor : public Action
{
public:
	ActionChangeBKGColor(ApplicationManager* pApp);

	virtual void Execute();

};

#endif