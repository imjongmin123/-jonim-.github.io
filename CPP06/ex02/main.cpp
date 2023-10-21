#include "Base.hpp"

int main()
{
	Base* b = new Base();
	Base *bas = b->generate();
	b->identify(bas);
	b->identify(*bas);
	delete b;
	delete bas;
}