/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:22:42 by drubio-m          #+#    #+#             */
/*   Updated: 2024/11/01 09:31:47 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
// Constructor por defecto
FragTrap::FragTrap() : ClapTrap()
{
    _health = 100;
    _energy_points = 100;
    _attack_dmg = 30;
    std::cout << GREEN << "Default FragTrap constructor called for " << _name << RESET << std::endl;
}

// Constructor con nombre
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _health = 100;
    _energy_points = 100;
    _attack_dmg = 30;
    std::cout << GREEN << "Name FragTrap constructor called for " << _name << RESET << std::endl;
}

// Constructor de copia
FragTrap::FragTrap(const FragTrap &ft) : ClapTrap(ft)
{
    std::cout << GREEN << "FragTrap copy constructor called for " << _name << RESET << std::endl;
}

// Destructor
FragTrap::~FragTrap()
{
    std::cout << RED << "FragTrap destructor called for " << _name << RESET << std::endl;
}

// Operador de asignación
FragTrap &FragTrap::operator=(const FragTrap &ft)
{
    std::cout << "FragTrap " << this->_name << " assignment operator called" << std::endl;
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
