#include <iostream>
#include "iter.hpp"

int main()
{
	int array2[5] = {3, 4, 42, 42};
	const char myString[] = "Hello";
	const int array[10] = {1, 2, 3, 4};

	iter(array, 5, myprint);
	iter(array, 5, myprint<int>);
	iter(array, 5, myprint<const int>);

	iter(array, 5, myprint<volatile int>);
	iter(array, 5, myprint<const volatile int>);

	iter(array2, 5, plus<int>);

	iter(myString, 5, myprint);
	iter(myString, 5, myprint<const char>);
	iter(myString, 5, myprint<char>);
}