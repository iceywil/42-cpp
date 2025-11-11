/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:51:06 by wscherre          #+#    #+#             */
/*   Updated: 2025/11/11 21:00:01 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <limits>
#include <sstream>

int	main(void)
{
	try
	{
		Intern intern;

		std::cout << "---" << std::endl;
		AForm *form = intern.makeForm("robotomy request", "Bender");
		delete form;
		std::cout << "---" << std::endl;
		form = intern.makeForm("shrubbery creation", "home");
		delete form;
		std::cout << "---" << std::endl;
		form = intern.makeForm("presidential pardon", "Zaphod");
		delete form;
		std::cout << "---" << std::endl;
		form = intern.makeForm("RandomForm", "none");
		delete form;
		std::cout << "---" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
