#pragma once

#include "operation.h"

class IFactory
{
public:
	virtual IOperation* CreateOperation() = 0;
	~IFactory() {}
};