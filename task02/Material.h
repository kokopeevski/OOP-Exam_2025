#pragma once
#include <iostream>
#include <cstring>

class Material 
{
protected:
    char* code;
    int sensitivityLevel;

public:
    Material(const char* code, int level);
    Material(const Material& other);
    Material& operator=(const Material& other);
    virtual ~Material();

    virtual void process() const = 0;
    virtual Material* clone() const = 0;
    virtual void print(std::ostream& os) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Material& m);

private:
    void free();
    void copyFrom(const Material& other);
};