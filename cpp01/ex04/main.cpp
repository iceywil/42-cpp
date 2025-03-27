/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:08:52 by a                 #+#    #+#             */
/*   Updated: 2025/03/27 00:19:55 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"


int main (int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "bro you need to pass 3 arguments : filename, s1, s2" << std::endl;
		return (0);
	}
	replace(argv[1], argv[2], argv[3]);
	return (0);
}