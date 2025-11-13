/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:40:37 by wscherre          #+#    #+#             */
/*   Updated: 2025/11/13 19:20:02 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iomanip>
# include <iostream>
# include <stdint.h>
# include <string>

typedef struct Data
{
	std::string name;
	int		age;
	Data	*next;
}			Data;

class Serializer
{
  private:
	Serializer();
	Serializer(const Serializer &src);

  public:
	~Serializer();

	Serializer &operator=(const Serializer &rhs);

	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif