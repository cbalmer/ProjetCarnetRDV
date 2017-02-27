#include <iostream>
#include "Horaire.h"

int main()
{
	Horaire z{}, h{4,9};

	std::cout << z.str() << std::endl << h.str() << std::endl;

	return 0;
}