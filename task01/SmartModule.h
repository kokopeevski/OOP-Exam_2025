#pragma once
#include "Sensor.h"
#include "ControlledUnit.h"

class SmartModule : public Sensor, public ControlledUnit
{
	double limit;

public:
	SmartModule(const char* serial, const char* pass, double limit);
	void simulate(double value);
	void checkAndTrigger();

	void print() const override;
	BaseDevice* clone() const override;
};