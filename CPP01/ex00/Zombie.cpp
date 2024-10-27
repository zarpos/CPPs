/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:55:44 by drubio-m          #+#    #+#             */
/*   Updated: 2024/10/27 09:23:07 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

#include "Zombie.hpp"
#include <iostream>

// This is a list initialization, we are initializing _name with the value of name
// before the constructor is called to prevent _name from having a random value at first
Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie()
{
    std::cout << RED << "Zombie " << _name << " has been destroyed." << RESET << std::endl;
}

void Zombie::announce()
{
    std::cout << GREEN << _name << ": BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}
