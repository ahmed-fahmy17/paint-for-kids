
#include ".\Actions\Action.h"

class ActionSwitchToResize : public Action
{
public:
	ActionSwitchToResize(ApplicationManager* pApp);

	virtual void Execute();

};