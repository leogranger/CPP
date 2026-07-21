#pragma once

#include <iostream>
#include <stdint.h>

struct Data
{
	int			dataSize;
	int*		dataNb;
};

class Serializer
{
	public:
		Serializer(void);
		Serializer(const Serializer& other);
		Serializer&	operator=(const Serializer& other);
		~Serializer(void);
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};