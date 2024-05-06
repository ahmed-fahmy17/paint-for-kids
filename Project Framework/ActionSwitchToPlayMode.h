#ifndef ACTION_SWITCH_PLAY_MODE
#define ACTION_SWITCH_PLAY_MODE

#include ".\Actions\Action.h"

class ActionSwitchToPlayMode : public Action
{
public:
	ActionSwitchToPlayMode(ApplicationManager* pApp);

	virtual void Execute();

};

#endif