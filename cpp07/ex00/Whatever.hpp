/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 18:23:42 by wscherre          #+#    #+#             */
/*   Updated: 2025/12/07 18:23:56 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
void swap(T &a, T &b){
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T const& min(T const& a, T const& b){
	return (a < b ? a : b);
}

template<typename T>
T const& max(T const& a, T const& b){
	return (a > b ? a : b);
}
