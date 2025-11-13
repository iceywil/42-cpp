/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:32:40 by wscherre          #+#    #+#             */
/*   Updated: 2025/11/13 19:20:28 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data *data = new Data;
	data->name = "testname";
	data->age = 42;

	std::cout << "Original data pointer: " << data << std::endl;
	std::cout << "data->name: " << data->name << std::endl;
	std::cout << "data->age: " << data->age << std::endl;
	std::cout << "---" << std::endl;

	uintptr_t serialized_data = Serializer::serialize(data);
	Data *deserialized_data = Serializer::deserialize(serialized_data);

	std::cout << "Serialized data (uintptr_t): " << serialized_data << std::endl;
	std::cout << "Deserialized data pointer: " << deserialized_data << std::endl;
	std::cout << "---" << std::endl;

	std::cout << "Accessing data via deserialized pointer:" << std::endl;
	std::cout << "deserialized_data->name: " << deserialized_data->name << std::endl;
	std::cout << "deserialized_data->age: " << deserialized_data->age << std::endl;

	delete data;
	return (0);
}