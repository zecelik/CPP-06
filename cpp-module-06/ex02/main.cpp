#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>

Base* generate() {
	std::srand(time(NULL));

	int n = rand() % 3;
	switch (n) {
		case 0:
			std::cout << "generated an A class" << std::endl;
			return new A;
		case 1:
			std::cout << "generated an B class" << std::endl;
			return new B;
		case 2:
			std::cout << "generated an C class" << std::endl;
			return new C;
	}

	std::cout << "some very weird error ocurred: can't generate a class" << std::endl;
	return NULL;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL) {////base classın pointerını child classın pointerına dönüştürmeye çalışır
		std::cout << "A class was identified" << std::endl;
	} else if (dynamic_cast<B*>(p) != NULL) {
		std::cout << "B class was identified" << std::endl;
	} else if (dynamic_cast<C*>(p) != NULL) {
		std::cout << "C class was identified" << std::endl;
	} else {
		std::cout << "Can't identify the class" << std::endl;
	}
}

void identify(Base& p) {
	try {
		A& aux = dynamic_cast<A&>(p); (void)aux; //base classın referansını child classın referansına dönüştürmeye çalışır
		std::cout << "A class was identified" << std::endl;
		return;
	} catch (...) {}

	try {
		B& aux = dynamic_cast<B&>(p); (void)aux;
		std::cout << "B class was identified" << std::endl;
		return;
	} catch (...) {}

	try {
		C& aux = dynamic_cast<C&>(p); (void)aux;
		std::cout << "C class was identified" << std::endl;
		return;
	} catch (...) {}//her türden istisnayı yakalamak için üç nokta kullanılır

	std::cout << "Can't identify the class" << std::endl;
}

int main() {
	Base *base;

	base = generate();
	identify(base); // pointer
	identify(*base); // reference

	return 0;
}
