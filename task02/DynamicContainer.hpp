#pragma once
#include "Material.h"
#include <exception>

template <typename T, size_t max = 100>
class DynamicContainer 
{
    T** data;
    size_t count;

    void copyFrom(const DynamicContainer& other) 
    {
        count = other.count;
        data = new T * [max];
        for (size_t i = 0; i < count; ++i) 
        {
            data[i] = dynamic_cast<T*>(other.data[i]->clone());
        }
    }

    void free() 
    {
        for (size_t i = 0; i < count; ++i)
            delete data[i];
        delete[] data;
    }

public:
    DynamicContainer() : count(0)
    {
        data = new T * [max];
    }

    DynamicContainer(const DynamicContainer& other) 
    {
        copyFrom(other);
    }

    DynamicContainer& operator=(const DynamicContainer& other) 
    {
        if (this != &other) 
        {
            free();
            copyFrom(other);
        }
        return *this;
    }

    ~DynamicContainer() 
    {
        free();
    }

    void add(const T& element) 
    {
        if (count < max) 
        {
            data[count++] = dynamic_cast<T*>(element.clone());
        }
    }

    T& operator[](size_t index) 
    {
        if (index < 0 || index >= count)
            throw std::out_of_range("Out of range exeception");
        
        return *data[index];
    }

    const T& operator[](size_t index) const 
    {
        if (index < 0 || index >= count) 
            throw std::out_of_range("Out of range exeception");

        return *data[index];
    }

    DynamicContainer operator+(const DynamicContainer& other) const 
    {
        DynamicContainer result;
        for (int i = 0; i < count; ++i) 
            result.add(*data[i]);
        for (int i = 0; i < other.count; ++i)
            result.add(*other.data[i]);

        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const DynamicContainer& dc) 
    {
        os << "Container content (" << dc.count << " items):\n";
        for (int i = 0; i < dc.count; ++i) 
        {
            os << "  - ";
            dc.data[i]->print(os);
            os << std::endl;
        }
        return os;
    }
};