/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:36:43 by wscherre          #+#    #+#             */
/*   Updated: 2025/11/11 20:14:07 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class	Bureaucrat;

class Intern
{
  private:
  public:
	Intern();
	Intern(const Intern &src);
	Intern &operator=(Intern const &rhs);
	~Intern();

	AForm *makeForm(std::string formName, std::string formTarget);

	class FormDoesntExistException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
};

#endif
