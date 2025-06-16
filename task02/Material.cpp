#include "Material.h"
#pragma warning (disable:4996)

Material::Material(const char* code, int level) : sensitivityLevel(level)
{
	this->code = new char[strlen(code) + 1];
	strcpy(this->code, code);
}

Material::Material(const Material& other)
{
	copyFrom(other);
}

Material& Material::operator=(const Material& other)
{
	if (this != &other) 
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Material::~Material()
{
	free();
}

void Material::free()
{
	delete code;
	sensitivityLevel = 0;
}

void Material::copyFrom(const Material& other)
{
	code = new char[strlen(other.code) + 1];
	strcpy(this->code, other.code);
	sensitivityLevel = other.sensitivityLevel;
}

std::ostream& operator<<(std::ostream& os, const Material& m)
{
	m.print(os);
	return os;
}
