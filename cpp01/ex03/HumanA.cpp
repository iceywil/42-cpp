/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:23:01 by a                 #+#    #+#             */
/*   Updated: 2025/03/26 23:23:21 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>
#include <string>

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	std::cout << "HumanA named " << _name << " has been created" << std::endl;
	std::cout << "HumanA named " << _name << " has " << weapon.getType() << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA named " << _name << " has been destroyed" << std::endl;
}

void HumanA::attack(void)
{
	std::cout << _name << " attacked with : " << this->_weapon.getType() << std::endl;
}
