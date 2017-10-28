#pragma once

#include "operation.h"
#include <iostream>

class OperationPan : public IOperation
{
public:
	virtual void Excute()
	{
		std::cout << "Pan Operation" << std::endl;
	}
};