/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:53:26 by a                 #+#    #+#             */
/*   Updated: 2025/06/03 04:04:03 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClatTrap: Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << "ClatTrap: Copy constructor called." << std::endl;
	*this = src;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10),
	_energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap: Constructor of " << this->_name << " called." << std::endl;
	ClapTrap::getPoints();
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: Destructor of " << this->_name << " called." << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return (*this);
}

void ClapTrap::setAttackDamage(int attackDamage)
{
	this->_attackDamage = attackDamage;
	std::cout << "ClapTrap " << this->_name << " Attack Damage has been set to " << this->_attackDamage << "." << std::endl;
}

int ClapTrap::getHitPoints()
{
	return (this->_hitPoints);
}

int ClapTrap::getEnergyPoints()
{
	return (this->_energyPoints);
}



void	ClapTrap::getPoints(){
	std::cout << "ClapTrap " << this->_name << " has:" << std::endl;
	std::cout << "   " << this->_hitPoints << " Hit points left." << std::endl;
	std::cout << "   " << this->_energyPoints << " Energy points left." << std::endl;
	std::cout << "   " << this->_attackDamage << " Attack damage." << std::endl;
	std::cout << std::endl;
}



void ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints <= 0)
		std::cout << "Claptrap " << this->_name << " can't attack without Energy Points." << std::endl;
	if (this->_hitPoints <= 0)
		std::cout << "Claptrap " << this->_name << " can't attack without Hit Points." << std::endl;
	else if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage !" << std::endl;
	}
	ClapTrap::getPoints();
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	std::cout  << "Claptrap "  << this->_name   << " took " << amount << " damage after being attacked!"  << std::endl;
	ClapTrap::getPoints();
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0)
		std::cout  << "Claptrap " << this->_name << " can't be repaired without Energy Points."  << std::endl;
	if (this->_hitPoints <= 0)
		std::cout  << "Claptrap " << this->_name << " can't be repaired without Hit Points."  << std::endl;
	else if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout  << "ClapTrap " << this->_name   << " got repaired for " << amount << " Hit Points." << std::endl;
	}
	ClapTrap::getPoints();
}