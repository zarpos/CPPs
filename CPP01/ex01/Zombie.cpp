/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:55:44 by drubio-m          #+#    #+#             */
/*   Updated: 2024/10/27 10:31:39 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {}

Zombie::~Zombie()
{
    std::cout << RED << "Zombie " << _name << " has been destroyed." << RESET << std::endl;
}

void Zombie::announce()
{
    std::cout << GREEN << _name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

void Zombie::setName(std::string name)
{
	_name = name;
}
