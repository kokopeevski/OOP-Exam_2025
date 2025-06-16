#include "Sensor.h"

Sensor::Sensor(const char* serialNum, double val) : BaseDevice(serialNum), value(val)
{
}

void Sensor::simulate(double newValue) 
{
    value = newValue;
}

double Sensor::getValue() const 
{
    return value;
}

void Sensor::print() const 
{
    std::cout << "[Sensor] Serial: " << serialNumber << ", Online: " << isOnline << ", Value: " << value << std::endl;
}

BaseDevice* Sensor::clone() const 
{
    return new Sensor(*this);
}