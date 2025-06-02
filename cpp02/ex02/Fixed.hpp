/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:06:02 by a                 #+#    #+#             */
/*   Updated: 2025/05/05 20:41:39 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Fixed
{
  private:
	int _value_fixed;
	static const int _nbBits;

  public:
	Fixed(void);
	Fixed(Fixed const &src);
	Fixed(int const int_to_fixed);
	Fixed(float const float_to_fixed);
	~Fixed(void);
	Fixed &operator=(Fixed const &rhs);
	void setRawBits(int const raw);
	int getRawBits(void) const;
	float toFloat(void) const;
	int toInt(void) const;
	bool operator>(Fixed const &rhs) const;
	bool operator<(Fixed const &rhs) const;
	bool operator>=(Fixed const &rhs) const;
	bool operator<=(Fixed const &rhs) const;
	bool operator==(Fixed const &rhs) const;
	bool operator!=(Fixed const &rhs) const;
	Fixed operator+(Fixed const &rhs) const;
	Fixed operator-(Fixed const &rhs) const;
	Fixed operator*(Fixed const &rhs) const;
	Fixed operator/(Fixed const &rhs) const;
	Fixed &operator++(); 
	Fixed &operator--();
	Fixed operator++(int);
	Fixed operator--(int);
	static Fixed &min(Fixed &n1, Fixed &n2);
	static Fixed const &min(Fixed const &n1, Fixed const &n2);
	static Fixed &max(Fixed &n1, Fixed &n2);
	static Fixed const &max(Fixed const &n1, Fixed const &n2);
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);