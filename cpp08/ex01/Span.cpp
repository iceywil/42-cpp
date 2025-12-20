/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:04:00 by wscherre          #+#    #+#             */
/*   Updated: 2025/12/20 17:09:36 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0)
{
}

Span::Span(unsigned int n) : _maxSize(n)
{
}

Span::Span(const Span &src) : _maxSize(src._maxSize), _numbers(src._numbers)
{
}

Span &Span::operator=(const Span &src)
{
	if (this != &src)
	{
		_maxSize = src._maxSize;
		_numbers = src._numbers;
	}
	return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int num)
{
	if (_numbers.size() >= _maxSize)
		throw Span::NotEnoughSpaceInSpanException();
	_numbers.push_back(num);
}

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw Span::NotEnoughNumbersToFindASpanpanException();
	std::vector<int> tmp = _numbers;
	std::sort(tmp.begin(), tmp.end());

	int minSpan = tmp[1] - tmp[0];
	for (size_t i = 1; i < tmp.size() - 1; ++i)
	{
		int diff = tmp[i + 1] - tmp[i];
		if (diff < minSpan)
			minSpan = diff;
	}
	return (minSpan);
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw Span::NotEnoughNumbersToFindASpanpanException();

	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());

	return (max - min);
}
