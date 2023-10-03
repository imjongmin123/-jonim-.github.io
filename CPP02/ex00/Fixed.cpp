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

Fixed& Fixed::operator=(const Fixed& fx)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fix_point_number = fx.getRawBits();
	return (*this);
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
