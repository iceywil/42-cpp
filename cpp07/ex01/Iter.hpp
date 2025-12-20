/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 18:24:37 by wscherre          #+#    #+#             */
/*   Updated: 2025/12/18 12:44:16 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
void	iter(T* array, int length, void (*func)(T  &)){
	for (int i = 0; i < length; i++)
		func(array[i]);
}

template<typename T>
void	iter(const T* array, int length, void (*func)(const T &)){
	for (int i = 0; i < length; i++)
		func(array[i]);
}