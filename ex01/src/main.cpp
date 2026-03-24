#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data data;
	data.id    = 42;
	data.name  = "hello";
	data.value = 3.14f;

	std::cout << "Original pointer : " << &data << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized       : " << raw << std::endl;

	Data *result = Serializer::deserialize(raw);
	std::cout << "Deserialized ptr : " << result << std::endl;

	if (result == &data)
		std::cout << "OK: pointers are equal" << std::endl;
	else
		std::cout << "KO: pointers differ" << std::endl;

	std::cout << "id="    << result->id
	          << " name=" << result->name
	          << " value=" << result->value << std::endl;
}
