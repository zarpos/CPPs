/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:33:39 by drubio-m          #+#    #+#             */
/*   Updated: 2024/10/26 18:07:20 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include <string>

// Getters
std::string Contact::GetFirstName(void)
{
	return _first_name;
}

std::string Contact::GetLastName(void)
{
	return _last_name;
}

std::string Contact::GetNickName(void)
{
	return _nickname;
}

std::string Contact::GetPhoneNumber(void)
{
	return _phone_number;
}

std::string Contact::GetDarkestSecret(void)
{
	return _darkest_secret;
}


// Setters

void Contact::SetFirstName(std::string FirstName)
{
	this->_first_name = FirstName;
}

void Contact::SetLastName(std::string LastName)
{
	this->_last_name = LastName;
}

void Contact::SetNickName(std::string NickName)
{
	this->_nickname = NickName;
}

void Contact::SetPhoneNumber(std::string PhoneNumber)
{
	this->_phone_number = PhoneNumber;
}

void Contact::SetDarkestSecret(std::string DarkestSecret)
{
	this->_darkest_secret = DarkestSecret;
}
