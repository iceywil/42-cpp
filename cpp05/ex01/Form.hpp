/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:10:19 by wscherre          #+#    #+#             */
/*   Updated: 2025/11/10 21:02:21 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <exception>
#include <iostream>
#include <iomanip>

class Bureaucrat;

class Form
{
	private:
		std::string const _name;
		bool _isSigned;
		int const _signingGrade;
		int const _executingGrade;

	public:
		Form();
		Form(std::string const name, int const signingGrade, int const executingGrade);
		Form(Form const &src);
		~Form();
		Form &operator=(Form const &rhs);
	
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

		
};

std::ostream &operator<<(std::ostream &o, Form &form);

#endif