#include "Actions/Action.h""

class ActionPlayShape : public Action
{
public:
	ActionPlayShape(ApplicationManager* pApp);

	virtual void Execute();
	~ActionPlayShape();
};