#pragma once
#include "Component.h"
class ControlComponent : public Component
{
public:
	ControlComponent() : controlValue(1) {}
	int getValue() { return controlValue; }
	void setValue(int value) { this->controlValue = value; }
private:
	int controlValue;
};