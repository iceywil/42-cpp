/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:04:11 by wscherre          #+#    #+#             */
/*   Updated: 2025/12/20 17:08:03 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <stdexcept>
#include <vector>

class Span
{
  private:
	unsigned int _maxSize;
	std::vector<int> _numbers;

  public:
	Span();
	Span(unsigned int n);
	Span(const Span &src);
	Span& operator=(const Span &src);
	~Span();

	void addNumber(int num);
	int shortestSpan() const;
	int longestSpan() const;

	class NotEnoughSpaceInSpanException : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Not enough space in Span!");
		}
	};

	class NotEnoughNumbersToFindASpanpanException : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Not enough numbers to find a span!");
		}
	};

	template <typename Iterator> void addRange(Iterator begin, Iterator end)
	{
		if (_numbers.size() + std::distance(begin, end) > _maxSize)
			throw NotEnoughSpaceInSpanException();
		_numbers.insert(_numbers.end(), begin, end);
	}
};
