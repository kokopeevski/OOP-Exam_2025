#pragma once
#include "BaseDevice.h"

class Sensor : virtual public BaseDevice
{
protected:
	double value;

public:
	Sensor(const char* serialNum, double val = 0);
	void simulate(double newValue);
	double getValue() const;

	void print() const override;
	BaseDevice* clone() const override;
};