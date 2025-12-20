/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:05:30 by wscherre          #+#    #+#             */
/*   Updated: 2025/12/19 17:46:40 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template <typename T> class MutantStack : public std::stack<T>
{
  private:
  public:
	MutantStack()
	{
	}
	MutantStack(const MutantStack &other) : std::stack<T>(other)
	{
	}
	~MutantStack()
	{
	}

	MutantStack &operator=(const MutantStack &other)
	{
		std::stack<T>::operator=(other);
		return (*this);
	}

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	iterator begin()
	{
		return (this->c.begin());
	}
	iterator end()
	{
		return (this->c.end());
	}
};
