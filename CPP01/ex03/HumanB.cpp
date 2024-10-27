/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:58:51 by drubio-m          #+#    #+#             */
/*   Updated: 2024/10/27 20:55:10 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {}

HumanB::~HumanB() {}

//you pass it as a reference and not as a pointer 
//in order to save the handling when the pointer is null.
void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void HumanB::attack()
{
    if (_weapon)
	{
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    } 
	else
	{
        std::cout << _name << " has no weapon to attack with!" << std::endl;
    }
}
