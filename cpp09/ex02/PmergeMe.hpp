/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:01:13 by wscherre          #+#    #+#             */
/*   Updated: 2025/12/20 16:22:26 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <sstream>
# include <algorithm>
# include <sys/time.h>
# include <climits>

class PmergeMe {
    private:
        PmergeMe();
        PmergeMe(const PmergeMe& src);
        PmergeMe& operator=(const PmergeMe& rhs);
        ~PmergeMe();

        static void _fordJohnsonSort(std::vector<int>& vec);
        static void _fordJohnsonSort(std::deque<int>& deq);

    public:
        static void process(char **argv);
};

#endif
