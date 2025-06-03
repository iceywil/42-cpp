/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:53:29 by a                 #+#    #+#             */
/*   Updated: 2025/06/03 17:35:16 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string type);
		Animal(Animal const &src);
		~Animal();
		Animal	&operator=(Animal const &rhs);

}
