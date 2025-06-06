/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:02:01 by a                 #+#    #+#             */
/*   Updated: 2025/06/05 18:02:19 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class ICharacter
{
  public:
	virtual ~ICharacter()
	{
	}
	virtual std::string const &getName() const = 0;
	virtual void equip(AMateria *m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter &target) = 0;
};
