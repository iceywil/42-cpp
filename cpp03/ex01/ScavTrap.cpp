/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:53:26 by a                 #+#    #+#             */
/*   Updated: 2025/06/03 04:04:03 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
	std::cout << "ScavTrap: Default constructor called." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src){
	std::cout << "ScavTrap: Copy constructor called." << std::endl;
	*this = src;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap: Constructor of " << this->_name << " called." << std::endl;
	ScavTrap::getPoints();
}

////////////DESTRUCTOR/////////////

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap: Destructor of " << this->_name << " called." << std::endl;
}



ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs) {
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return (*this);
}



int		ScavTrap::getAttackDamage(){
	return this->_attackDamage;
}

void	ScavTrap::attack(const std::string &target){
	if (this->_energyPoints <= 0)
		std::cout << "ScavTrap " << this->_name << " can't attack without Energy Points." << std::endl;
	if (this->_hitPoints <= 0)
		std::cout << "ScavTrap " << this->_name << " can't attack without Hit Points." << std::endl;
	else if (this->_energyPoints > 0 && this->_hitPoints > 0){
		this->_energyPoints--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
	ScavTrap::getPoints();
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap: " << this->_name<< " is now in Gate Keeper mode." << std::endl;
}
