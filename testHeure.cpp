#include <iostream>
#include "Horaire.h"

int main()
{
	Horairec h{4,9};

	std::cout << h.str() << std::endl;
	h++;
	std::cout << h.str() << std::endl;
	h--;

	return 0;
}