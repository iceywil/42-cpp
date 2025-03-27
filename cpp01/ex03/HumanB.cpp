/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:23:01 by a                 #+#    #+#             */
/*   Updated: 2025/03/26 23:23:10 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_weapon = nullptr;
    std::cout << "HumanB named " << _name << " has been created" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB named " << _name << " has been destroyed" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	std::cout << _name << " set Weapon to : " << weapon.getType() << std::endl;
}

void HumanB::attack(void)
{
	if (this->_weapon)
		std::cout << _name << " attacked with : " << this->_weapon->getType() << std::endl;
	else
		std::cout << _name << " attacked with bare hands!" << std::endl;
}
