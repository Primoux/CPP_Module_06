#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>

class Serializer
{
private:
	Serializer();
	~Serializer();
	Serializer(Serializer const &original);
	Serializer &operator=(Serializer const &other);

public:
	static uintptr_t	serialize(Data *ptr);
	static Data			*deserialize(uintptr_t raw);
};

#endif
