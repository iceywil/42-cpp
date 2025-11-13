/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:40:37 by wscherre          #+#    #+#             */
/*   Updated: 2025/11/13 20:52:46 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <ctime>
#include <exception>
#include <cstdlib>

class Base
{
  public:
	virtual ~Base();
};

class A : public Base
{
};
class B : public Base
{
};
class C : public Base
{
};

Base	*generate(void);

void	identify(Base *p);

void	identify(Base &p);