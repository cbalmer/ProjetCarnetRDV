#include <iostream>
#include "Date.h"

int main()
{

	Date d;

	std::cout << d.str() << std::endl;
	d++;
	std::cout << d.str() << std::endl;
	d--;
	std::cout << d.str() << std::endl;
	d+=4;
	std::cout << d.str() << std::endl;
	d-=30;
	std::cout << d.str() << std::endl;
}