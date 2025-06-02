/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 02:20:50 by a                 #+#    #+#             */
/*   Updated: 2025/03/21 21:08:58 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <string>

PhoneBook::PhoneBook()
{
	totalContacts = 0;
}

PhoneBook::~PhoneBook() {};

void PhoneBook::addContact()
{
	Contact	newContact;

	std::string input;
	input = "";
	std::cout << std::endl;
	do
	{
		std::cout << "Enter First Name : " << std::endl;
		std::cin >> input;
		if (std::cin.eof())
			return ;
		if (input == "")
			std::cout << "First Name cannot be empty." << std::endl;
		else if (!is_alphanum(input))
			std::cout << "First Name can only contain alphanum characters." << std::endl;
	} while (!is_alphanum(input) || input == "");
	newContact.setFirstName(input);
	input = "";
	do
	{
		std::cout << "Enter Last Name : " << std::endl;
		std::cin >> input;
		if (std::cin.eof())
			return ;
		if (input == "")
			std::cout << "Last Name cannot be empty." << std::endl;
		else if (!is_alphanum(input))
			std::cout << "Last Name can only contain alphanum characters." << std::endl;
	} while (!is_alphanum(input) || input == "");
	newContact.setLastName(input);
	input = "";
	do
	{
		std::cout << "Enter Nickname : " << std::endl;
		std::cin >> input;
		if (std::cin.eof())
			return ;
		if (input == "")
			std::cout << "Nickname cannot be empty." << std::endl;
		else if (!is_alphanum(input))
			std::cout << "Nickname can only contain alphanum characters." << std::endl;
	} while (!is_alphanum(input) || input == "");
	newContact.setNickName(input);
	input = "";
	do
	{
		std::cout << "Enter Phone Number : " << std::endl;
		std::cin >> input;
		if (std::cin.eof())
			return ;
		if (input == "")
			std::cout << "Phone Number cannot be empty." << std::endl;
		else if (!is_alphanum(input))
			std::cout << "Phone Number can only contain alphanum characters." << std::endl;
	} while (!is_alphanum(input) || input == "");
	newContact.setPhoneNumber(input);
	input = "";
	do
	{
		std::cout << "Enter Darkest Secret : " << std::endl;
		std::cin >> input;
		if (std::cin.eof())
			return ;
		if (input == "")
			std::cout << "Darkest Secret cannot be empty." << std::endl;
		else if (!is_alphanum(input))
			std::cout << "Darkest Secret can only contain alphanum characters." << std::endl;
	} while (!is_alphanum(input) || input == "");
	newContact.setDarkestSecret(input);
	if (PhoneBook::totalContacts == 8)
		PhoneBook::contacts[0] = newContact;
	else
	{
		PhoneBook::contacts[totalContacts] = newContact;
		PhoneBook::totalContacts += 1;
	}
}

void PhoneBook::displayContacts(void) const
{
	std::string input;

	if (PhoneBook::totalContacts == 0)
		std::cout << "You have no saved contacts." << std::endl;
	else
	{
		std::cout << std::setw(10) << "INDEX" << "|" << std::setw(10) << "FIRST NAME" << "|" << std::setw(10) << "LAST NAME" << "|" << std::setw(10) << "NICK NAME" << std::endl;
		for (int contact = 0; contact < PhoneBook::totalContacts; contact++)
		{
			std::cout << std::setw(10) << contact << "|";
			std::cout << std::setw(10) << cut_ten_char(PhoneBook::contacts[contact].getFirstName()) << "|";
			std::cout << std::setw(10) << cut_ten_char(PhoneBook::contacts[contact].getLastName()) << "|";
			std::cout << std::setw(10) << cut_ten_char(PhoneBook::contacts[contact].getNickName()) << std::endl;
		}
		std::cout << std::endl;
		input = "";
		do
		{
			std::cout << "Enter the index of the contact you want to consult :" << std::endl;
			std::cin >> input;
			if (std::cin.eof())
				return ;
			if (input == "")
				std::cout << "Index cannot be empty." << std::endl;
			else if (!ft_is_digits(input) || input == "8" || input == "9")
				std::cout << "Index can only contain a digit between 0 to 7." << std::endl;
			else if (std::stoi(input) > PhoneBook::totalContacts - 1)
				std::cout << "No contact saved at this index." << std::endl;
		} while (!ft_is_digits(input) || input == "" || input == "8"
			|| input == "9" || std::stoi(input) > PhoneBook::totalContacts - 1);
		searchContact(std::stoi(input));
	}
}

void PhoneBook::searchContact(int index) const
{
	std::cout << std::endl;
	std::cout << "Contact saved at index : " << index << std::endl;
	std::cout << "First Name : " << PhoneBook::contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name : " << PhoneBook::contacts[index].getLastName() << std::endl;
	std::cout << "NickName : " << PhoneBook::contacts[index].getNickName() << std::endl;
	std::cout << "Phone Number : " << PhoneBook::contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret : " << PhoneBook::contacts[index].getDarkestSecret() << std::endl;
}

bool	ft_is_digits(std::string &str)
{
	char	c;

	for (int i = 0; str[i]; i++)
	{
		c = str[i];
		if (!(c >= '0' && c <= '9'))
		{
			return (false);
		}
	}
	return (true);
}

std::string cut_ten_char(const std::string &str)
{
	if (str.size() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

bool	is_alphanum(const std::string &str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A'
					&& str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')))
		{
			return (false);
		}
	}
	return (true);
}
