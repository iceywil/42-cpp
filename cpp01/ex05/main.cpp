/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:21:55 by a                 #+#    #+#             */
/*   Updated: 2025/03/26 23:40:00 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) 
	{
		std::cout << "Error." << std::endl;
		std::cout << "Usage: ./harl [LEVEL]" << std::endl;
		std::cout  << "LEVEL = [DEBUG || INFO || WARNING || ERROR]" << std::endl;
		return (1);
	}
	Harl	harl;
	harl.complain(argv[1]);
	return (0);
}
