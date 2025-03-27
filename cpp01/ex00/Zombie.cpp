/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:23:01 by a                 #+#    #+#             */
/*   Updated: 2025/03/26 23:24:02 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(std::string name)
{
    this->_name = name;
    std::cout << "Zombie named " << _name << " has been created" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie named " << _name << " has been destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
