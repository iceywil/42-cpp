/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 18:29:05 by wscherre          #+#    #+#             */
/*   Updated: 2025/12/07 18:29:07 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
#include <algorithm>


class ValueNotFoundException : public std::exception{
    public:
        virtual const char *what() const throw(){
            return ("Value not found!");
        }
        
};

template <typename T>
typename T::iterator easyfind(T& container, int value){
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw ValueNotFoundException();
    return it;
}