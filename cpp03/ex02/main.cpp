/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:52:55 by a                 #+#    #+#             */
/*   Updated: 2025/06/03 04:02:07 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap ClapA("ClapA");
	ClapTrap ClapB("ClapB");
	ClapTrap ClapC("ClapC");
	ClapTrap ClapD("ClapD");
	ScavTrap ScavA("ScavA");
	ScavTrap ScavB("ScavB");
	FragTrap FragA("FragA");
	FragTrap FragB("FragB");


	ClapA.setAttackDamage(10);
	ClapA.attack("ClapC");
	if (ClapA.getHitPoints() > 0 && ClapA.getEnergyPoints() > 0)
		ClapC.takeDamage(10);
	ClapC.beRepaired(10);
	ClapD.setAttackDamage(2);
	for (int i = 0; i < 10; i++){
		ClapD.attack("ClapB");
		if (ClapD.getHitPoints() > 0 && ClapD.getEnergyPoints() > 0)
			ClapB.takeDamage(2);
		ClapB.beRepaired(1);
	}
	ScavA.attack("ScavB");
	if (ScavA.getHitPoints() > 0 && ScavA.getEnergyPoints() > 0)
		ScavB.takeDamage(ScavA.getAttackDamage());
	ScavA.guardGate();
	FragA.attack("FragB");
	if (FragA.getHitPoints() > 0 && FragA.getEnergyPoints() > 0)
		FragB.takeDamage(FragA.getAttackDamage());
	FragA.highFiveGuys();
}
