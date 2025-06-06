/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:53:29 by a                 #+#    #+#             */
/*   Updated: 2025/06/04 22:23:46 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <string>

Dog::Dog() : Animal()
{
	_type = "Dog";
	std::cout << "Dog: Default constructor called." << std::endl;
}

Dog::Dog(Dog const &src) : Animal()
{
	std::cout << "Dog: Copy constructor called." << std::endl;
	*this = src;
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor called." << std::endl;
}

Dog &Dog::operator=(Dog const &rhs)
{
	std::cout << "Dog Assignation operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	this->_type = rhs._type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "WOOUF" << std::endl;
}
