#pragma once

#include "factory.h"
#include "operation_zoom.h"

class ZoomOperationFactory : public IFactory
{
public:
	virtual IOperation* CreateOperation()
	{
		return new OperationZoom();
	}
};

