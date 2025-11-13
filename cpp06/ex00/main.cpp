/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:32:40 by wscherre          #+#    #+#             */
/*   Updated: 2025/11/12 13:52:42 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::string literal = argv[1];
		ScalarConverter::convert(literal);
		return 0;
	}
	std::cerr << "ONE AND ONLY ONE ARGUMENT NEEDED" << std::endl;
	return 1;
}