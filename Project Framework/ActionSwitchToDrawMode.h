#include ".\Actions\Action.h"

class ActionSwitchToDrawMode : public Action
{
public:
	ActionSwitchToDrawMode(ApplicationManager* pApp);

	virtual void Execute();

};