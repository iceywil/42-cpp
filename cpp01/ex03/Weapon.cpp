/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:22:48 by a                 #+#    #+#             */
/*   Updated: 2025/03/26 23:22:50 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>
#include <string>

Weapon::Weapon(std::string type)
{
	this->_type = type;
	std::cout << "Weapon named " << _type << " has been created" << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon named " << _type << " has been destroyed" << std::endl;
}

void Weapon::setType(std::string type)
{
	this->_type = type;
	std::cout << "Weapon named " << _type << " has been set " << std::endl;
}

const std::string &Weapon::getType() const
{
	return (this->_type);
}
