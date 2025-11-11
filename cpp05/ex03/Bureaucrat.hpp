/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:57:35 by wscherre          #+#    #+#             */
/*   Updated: 2025/11/11 19:06:28 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>
#include <iomanip>

class AForm;

class Bureaucrat
{
	private:
		std::string const _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &src);

		~Bureaucrat();
		
		Bureaucrat &operator=(Bureaucrat const &rhs);

		std::string getName() const;
		int getGrade() const;

		void incrGrade();
		void decrGrade();

		class GradeTooHighException : public std::exception{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public:
				virtual const char *what() const throw();
		};

		void signForm(AForm &form);

		void executeForm(AForm const &form);
};

std::ostream    &operator<<(std::ostream &o, Bureaucrat &bureaucrat);

#endif