/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:54:23 by drubio-m          #+#    #+#             */
/*   Updated: 2024/10/26 18:04:51 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <string>
#include <iostream>
#include <sstream>

Contact Phonebook::GetContact(int index)
{
	return _contacts[index];
}

void Phonebook::SetContact(Contact contact, int i)
{
    _contacts[i] = contact;   
}

void Phonebook::add_contact(int& last_contact)
{
	int i;
	for (i = 0; i < 8; i++)
	{
		if (this->GetContact(i).GetFirstName().empty())
		{
			this->SetContact(new_contact(), i);
			std::cout << "Contact Added" << std::endl;
		//	last_contact++;
			break;
		}
		if (i == 7)
		{
			this->SetContact(this->new_contact(), last_contact);
			last_contact++;
			if (last_contact == 8)
				last_contact = 0;
		}
	}
}

void	Phonebook::show_contact(void)
{
	int			num;
	std::string	index;
	std::string str;
	std::stringstream s1;

	num = 0;
	std::cout << "---------------------------------------------"  << std::endl;
	std::cout << "|     Index|" << "  1st name|" << " Last name|" << "  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|"  << std::endl;
	for(int	i = 0; i < 8; i++)
	{
		std::cout << "|"; 
		s1.str("");
        s1.clear();   
		s1 << i + 1;
		str = s1.str();
		print_value(str);
		print_value(this->GetContact(i).GetFirstName());
		print_value(this->GetContact(i).GetLastName());
		print_value(this->GetContact(i).GetNickName());
		std::cout << std::endl;
		if (i != 7)
			std::cout << "|----------|----------|----------|----------|"  << std::endl;
	}
	std::cout << "---------------------------------------------"  << std::endl;

	std::cout << "Select an index between 1 and 8: ";
	std::getline(std::cin, str);
	index = str;
	try
	{
		std::stringstream ss(index);
		ss >> num;
	}
	catch(const std::exception& e)
	{
		std::cout << std::endl << "That was not a number!" << std::endl << std::endl;
	}	
	if (num > 0 && num < 9)
		this->show_full_contact(this->GetContact(num - 1));
	else
		std::cout << std::endl << "Wrong index!" << std::endl << std::endl;
}

Contact	Phonebook::new_contact(void)
{
	Contact contact;
	
	std::string str;
	do
	{
		std::cout << "First name:";
		std::getline(std::cin, str);
	}while(str.empty());		
	contact.SetFirstName(str);
	do
	{
		std::cout << "Last name:";
		std::getline(std::cin, str);
	}while(str.empty());
	contact.SetLastName(str);
	do
	{		
		std::cout << "Nickname:";
		std::getline(std::cin, str);
	}while(str.empty());	
	contact.SetNickName(str);
	do
	{				
		std::cout << "Phone number:";
		std::getline(std::cin, str);
	}while(str.empty());
	contact.SetPhoneNumber(str);
	do
	{				
		std::cout << "Darkest secret:";
		std::getline(std::cin, str);
	}while(str.empty());	
	contact.SetDarkestSecret(str);
	std::cout << std::endl;	
	return (contact);
}

void	Phonebook::show_full_contact(Contact contact)
{
	if (contact.GetFirstName().empty())
	{
		std::cout << "Nothing to see here 👀" << std::endl;
		return ;
	}
	std::cout << "First name: ";
	std::cout << contact.GetFirstName() << std::endl;
	std::cout << "Last name: ";
	std::cout << contact.GetLastName() << std::endl;
	std::cout << "Nickname: ";
	std::cout << contact.GetNickName() << std::endl;
	std::cout << "Phone number: ";
	std::cout << contact.GetPhoneNumber() << std::endl;
	std::cout << "Darkest secret: ";
	std::cout << contact.GetDarkestSecret() << std::endl;
}
