/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:53:29 by a                 #+#    #+#             */
/*   Updated: 2025/06/03 04:04:03 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class ClapTrap
{
  protected:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;

  public:
	ClapTrap();
	ClapTrap(ClapTrap const &src);
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap &operator=(ClapTrap const &rhs);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	
	void setHitPoints(int amount);
	void setAttackDamage(int amount);
	void setEnergyPoints(int amount);
	
	int getHitPoints();
	int getAttackDamage();
	int getEnergyPoints();

	void getPoints();
};
