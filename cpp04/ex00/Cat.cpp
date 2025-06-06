/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:15:39 by a                 #+#    #+#             */
/*   Updated: 2025/06/04 22:23:24 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <string>

Cat::Cat() : Animal()
{
	_type = "Cat";
	std::cout << "Cat: Default constructor called." << std::endl;
}

Cat::Cat(Cat const &src) : Animal()
{
	std::cout << "Cat: Copy constructor called." << std::endl;
	*this = src;
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor called." << std::endl;
}

Cat &Cat::operator=(Cat const &rhs)
{
	std::cout << "Cat Assignation operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	this->_type = rhs._type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Miaw" << std::endl;
}
