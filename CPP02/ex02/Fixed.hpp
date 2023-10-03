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

	bool operator>(const Fixed& fx) const;
	bool operator<(const Fixed& fx) const;
	bool operator>=(const Fixed& fx) const;
	bool operator<=(const Fixed& fx) const;
	bool operator==(const Fixed& fx) const;
	bool operator!=(const Fixed& fx) const;

	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	Fixed operator+(const Fixed& fx) const;
	Fixed operator*(const Fixed& fx) const;
	Fixed operator-(const Fixed& fx) const;
	Fixed operator/(const Fixed& fx) const;

	int getRawBits() const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;

	static Fixed& min(Fixed& fx1, Fixed& fx2);
	static const Fixed& min(const Fixed& fx1, const Fixed& fx2);
	static Fixed& max(Fixed& fx1, Fixed& fx2);
	static const Fixed& max(const Fixed& fx1, const Fixed& fx2);
};

std::ostream& operator<< (std::ostream& os, const Fixed& fixed);

#endif
