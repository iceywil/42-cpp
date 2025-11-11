/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:51:06 by wscherre          #+#    #+#             */
/*   Updated: 2025/11/11 19:19:24 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <limits>
#include <sstream>

int	main(void)
{
	try
	{
		std::cout << "Bureaucrats creation =====" << std::endl << std::endl;
		Bureaucrat will("Will", 50);
		Bureaucrat tom("Tom", 5);
		Bureaucrat yay("Yay", 142);
		std::cout << will << std::endl;
		std::cout << tom << std::endl;
		std::cout << yay << std::endl;
		std::cout << "Forms creation =====" << std::endl << std::endl;
		ShrubberyCreationForm shrubForm("ShrubForm");
		RobotomyRequestForm roboForm("RobForm");
		PresidentialPardonForm pardonForm("PresForm");
		PresidentialPardonForm yayPresForm("yayPresForm");
		std::cout << shrubForm << std::endl;
		std::cout << roboForm << std::endl;
		std::cout << pardonForm << std::endl;
		std::cout << yayPresForm << std::endl;
		std::cout << "Signature Test =====" << std::endl << std::endl;
		will.signForm(shrubForm);
		std::cout << shrubForm << std::endl;
		tom.signForm(pardonForm);
		std::cout << pardonForm << std::endl;
		tom.signForm(roboForm);
		std::cout << roboForm << std::endl;
		yay.signForm(yayPresForm);
		std::cout << yayPresForm << std::endl;
		// try {
		//     tom.signForm(roboForm);
		// } catch (const std::exception &e) {
		//     std::cerr << "Error in Robotomy test : " << e.what() << std::endl;
		// }
		std::cout << "Execution test =====" << std::endl << std::endl;
		will.executeForm(shrubForm);
		tom.executeForm(pardonForm);
		yay.executeForm(shrubForm);
		std::cout << "Robotomy test =====" << std::endl << std::endl;
		tom.executeForm(roboForm);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception catched: " << e.what() << std::endl;
	}

	return (0);
}