#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>


class Fixed
{
	private:
	int	fix_point_number;
	static const int bit = 8;

	public:
	Fixed();
	~Fixed();
	
	Fixed(const int var);
	Fixed(const float var);
	Fixed(const Fixed& fx);

	Fixed& operator=(const Fixed& fx);

	int getRawBits() const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream& operator<< (std::ostream& os, const Fixed& fixed);

#endif
