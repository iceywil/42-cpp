/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 02:20:10 by a                 #+#    #+#             */
/*   Updated: 2025/03/13 02:46:18 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName(std::string &firstName)
{
	this->_firstName = firstName;
}

void Contact::setLastName(std::string &lastName)
{
	this->_lastName = lastName;
}

void Contact::setNickName(std::string &nickName)
{
	this->_nickName = nickName;
}

void Contact::setPhoneNumber(std::string &phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string &darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const
{
	return Contact::_firstName;
}

std::string Contact::getLastName() const
{
	return Contact::Contact::_lastName;
}

std::string Contact::getNickName() const
{
	return Contact::_nickName;
}

std::string Contact::getPhoneNumber() const
{
	return Contact::_phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
	return Contact::_darkestSecret;
}
