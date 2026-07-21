#include "Serializer/Serializer.hpp"

int	main(void)
{
	Data	data;

	data.dataSize = 5;
	data.dataNb = new int[data.dataSize];
	for (int i = 0; i < data.dataSize; i++)
		data.dataNb[i] = i;

	Serializer	serie;
	uintptr_t	raw;

	std::cout << "Before serialization: " << &data << std::endl;

	raw = serie.serialize(&data);

	std::cout << "After serialization: " << &data << std::endl;

	Data*	returnedData = serie.deserialize(raw);

	std::cout << "The return value after deserialization: " << returnedData << std::endl;

	return (0);
}