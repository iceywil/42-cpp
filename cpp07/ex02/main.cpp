/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:03:33 by wscherre          #+#    #+#             */
/*   Updated: 2025/12/18 13:30:35 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	try
	{
		Array<int> arr(5);
		Array<char> charr(10);

		char content = 'a';

		for (unsigned int i = 0; i < arr.size(); i++)
			arr[i] = i * 10;
		for (unsigned int i = 0; i < arr.size(); i++)
			charr[i] = content++;

		std::cout << "Int Array contents: ";
		for (unsigned int i = 0; i < arr.size(); i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;

		std::cout << "Char Array contents: ";
		for (unsigned int i = 0; i < arr.size(); i++)
			std::cout << charr[i] << " ";
		std::cout << std::endl;

		Array<int> arrCopy = arr;
		arrCopy[0] = 999;

		std::cout << "Original arr[0]: " << arr[0] << std::endl;
		std::cout << "Copy arr[0]: " << arrCopy[0] << std::endl;

		std::cout << arr[10] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}