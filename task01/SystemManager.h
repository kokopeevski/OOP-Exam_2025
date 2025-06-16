#pragma once
#include "BaseDevice.h"
const int MAX_DEVICES = 100;

class SystemManager
{
	BaseDevice* devices[MAX_DEVICES];
	int count;

public:
    SystemManager();
    ~SystemManager();

    void registerDevice(BaseDevice* dev);
    void simulateAll();
    void printAll() const;
    void saveToFile(const char* filename) const;
    void loadFromFile(const char* filename);
};