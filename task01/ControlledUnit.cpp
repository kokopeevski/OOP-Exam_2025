#include "ControlledUnit.h"
#pragma warning (disable:4996)


ControlledUnit::ControlledUnit(const char* serial, const char* pass) : BaseDevice(serial)
{
	password = new char[strlen(pass) + 1];
	strcpy(password, pass);
}

ControlledUnit::ControlledUnit(const ControlledUnit& other) : BaseDevice(other)
{
	copyFrom(other);
}

ControlledUnit& ControlledUnit::operator=(const ControlledUnit& other)
{
	if (this != &other)
	{
		BaseDevice::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}

ControlledUnit::~ControlledUnit()
{
	free();
}

bool ControlledUnit::authenticate(const char* input) const
{
	return strcmp(input, password) == 0;
}

void ControlledUnit::print() const
{
	std::cout << "[ControlledUnit] Serial: " << serialNumber << ", Online: " << isOnline << ", Password protected\n";
}

BaseDevice* ControlledUnit::clone() const
{
	return new ControlledUnit(*this);
}

void ControlledUnit::free()
{
	delete[] password;
}

void ControlledUnit::copyFrom(const ControlledUnit& other)
{
	this->password = new char[strlen(other.password) + 1];
	strcpy(this->password, password);
}
