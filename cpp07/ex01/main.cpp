/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 18:25:14 by wscherre          #+#    #+#             */
/*   Updated: 2025/12/18 13:31:39 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <iostream>

template <typename T> void printElem(T &x)
{
	std::cout << x << std::endl;
}

template <typename T> void minusss(T &x)
{
	x = x - 32;
}

int	main(void)
{
	char arr[] = {'b', 'o', 'n', 'j', 'o', 'u', 'r'};

	iter(arr, 7, printElem);
	std::cout << "------------------" << std::endl;
	iter(arr, 7, minusss);
	iter(arr, 7, printElem);
	int tab[] = {12, 23, 345, 3, 42, 24};
	std::cout << "------------------" << std::endl;
	iter(tab, 6, printElem);
	std::cout << "------------------" << std::endl;
	iter(tab, 6, minusss);
	iter(tab, 6, printElem);
}