/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:04:48 by wscherre          #+#    #+#             */
/*   Updated: 2025/12/19 16:59:35 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <iostream>

int	main(void)
{
	try
	{
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		std::cout << "10k Test: " << sp.longestSpan() << std::endl;

		Span bigSpan(10000);
		std::vector<int> data;
		for (int i = 0; i < 10000; ++i)
			data.push_back(rand());

		bigSpan.addRange(data.begin(), data.end());
		std::cout << "Shortest (big): " << bigSpan.shortestSpan() << std::endl;
		std::cout << "Longest (big): " << bigSpan.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return (0);
}
