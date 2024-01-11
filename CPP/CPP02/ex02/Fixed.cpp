#include "Fixed.hpp"

Fixed::Fixed() : fix_point_number(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed (const Fixed& fx)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fx;
}

Fixed::Fixed (const float var) : fix_point_number(roundf(var * (1 << bit)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed (const int var) : fix_point_number(var << bit)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& fx)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fix_point_number = fx.getRawBits();
	return (*this);
}



bool Fixed::operator>(const Fixed& fx) const
{
	return (this->fix_point_number > fx.fix_point_number);
}

bool Fixed::operator<(const Fixed& fx) const
{
	return (this->fix_point_number < fx.fix_point_number);
}

bool Fixed::operator>=(const Fixed& fx) const
{
	return (this->fix_point_number >= fx.fix_point_number);
}

bool Fixed::operator<=(const Fixed& fx) const
{
	return (this->fix_point_number <= fx.fix_point_number);
}

bool Fixed::operator==(const Fixed& fx) const
{
	return (this->fix_point_number == fx.fix_point_number);
}

bool Fixed::operator!=(const Fixed& fx) const
{
	return (this->fix_point_number != fx.fix_point_number);
}




Fixed	Fixed::operator+(const Fixed& fx) const
{
	return Fixed(this->toFloat() + fx.toFloat());
}

Fixed	Fixed::operator-(const Fixed& fx) const
{
	return Fixed(this->toFloat() - fx.toFloat());
}

Fixed	Fixed::operator*(const Fixed& fx) const
{
	return Fixed(this->toFloat() * fx.toFloat());
}

Fixed	Fixed::operator/(const Fixed& fx) const
{
	return Fixed(this->toFloat() / fx.toFloat());
}


Fixed& Fixed::operator++()
{
	this->fix_point_number++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++(*this);
	return (temp);
}

Fixed& Fixed::operator--()
{
	this->fix_point_number--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--(*this);
	return (temp);
}

Fixed& Fixed::min(Fixed& fx1, Fixed& fx2)
{
	if (fx1.operator<(fx2))
		return (fx1);
	return(fx2);
}

const Fixed& Fixed::min(const Fixed& fx1, const Fixed& fx2)
{
	if (fx1.operator<(fx2))
		return (fx1);
	return(fx2);
}

Fixed& Fixed::max(Fixed& fx1, Fixed& fx2)
{
	if (fx1.operator>(fx2))
		return (fx1);
	return(fx2);
}

const Fixed& Fixed::max(const Fixed& fx1, const Fixed& fx2)
{
	if (fx1.operator>(fx2))
		return (fx1);
	return(fx2);
}


std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}


int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fix_point_number);
}

void Fixed::setRawBits(int const raw)
{
	fix_point_number = raw;
}


float Fixed::toFloat() const
{
	return (static_cast<float>(fix_point_number) / (1 << bit));
}

int Fixed::toInt() const
{
	return (fix_point_number >> bit);
}
