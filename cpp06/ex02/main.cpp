/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:32:40 by wscherre          #+#    #+#             */
/*   Updated: 2025/12/01 16:40:12 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	std::srand(std::time(NULL));
	for (int i = 0; i < 10; i++)
	{
		Base *object = generate();
		identify(object);

		identify(*object);

		std::cout << "-----------------------" << std::endl;
		delete(object);
	}
	return (0);
}