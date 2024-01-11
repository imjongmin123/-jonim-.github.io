#include "Serializer.hpp"

int main()
{
	Data* dataptr = new Data(11);

	uintptr_t	serializ = Serializer::serialize(dataptr);
	Data* deserializ = Serializer::deserialize(serializ);
	if (deserializ == dataptr)
	{
		std::cout << "before : " << dataptr->getvalue() << std::endl;
		std::cout << "after : " << deserializ->getvalue() << std::endl;
		std::cout << "Success" << std::endl;
	}
	else
		std::cout << "fail" << std::endl;


	int*			iptr = reinterpret_cast<int*>(dataptr);
	Data*			dptr = reinterpret_cast<Data*>(iptr);
	if (dptr == dataptr)
	{
		std::cout << "before : " << dataptr->getvalue() << std::endl;
		std::cout << "after : " << dptr->getvalue() << std::endl;
		std::cout << "Success" << std::endl;
	}
	else
		std::cout << "fail" << std::endl;

	delete dataptr;
}