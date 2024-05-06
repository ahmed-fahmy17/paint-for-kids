#include "Actions/Action.h""

class ActionPlayColor : public Action
{
public:
	ActionPlayColor(ApplicationManager* pApp);

	virtual void Execute();
};