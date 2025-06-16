#include "SmartModule.h"

SmartModule::SmartModule(const char* serial, const char* pass, double limit)
    : BaseDevice(serial), Sensor(serial), ControlledUnit(serial, pass), limit(limit) 
{
}

void SmartModule::simulate(double value) 
{
    Sensor::simulate(value);
    checkAndTrigger();
}

void SmartModule::checkAndTrigger() 
{
    if (getValue() > limit) {
        ControlledUnit::turnOn();
    }
    else {
        ControlledUnit::turnOff();
    }
}

void SmartModule::print() const 
{
    std::cout   << "[SmartModule] Serial: " << serialNumber
                << ", Online: " << isOnline
                << ", Value: " << getValue()
                << ", Limit: " << limit << std::endl;
}

BaseDevice* SmartModule::clone() const 
{
    return new SmartModule(*this);
}