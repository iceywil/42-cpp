/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:22:55 by a                 #+#    #+#             */
/*   Updated: 2025/03/26 23:22:57 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

int	main(void)
{
	Weapon club = Weapon("crude spiked club");
	std::cout << std::endl;

	HumanA bob("Bob", club);
	std::cout << std::endl;

	bob.attack();
	std::cout << std::endl;

	club.setType("some other type of club");
	std::cout << std::endl;

	bob.attack();
	std::cout << std::endl;

	club = Weapon("crude spiked club");
	std::cout << std::endl;
	//check if Weapon doesnt leak
	
	HumanB jim("Jim");
	std::cout << std::endl;

	jim.setWeapon(club);
	std::cout << std::endl;

	jim.attack();
	std::cout << std::endl;

	club.setType("some other type of club");
	std::cout << std::endl;

	jim.attack();
	std::cout << std::endl;

	return (0);
}
