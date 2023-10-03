#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
	private:
	int	fix_point_number;
	static const int bit = 8;

	public:
	Fixed();
	~Fixed();

	Fixed(const Fixed& fx);
	Fixed& operator=(const Fixed& fx);
	int getRawBits() const;
	void setRawBits(int const raw);
};

#endif
