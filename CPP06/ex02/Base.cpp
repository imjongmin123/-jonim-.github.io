#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base::~Base() {}

Base* Base::generate(void)
{
	std::srand(std::time(0));
	int ran = rand() % 3;
	Base* base;
	if (ran == 0)
	{
		A* a = new A();
		base = dynamic_cast<Base*>(a);
	}
	else if (ran == 1)
	{
		B* b = new B();
		base = dynamic_cast<Base*>(b);
	}
	else
	{
		C* c = new C();
		base = dynamic_cast<Base*>(c);
	}
	return (base);
}

void Base::identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "pointer to type : A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "pointer to type : B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "pointer to type : C" << std::endl;
}

void Base::identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "reference to type : A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "reference to type : B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				C &c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "reference to type : C" << std::endl;
			}
			catch(const std::exception& e)
			{
			}
			
		}
	}
}