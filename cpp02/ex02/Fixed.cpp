/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:06:05 by a                 #+#    #+#             */
/*   Updated: 2025/05/14 19:32:22 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_nbBits = 8;

Fixed::Fixed() : _value_fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int const int_to_fixed)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value_fixed = int_to_fixed * (1 << _nbBits);
}

Fixed::Fixed(float const float_to_fixed)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value_fixed = roundf(float_to_fixed * (1 << _nbBits));
	std::cout << _value_fixed << std::endl;
}




Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}




int		Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value_fixed);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value_fixed = raw;
}




int	Fixed::toInt() const
{
	return this->_value_fixed / (1 << _nbBits);
}

float	Fixed::toFloat() const
{
	return static_cast<float>(this->_value_fixed) / (1 << _nbBits);
}




Fixed	&Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this-> _value_fixed = rhs.getRawBits();
	return (*this); // return a reference
}


std::ostream &operator<<(std::ostream &out, Fixed const &rhs)
{
	out << rhs.toFloat();
	return out;
}







bool	Fixed::operator>(Fixed const &rhs) const
{
	return (this->_value_fixed > rhs._value_fixed);
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	return (this->_value_fixed < rhs._value_fixed);
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	return (this->_value_fixed >= rhs._value_fixed);
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	return (this->_value_fixed <= rhs._value_fixed);
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	return (this->_value_fixed == rhs._value_fixed);
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	return (this->_value_fixed != rhs._value_fixed);
}





Fixed	Fixed::operator+(Fixed const &rhs) const
{
	 return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(Fixed const &rhs) const
{
	 return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{
	 return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	 return (Fixed(this->toFloat() / rhs.toFloat()));
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Fixed	&Fixed::operator++() // pre incr
{
	this->_value_fixed++;
	return (*this);
}

Fixed	&Fixed::operator--() // pre decr
{
	this->_value_fixed--;
	return (*this);
}

Fixed	Fixed::operator++(int) // post incr
{
	Fixed tmp = *this;
	++*this;
	return (tmp);
}

Fixed	Fixed::operator--(int) // post incr
{
	Fixed tmp = *this;
	--*this;
	return (tmp);
}



Fixed	&Fixed::min(Fixed &n1, Fixed &n2)
{
	if (n1.getRawBits() < n2.getRawBits())
		return (n1);
	return (n2);
}

Fixed const	&Fixed::min(Fixed const &n1, Fixed const &n2)
{
	if (n1.getRawBits() < n2.getRawBits())
		return (n1);
	return (n2);
}

Fixed	&Fixed::max(Fixed &n1, Fixed &n2)
{
	if (n1.getRawBits() > n2.getRawBits())
		return (n1);
	return (n2);
}

Fixed const	&Fixed::max(Fixed const &n1, Fixed const &n2)
{
	if (n1.getRawBits() > n2.getRawBits())
		return (n1);
	return (n2);
}





