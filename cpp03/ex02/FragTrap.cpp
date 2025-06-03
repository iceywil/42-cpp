/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:53:26 by a                 #+#    #+#             */
/*   Updated: 2025/06/03 04:05:33 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(){
	std::cout << "FragTrap: Default constructor called." << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src){
	std::cout << "FragTrap: Copy constructor called." << std::endl;
	*this = src;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	//this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap: Constructor of "<< this->_name << " called." << std::endl;
	FragTrap::getPoints();
}



FragTrap::~FragTrap(){
	std::cout << "FragTrap: Destructor of "<< this->_name << " called." << std::endl;
}



FragTrap	&FragTrap::operator=(FragTrap const &rhs) {
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return (*this);
}



int		FragTrap::getAttackDamage(){
	return this->_attackDamage;
}

void	FragTrap::attack(const std::string &target){
	if (this->_energyPoints <= 0)
		std::cout << "FragTrap " << this->_name << " can't attack without Energy Points." << std::endl;
	if (this->_hitPoints <= 0)
		std::cout << "FragTrap " << this->_name << " can't attack without Hit Points." << std::endl;
	else if (this->_energyPoints > 0 && this->_hitPoints > 0){
		this->_energyPoints--;
		std::cout << "FragTrap "<< this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
	FragTrap::getPoints();
}

void	FragTrap::highFiveGuys(void){
	std::cout << "Hi I'm " << this->_name << " give me a high five! :)" << std::endl;
}