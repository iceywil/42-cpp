/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:53:29 by a                 #+#    #+#             */
/*   Updated: 2025/06/03 03:55:35 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(); //canonical
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &src); // copy constuctor (canonical)
		~ScavTrap();
		ScavTrap	&operator=(ScavTrap const &rhs); // = op overload (canonical)

		int		getAttackDamage();
		void	attack(const std::string &target);
		void	guardGate();
};
