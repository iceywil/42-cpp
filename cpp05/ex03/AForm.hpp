/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:10:19 by wscherre          #+#    #+#             */
/*   Updated: 2025/11/11 20:17:42 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <exception>
#include <iostream>
#include <iomanip>

class Bureaucrat;

class AForm
{
	private:
		std::string const _name;
		bool _isSigned;
		int const _signingGrade;
		int const _executingGrade;

	public:
		AForm();
		AForm(std::string const name, int const signingGrade, int const executingGrade);
		AForm(AForm const &src);
		virtual ~AForm();
		AForm &operator=(AForm const &rhs);
	
		const std::string getName() const;
		bool getIsSigned() const;
		int getSigningGrade() const;
		int getExecutingGrade() const;

		void beSigned(Bureaucrat bureaucrat);

		class GradeTooLowException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooHighException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class FormIsNotSigned : public std::exception{
			public:
				virtual const char *what() const throw();
		};

		virtual void execute(Bureaucrat const &bureaucrat) = 0;
};

std::ostream &operator<<(std::ostream &o, AForm &form);

#endif
