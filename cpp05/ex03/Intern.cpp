/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:12:47 by wscherre          #+#    #+#             */
/*   Updated: 2025/11/29 18:08:22 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::Intern(const Intern &src)
{
	(void)src;
	std::cout << "Intern Copy Constructor called" << std::endl;
}

Intern &Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return (*this);
	std::cout << "Intern operator called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string formTypes[] = {"shrubbery creation", "robotomy request",
		"presidential pardon"};
	AForm *form = NULL;

	int formIndex = -1;
	for (int i = 0; i < 3; i++)
	{
		if (formName == formTypes[i])
		{
			formIndex = i;
			break;
		}
	}

	switch (formIndex)
	{
	case 0:
		form = new ShrubberyCreationForm(formTarget);
		break;
	case 1:
		form = new RobotomyRequestForm(formTarget);
		break;
	case 2:
		form = new PresidentialPardonForm(formTarget);
		break;
	default:
		throw Intern::FormDoesntExistException();
	}

	std::cout << "Intern creates " << formName << std::endl;
	return (form);
}

const char *Intern::FormDoesntExistException::what() const throw()
{
	return ("Form doesn't exist.");
}
