/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:22:00 by a                 #+#    #+#             */
/*   Updated: 2025/03/26 23:41:37 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>
class Harl
{
  private:
	void _debug(void);
	void _info(void);
	void _warning(void);
	void _error(void);

  public:
	Harl(void);
	~Harl(void);
	void complain(std::string level);
};

#endif
