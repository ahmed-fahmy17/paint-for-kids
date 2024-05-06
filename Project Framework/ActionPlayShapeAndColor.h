#include "Actions/Action.h""

class ActionPlayShapeAndColor : public Action
{
public:
	ActionPlayShapeAndColor(ApplicationManager* pApp);

	virtual void Execute();
};