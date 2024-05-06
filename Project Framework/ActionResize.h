#include ".\Actions\Action.h"

//Add Square Action class
class ActionResize : public Action
{
	double factor;
public:
	ActionResize(ApplicationManager* pApp,double _factor);

	virtual void Execute();

};