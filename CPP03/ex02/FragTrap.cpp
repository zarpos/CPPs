/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:22:42 by drubio-m          #+#    #+#             */
/*   Updated: 2024/10/31 18:23:15 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
// Constructor por defecto
FragTrap::FragTrap() : ClapTrap()
{
    _health = 100;
    _energy_points = 100;
    _attack_dmg = 30;
    std::cout << "Default FragTrap constructor called for " << _name << std::endl;
}

// Constructor con nombre
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _health = 100;
    _energy_points = 100;
    _attack_dmg = 30;
    std::cout << "Name FragTrap constructor called for " << _name << std::endl;
}

// Constructor de copia
FragTrap::FragTrap(const FragTrap &ft) : ClapTrap(ft)
{
    std::cout << "FragTrap copy constructor called for " << _name << std::endl;
}

// Destructor
FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called for " << _name << std::endl;
}

// Operador de asignación
FragTrap &FragTrap::operator=(const FragTrap &ft)
{
    std::cout << "FragTrap assignment operator called" << std::endl;
    if (this != &ft) {
        ClapTrap::operator=(ft);
    }
    return *this;
}

// Método específico de FragTrap para pedir un high five
void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << _name << " says: High five, guys!" << std::endl;
}
