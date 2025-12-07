/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:36:46 by wscherre          #+#    #+#             */
/*   Updated: 2025/11/29 18:05:12 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm(target,
	72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src),
	_target(src._target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
		_target = rhs._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const
{
	if (this->getIsSigned() == false)
		throw(AForm::FormIsNotSigned());
	else if (bureaucrat.getGrade() > this->getExecutingGrade())
		throw(AForm::GradeTooLowException());

	std::cout << "BRRRRRRRRRRRRRRRRRRRRRR!!!!!!!!!" << std::endl;

	if (std::rand() % 2 == 0)
		std::cout << _target << " robotomized succesfully!" << std::endl;
	else
		std::cout << "Failed to robotomize " << _target << " !" << std::endl;
};
