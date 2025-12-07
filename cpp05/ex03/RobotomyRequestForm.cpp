/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:36:46 by wscherre          #+#    #+#             */
/*   Updated: 2025/11/29 18:14:25 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm(target,
	72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src),
	_target(src._target)
{
	std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	std::cout << "RobotomyRequestForm operator called" << std::endl;
	if (this != &rhs)
		_target = rhs._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const
{
	if (!getIsSigned())
		throw FormIsNotSigned();

	if (bureaucrat.getGrade() > this->getExecutingGrade())
		throw GradeTooLowException();

	std::cout << "BRRRRRRRRRRRRRRRRRRRRRR!!!!!!!!!" << std::endl;

	std::srand(std::time(0));
	if (std::rand() % 2 == 0)
		std::cout << _target << " robotomized succesfully!" << std::endl;
	else
		std::cout << "Failed to robotomize " << _target << " !" << std::endl;
};
