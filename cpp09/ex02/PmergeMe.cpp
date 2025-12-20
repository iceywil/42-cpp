/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:01:01 by wscherre          #+#    #+#             */
/*   Updated: 2025/12/20 16:24:54 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}
PmergeMe::PmergeMe(const PmergeMe &src)
{
	(void)src;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	(void)rhs;
	return (*this);
}
PmergeMe::~PmergeMe()
{
}

void PmergeMe::_fordJohnsonSort(std::vector<int> &vec)
{
	int	stray;

	if (vec.size() <= 1)
		return ;

	std::vector<std::pair<int, int>> pairs;
	stray = -1;
	for (size_t i = 0; i + 1 < vec.size(); i += 2)
	{
		pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
	}
	if (vec.size() % 2 != 0)
	{
		stray = vec.back();
	}

	for (size_t i = 0; i < pairs.size(); ++i)
	{
		if (pairs[i].first < pairs[i].second)
			std::swap(pairs[i].first, pairs[i].second);
	}

	std::vector<int> mainChain;
	std::vector<int> pendChain;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		mainChain.push_back(pairs[i].first);
		pendChain.push_back(pairs[i].second);
	}

	_fordJohnsonSort(mainChain);
	for (size_t i = 0; i < pendChain.size(); ++i)
	{
		std::vector<int>::iterator it = std::lower_bound(mainChain.begin(),
				mainChain.end(), pendChain[i]);
		mainChain.insert(it, pendChain[i]);
	}
	if (stray != -1)
	{
		std::vector<int>::iterator it = std::lower_bound(mainChain.begin(),
				mainChain.end(), stray);
		mainChain.insert(it, stray);
	}
	vec = mainChain;
}

void PmergeMe::_fordJohnsonSort(std::deque<int> &deq)
{
	int	stray;

	if (deq.size() <= 1)
		return ;
	std::deque<std::pair<int, int>> pairs;
	stray = -1;
	for (size_t i = 0; i + 1 < deq.size(); i += 2)
	{
		pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
	}
	if (deq.size() % 2 != 0)
		stray = deq.back();
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		if (pairs[i].first < pairs[i].second)
		{
			std::swap(pairs[i].first, pairs[i].second);
		}
	}
	std::deque<int> mainChain;
	std::deque<int> pendChain;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		mainChain.push_back(pairs[i].first);
		pendChain.push_back(pairs[i].second);
	}
	_fordJohnsonSort(mainChain);
	for (size_t i = 0; i < pendChain.size(); ++i)
	{
		std::deque<int>::iterator it = std::lower_bound(mainChain.begin(),
				mainChain.end(), pendChain[i]);
		mainChain.insert(it, pendChain[i]);
	}
	if (stray != -1)
	{
		std::deque<int>::iterator it = std::lower_bound(mainChain.begin(),
				mainChain.end(), stray);
		mainChain.insert(it, stray);
	}
	deq = mainChain;
}

void PmergeMe::process(char **argv)
{
	long	val;
	long	time_vec;
	long	time_deq;

	std::vector<int> vec;
	std::deque<int> deq;
	for (int i = 1; argv[i]; ++i)
	{
		std::stringstream ss(argv[i]);
		ss >> val;
		if (ss.fail() || !ss.eof() || val < 0 || val > INT_MAX)
		{
			std::cerr << "Error" << std::endl;
			return ;
		}
		vec.push_back(static_cast<int>(val));
		deq.push_back(static_cast<int>(val));
	}
	std::cout << "Before: ";
	for (size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	timeval start_vec, end_vec;
	gettimeofday(&start_vec, NULL);
	_fordJohnsonSort(vec);
	gettimeofday(&end_vec, NULL);
	time_vec = (end_vec.tv_sec - start_vec.tv_sec) * 1000000L + (end_vec.tv_usec
			- start_vec.tv_usec);
	std::cout << "After:  ";
	for (size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	timeval start_deq, end_deq;
	gettimeofday(&start_deq, NULL);
	_fordJohnsonSort(deq);
	gettimeofday(&end_deq, NULL);
	time_deq = (end_deq.tv_sec - start_deq.tv_sec) * 1000000L + (end_deq.tv_usec
			- start_deq.tv_usec);
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << time_vec << " us" << std::endl;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque:  " << time_deq << " us" << std::endl;
}
