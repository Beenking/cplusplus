#include "pan_operation_factory.h"
#include "zoom_operation_factory.h"

IFactory* factory1 = new PanOperationFactory;
IFactory* factory2 = new ZoomOperationFactory;

int main()
{
	IOperation* pan = factory1->CreateOperation();
	pan->Excute();

	IOperation* zoom = factory2->CreateOperation();
	zoom->Excute();

	return 0;
}