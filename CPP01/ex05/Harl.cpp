/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:24:17 by drubio-m          #+#    #+#             */
/*   Updated: 2024/10/27 22:38:00 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	mp["DEBUG"] = &Harl::debug;
	mp["INFO"] = &Harl::info;
	mp["WARNING"] = &Harl::warning;
	mp["ERROR"] = &Harl::error;
}

Harl::~Harl(){}

void    Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void    Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month" << std::endl;
}

void    Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::map<std::string, ft_ptr>::iterator 
	it = mp.begin();
	
	if (level.empty())
	{
		std::cout << "Empty level" << std::endl;
		return ;
	}
	
	while (it != mp.end())
	{
		// Compares the level passes as parameter with the one in the iterator
		if (level == it->first)
		{			
			(this->*(it->second))();
			break ;
		}		
		++it;
	}
	if (it == mp.end())
		std::cout << "Level: " << level << " not found" << std::endl;
}
