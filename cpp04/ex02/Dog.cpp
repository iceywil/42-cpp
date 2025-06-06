/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:53:29 by a                 #+#    #+#             */
/*   Updated: 2025/06/05 17:05:06 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <string>

Dog::Dog() : Animal(), _brain(new Brain())
{
	_type = "Dog";
	std::cout << "Dog: Default constructor called." << std::endl;
}

Dog::Dog(Dog const &src) : Animal(src), _brain(new Brain(*src._brain))
{
	std::cout << "Dog: Copy constructor called." << std::endl;
	*this = src;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog: Destructor called." << std::endl;
}

Dog &Dog::operator=(Dog const &rhs)
{
	std::cout << "Dog Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		delete _brain;
		_brain = new Brain(*rhs._brain);
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "WOOUF" << std::endl;
}

void Dog::setIdea(int index, const std::string &idea)
{
	_brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
	return _brain->getIdea(index);
}
