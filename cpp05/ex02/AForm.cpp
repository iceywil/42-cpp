/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:10:26 by wscherre          #+#    #+#             */
/*   Updated: 2025/11/29 18:05:12 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _signingGrade(0),
	_executingGrade(0)
{
}

AForm::AForm(std::string const name, int const signingGrade,
	int const executingGrade) : _name(name), _isSigned(false),
	_signingGrade(signingGrade), _executingGrade(executingGrade)
{
	if (signingGrade < 1 || executingGrade < 1)
	{
		throw(AForm::GradeTooHighException());
	}
	if (signingGrade > 150 || executingGrade > 150)
	{
		throw(AForm::GradeTooLowException());
	}
}

AForm::AForm(AForm const &src) : _name(src._name),
	_signingGrade(src._signingGrade), _executingGrade(src._executingGrade)
{
	this->_isSigned = src._isSigned;
}

AForm::~AForm()
{
}

AForm &AForm::operator=(AForm const &rhs)
{
	if (this != &rhs)
		this->_isSigned = rhs._isSigned;
	return (*this);
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char *AForm::FormIsNotSigned::what() const throw()
{
	return ("Form is not signed.");
}

const std::string AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

int AForm::getSigningGrade(void) const
{
	return (this->_signingGrade);
}

int	AForm::getExecutingGrade(void) const
{
	return (this->_executingGrade);
}

void AForm::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signingGrade)
		throw(AForm::GradeTooLowException());
	this->_isSigned = true;
}


std::ostream &operator<<(std::ostream &o, AForm &AForm)
{
	o << "AForm " << AForm.getName();
	if (AForm.getIsSigned() == true)
		o << " is signed !" << std::endl;
	else
		o << " is not signed !" << std::endl;
	o << "Required grade to sign AForm : " << AForm.getSigningGrade() << std::endl;
	o << "Required grade to execute AForm : " << AForm.getExecutingGrade() << std::endl;
	return (o);
}