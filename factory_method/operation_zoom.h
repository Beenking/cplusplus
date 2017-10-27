#pragma once
#include "operation.h"
#include <iostream>

class OperationZoom : public IOperation
{
	virtual void Excute()
	{
		std::cout << "Zoom Operation" << std::endl;
	}
};