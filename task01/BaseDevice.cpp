#include "BaseDevice.h"
#pragma warning (disable:4996)

BaseDevice::BaseDevice(const char* serialNumber, bool isOnline) : isOnline(isOnline)
{
	this->serialNumber = new char[strlen(serialNumber) + 1];
	strcpy(this->serialNumber, serialNumber);
}

BaseDevice::BaseDevice(const BaseDevice& other)
{
	copyFrom(other);
}

BaseDevice& BaseDevice::operator=(const BaseDevice& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

BaseDevice::~BaseDevice()
{
	free();
}

void BaseDevice::turnOn()
{
	isOnline = true;
}

void BaseDevice::turnOff()
{
	isOnline = false;
}

void BaseDevice::copyFrom(const BaseDevice& other)
{
	serialNumber = new char[strlen(other.serialNumber) + 1];
	strcpy(this->serialNumber, other.serialNumber);
	isOnline = other.isOnline;
}

void BaseDevice::free()
{
	delete[] serialNumber;
}