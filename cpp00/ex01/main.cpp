/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 02:20:19 by a                 #+#    #+#             */
/*   Updated: 2025/03/19 19:31:03 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	PhoneBook PhoneBook;
	std::string input;

	while (true)
	{
		if (std::cin.eof())
		{
			std::cout << std::endl;
			break ;
		}
		std::cout << std::endl;
		std::cout << "Yo, welcome to your PhoneBook, you can use these commands : ADD, SEARCH and EXIT !" << std::endl;
		std::cout << std::endl;
		std::cin >> input;
		if (input == "ADD")
			PhoneBook.addContact();
		else if (input == "SEARCH")
			PhoneBook.displayContacts();
		else if (input == "EXIT")
			return (0);
		else if (input == "")
			return (0);
		else
			std::cout << std::endl << "Wrong Command" << std::endl;
	}
	return (0);
}