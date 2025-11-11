/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:10:26 by wscherre          #+#    #+#             */
/*   Updated: 2025/11/10 21:12:46 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _isSigned(false), _signingGrade(0),
	_executingGrade(0)
{
	std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(std::string const name, int const signingGrade,
	int const executingGrade) : _name(name), _isSigned(false),
	_signingGrade(signingGrade), _executingGrade(executingGrade)
{
	if (signingGrade < 1 || executingGrade < 1)
	{
		throw(Form::GradeTooHighException());
	}
	if (signingGrade > 150 || executingGrade > 150)
	{
		throw(Form::GradeTooLowException());
	}
	std::cout << "Form Constructor called" << std::endl;
}

Form::Form(Form const &src) : _name(src._name), _isSigned(false),
	_signingGrade(src._signingGrade), _executingGrade(src._executingGrade)
{
	*this = src;
	std::cout << "Form Copy Constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form " << this->_name << " destructor called" << std::endl;
}

Form &Form::operator=(Form const &rhs)
{
	std::cout << "Form assignation operator overload called." << std::endl;
	if (this != &rhs)
		this->_isSigned = rhs._isSigned;
	return (*this);
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const std::string Form::getName() const
{
	return (this->_name);
}

bool	Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

int Form::getSigningGrade(void) const
{
	return (this->_signingGrade);
}

int	Form::getExecutingGrade(void) const
{
	return (this->_executingGrade);
}

void Form::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signingGrade)
		throw(Form::GradeTooLowException());
	this->_isSigned = true;
}


std::ostream &operator<<(std::ostream &o, Form &form)
{
	o << "Form " << form.getName();
	if (form.getIsSigned() == true)
		o << " is signed !" << std::endl;
	else
		o << " is not signed !" << std::endl;
	o << "Required grade to sign Form : " << form.getSigningGrade() << std::endl;
	o << "Required grade to execute Form : " << form.getExecutingGrade() << std::endl;
	return (o);
}