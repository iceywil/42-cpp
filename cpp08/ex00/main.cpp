/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 18:28:50 by wscherre          #+#    #+#             */
/*   Updated: 2025/12/19 15:47:07 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>

#include "easyfind.hpp"

int main(void)
{
    std::vector<int> intvec;
    
    intvec.push_back(1);
    intvec.push_back(2);
    intvec.push_back(3);
    intvec.push_back(42);
    intvec.push_back(6);

    
    std::list<int> intlst;

    intlst.push_back(10);
    intlst.push_back(11);
    intlst.push_back(12);
    intlst.push_back(42);
    intlst.push_back(14);
    

    std::cout << "-----Test 1------" << std::endl;
    try{
        std::vector<int>::iterator it1 = easyfind(intvec, 42);
        std::cout << "Found in vector: " << *it1 << std::endl;
    }
    catch (std::exception &e){
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "-----Test 2------" << std::endl;
    try{
        std::vector<int>::iterator it2 = easyfind(intvec, 5);
        std::cout << "Found in vector: " << *it2 << std::endl;
    }
    catch (std::exception &e){
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-----Test 3------" << std::endl;
    try{
        std::list<int>::iterator it3 = easyfind(intlst, 42);
        std::cout << "Found in list: " << *it3 << std::endl;
    }
    catch (std::exception &e){
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-----Test 4------" << std::endl;
    try{
        std::list<int>::iterator it4 = easyfind(intlst, 13);
        std::cout << "Found in list: " << *it4 << std::endl;
    }
    catch (std::exception &e){
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}