#pragma once

#include "factory.h"
#include "operation_pan.h"

class PanOperationFactory : public IFactory
{
public:
	virtual IOperation* CreateOperation()
	{
		return new OperationPan();
	}
};
