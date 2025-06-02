/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 02:20:52 by a                 #+#    #+#             */
/*   Updated: 2025/03/21 21:07:57 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>

bool	ft_is_digits(std::string &str);
std::string cut_ten_char(const std::string &str);
bool	is_alphanum(const std::string &str);

class PhoneBook
{
  private:
	Contact contacts[8];
	int totalContacts;

  public:
	PhoneBook();
	~PhoneBook();
	void addContact();
	void displayContacts() const;
	void searchContact(int index) const;
};

#endif