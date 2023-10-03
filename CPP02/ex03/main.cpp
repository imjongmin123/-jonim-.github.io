#include "Fixed.hpp"
#include "Point.hpp"

int main()
{
	Point a(1, 1);
	Point b(5, 1);
	Point c(3, 3);
	Point m(2, 1);

	if (bsp(a, b, c, m))
		std::cout << "point in tran" << std::endl;
	else
		std::cout << "point is not in" << std::endl;
}
