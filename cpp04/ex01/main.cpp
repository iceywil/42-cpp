/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:16:40 by a                 #+#    #+#             */
/*   Updated: 2025/06/05 17:00:04 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{   
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	delete j;
	delete i;
	
	Animal* animals[100];

	for(int i = 0;i < 10;i++)
		animals[i] = new Dog();
	for(int i = 10;i < 20;i++)
		animals[i] = new Cat();
	for(int i = 0;i < 20;i++)
		animals[i]->makeSound();

	for(int i = 0;i < 20;i++)
		delete animals[i];

	
	Dog OGdog;
	Cat OGcat;
	
	OGdog.setIdea(0, "Mmmmh woof");
	OGdog.setIdea(1, "Mmh ?? Wouf wouf!");

	OGcat.setIdea(0, "Zzzzzz Brrrrr");
	OGcat.setIdea(1, "I'm an Og.");

	Dog COPYdog = OGdog;
	Cat COPYcat = OGcat;

	std::cout << "OGdog idea: " << OGdog.getIdea(0) << std::endl;
	std::cout << "OGdog idea: " << OGdog.getIdea(1) << std::endl;
	std::cout << "COPYdog idea: " << COPYdog.getIdea(0) << std::endl;
	std::cout << "COPYdog idea: " << COPYdog.getIdea(1) << std::endl;

	std::cout << "OGcat idea: " << OGcat.getIdea(0) << std::endl;
	std::cout << "OGcat idea: " << OGcat.getIdea(1) << std::endl;
	std::cout << "COPYcat idea: " << COPYcat.getIdea(0) << std::endl;
	std::cout << "COPYcat idea: " << COPYcat.getIdea(1) << std::endl;


	COPYdog.setIdea(0, "I'm a fake dog");
	COPYdog.setIdea(1, "Ssshhhhhh");
	COPYcat.setIdea(0, "meowww?");
	COPYcat.setIdea(1, "meowmeow");

	std::cout << "OGdog idea: " << OGdog.getIdea(0) << std::endl;
	std::cout << "OGdog idea: " << OGdog.getIdea(1) << std::endl;
	std::cout << "COPYdog idea: " << COPYdog.getIdea(0) << std::endl;
	std::cout << "COPYdog idea: " << COPYdog.getIdea(1) << std::endl;

	std::cout << "OGcat idea: " << OGcat.getIdea(0) << std::endl;
	std::cout << "OGcat idea: " << OGcat.getIdea(1) << std::endl;
	std::cout << "COPYcat idea: " << COPYcat.getIdea(0) << std::endl;
	std::cout << "COPYcat idea: " << COPYcat.getIdea(1) << std::endl;


    return 0;
}
