/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:51:06 by wscherre          #+#    #+#             */
/*   Updated: 2025/11/10 16:06:43 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat will("Will", 2);
		std::cout << will;
		will.incrGrade();
		std::cout << will;
		will.incrGrade();
		std::cout << will;
	}
	catch (std::exception &e)
	{
		std::cerr << "Bureaucrat Will : " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat tom("Tom", 149);
		std::cout << tom;
		tom.decrGrade();
		std::cout << tom;
		tom.decrGrade();
		std::cout << tom;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Bureaucrat Tom : " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat invalid("Invalid", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Bureaucrat Invalid :" << e.what() << std::endl;
	}
	return (0);
}
