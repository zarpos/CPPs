/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:49:26 by drubio-m          #+#    #+#             */
/*   Updated: 2024/10/26 18:01:56 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>

void print_value(std::string str)
{
	if (str.length() > 10)
	{
		std::cout << str.substr(0, 9) << ".";
	}
	else
	{
		std::cout << std::setw(10) << std::setfill(' ') << str << std::flush;
	}
	std::cout << "|";
}

int	stringToInt(std::string& str)
{
	if (str == "ADD")
		return (1);
	else if (str == "SEARCH")
		return (2);
	else if (str == "EXIT")
		return (3);
	else
		return (4);
}

void	create_menu(void)
{
	std::cout << "TYPE AN OPTION:" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "ADD" << std::endl << "SEARCH" << std::endl << "EXIT" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "Your option: ";
}

void	show_menu(Phonebook p_book)
{
//	Contact	contact;
	int		choice;
	int		oldest;
	
	oldest = 0;
	do
	{
		create_menu();
		std::string str;
		std::getline(std::cin, str);
		if (std::cin.eof()==1)
			break ;
		choice = stringToInt(str);		
        if (choice == 1)
        {
            p_book.add_contact(oldest);
        }
        else if (choice == 2)
        {
            p_book.show_contact();
        }
        else if (choice == 3)
        {
            std::cout << "Bye!" << std::endl;
        }
        else
        {
            std::cout << "Wrong Option" << std::endl;
        }
	} while (choice != 3);
}

int main (int argc, char **argv)
{
	Phonebook	p_book;

	if (argc > 1 || argv[1])
	{
		std::cerr << "This program doesn't acept arguments" << std::endl;
		return (0);
	}
	show_menu(p_book);
	return (0);
}