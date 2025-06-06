/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:53:29 by a                 #+#    #+#             */
/*   Updated: 2025/06/05 16:54:43 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <string>
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain: Default constructor called." << std::endl;
}

Brain::Brain(Brain const &src)
{
	std::cout << "Brain: Copy constructor called." << std::endl;
	*this = src;
}

Brain::~Brain()
{
	std::cout << "Brain: Destructor called." << std::endl;
}

Brain &Brain::operator=(Brain const &rhs)
{
	std::cout << "Brain Assignation operator called" << std::endl;
	if (this == &rhs)
		return *this;

	for (int i = 0; i < 100; i++)
		this->_ideas[i] = rhs._ideas[i];
	return *this;
}

void Brain::setIdea(int index, const std::string &idea)
{
	if (index >= 0 && index < 100)
		this->_ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return this->_ideas[index];
	return "";
}    
