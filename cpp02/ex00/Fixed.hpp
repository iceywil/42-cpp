/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:06:02 by a                 #+#    #+#             */
/*   Updated: 2025/05/05 19:27:44 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Fixed
{
  private:
	int _value;
	static const int _nbBits;

  public:
	Fixed(void);
	Fixed(Fixed const &src);
	~Fixed(void);
	Fixed &operator=(Fixed const &rhs);
	void setRawBits(int const raw);
	int getRawBits(void) const;
};