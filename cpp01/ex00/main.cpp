/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:23:01 by a                 #+#    #+#             */
/*   Updated: 2025/03/26 23:23:51 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	Zombie	*Charly;

	std::cout << std::endl;
	Charly = newZombie("Charly on the heap");
	Charly->announce();
	std::cout << std::endl;
	randomChump("Chumpy on the stack");
	std::cout << std::endl;
	delete (Charly);
}
