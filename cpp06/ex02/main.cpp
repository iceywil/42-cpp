/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:32:40 by wscherre          #+#    #+#             */
/*   Updated: 2025/11/13 21:19:54 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		std::srand(std::time(NULL) + std::clock());

		Base *object = generate();
		identify(object);

		identify(*object);

		std::cout << "-----------------------" << std::endl;
		delete(object);
	}
	return (0);
}