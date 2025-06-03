/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:53:29 by a                 #+#    #+#             */
/*   Updated: 2025/06/03 17:36:08 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Dog
{
	protected:
		std::string type;
	public:
		Dog();
		Dog(std::string type);
		Dog(Dog const &src);
		~Dog();
		Dog	&operator=(Dog const &rhs);

}
