#pragma once
#include "BaseDevice.h"

class ControlledUnit : virtual public BaseDevice
{
protected:
	char* password;

public:
	ControlledUnit(const char* serial, const char* pass);
	ControlledUnit(const ControlledUnit& other);
	ControlledUnit& operator=(const ControlledUnit& other);
	~ControlledUnit();

	bool authenticate(const char* input) const;
	void print() const override;
	BaseDevice* clone() const override;

private:
	void free();
	void copyFrom(const ControlledUnit& other);
};