#pragma once
#include <iostream>
#include <cstring>

class BaseDevice
{
protected:
	char* serialNumber;
	bool isOnline;

public:
	BaseDevice(const char* serialNumber, bool isOnline = false);
	BaseDevice(const BaseDevice& other);
	BaseDevice& operator=(const BaseDevice& other);
	virtual ~BaseDevice();

	virtual void turnOn();
	virtual void turnOff();

	virtual void print() const = 0;
	virtual BaseDevice* clone() const = 0;

private:
	void copyFrom(const BaseDevice& other);
	void free();
};