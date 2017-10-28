#pragma once

class IOperation
{
public:
	virtual void Excute() = 0;
	virtual ~IOperation() {}
};