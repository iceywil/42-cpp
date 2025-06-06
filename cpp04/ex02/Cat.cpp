/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:15:39 by a                 #+#    #+#             */
/*   Updated: 2025/06/05 17:05:22 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <string>

Cat::Cat() : Animal(), _brain(new Brain())
{
	_type = "Cat";
	std::cout << "Cat: Default constructor called." << std::endl;
}

Cat::Cat(Cat const &src) : Animal(src), _brain(new Brain(*src._brain))
{
	std::cout << "Cat: Copy constructor called." << std::endl;
	*this = src;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat: Destructor called." << std::endl;
}

Cat &Cat::operator=(Cat const &rhs)
{
	std::cout << "Cat Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		delete _brain;
		_brain = new Brain(*rhs._brain);
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Miaw" << std::endl;
}

void Cat::setIdea(int index, const std::string &idea)
{
	_brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
	return _brain->getIdea(index);
}
