/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:53:29 by a                 #+#    #+#             */
/*   Updated: 2025/06/03 17:36:18 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Cat
{
	protected:
		std::string type;
	public:
		Cat();
		Cat(std::string type);
		Cat(Cat const &src);
		~Cat();
		Cat	&operator=(Cat const &rhs);

}
