/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:15:39 by a                 #+#    #+#             */
/*   Updated: 2025/06/04 20:34:08 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <string>

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat: Default constructor called." << std::endl;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal()
{
	std::cout << "WrongCat: Copy constructor called." << std::endl;
	*this = src;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Destructor called." << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs)
{
	std::cout << "WrongCat Assignation operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	this->_type = rhs._type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong Wouf" << std::endl;
}
