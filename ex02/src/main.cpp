#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Base.hpp"

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));

	for (int i = 0; i < 6; i++)
	{
		Base *p = generate();
		std::cout << "pointer : ";
		identify(p);
		std::cout << "reference: ";
		identify(*p);
		delete p;
	}
}
