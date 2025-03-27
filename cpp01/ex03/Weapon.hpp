/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:22:40 by a                 #+#    #+#             */
/*   Updated: 2025/03/26 23:22:42 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
  private:
	std::string _type;

  public:
  	Weapon(std::string type);
	~Weapon(void);
	const std::string &getType() const;
	void setType(std::string type);
};


#endif
