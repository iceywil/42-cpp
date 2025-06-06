/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:53:29 by a                 #+#    #+#             */
/*   Updated: 2025/06/05 17:36:52 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <string>

Animal::Animal()
{
	std::cout << "Animal: Default constructor called." << std::endl;
}

Animal::Animal(Animal const &src)
{
	std::cout << "Animal: Copy constructor called." << std::endl;
	*this = src;
}

Animal::~Animal()
{
	std::cout << "Animal: Destructor called." << std::endl;
}

Animal &Animal::operator=(Animal const &rhs)
{
	std::cout << "Animal Assignation operator called" << std::endl;
	if (this == &rhs)
		return *this;

	this->_type = rhs._type;
	return *this;
}

std::string Animal::getType() const{
    return this->_type;
}
