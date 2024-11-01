/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:09:57 by drubio-m          #+#    #+#             */
/*   Updated: 2024/11/01 09:39:26 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructor por defecto
ScavTrap::ScavTrap() : ClapTrap()
{
    _health = 100;
    _energy_points = 50;
    _attack_dmg = 20;
    std::cout << GREEN << "Default ScavTrap constructor called for " << _name << RESET << std::endl;
}

// Constructor con nombre
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _health = 100;
    _energy_points = 50;
    _attack_dmg = 20;
    std::cout << GREEN << "Name ScavTrap constructor called for " << _name << RESET << std::endl;
}

// Constructor de copia
ScavTrap::ScavTrap(const ScavTrap &st) : ClapTrap(st)
{
    std::cout << GREEN << "ScavTrap copy constructor called for " << _name << RESET << std::endl;
}

// Destructor
ScavTrap::~ScavTrap()
{
    std::cout << RED << "ScavTrap destructor called for " << _name << RESET << std::endl;
}

// Operador de asignación
ScavTrap &ScavTrap::operator=(const ScavTrap &st)
{
    std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this != &st) {
        ClapTrap::operator=(st);
    }
    return *this;
}

// Redefinición del método attack()
void ScavTrap::attack(const std::string &target)
{
    if (_energy_points > 0) {
        std::cout << "ScavTrap " << _name << " attacks " << target 
                  << ", causing " << _attack_dmg << " points of damage!" << std::endl;
        _energy_points--;
    } else {
        std::cout << "ScavTrap " << _name << " has no energy left to attack." << std::endl;
    }
}

// Método guardGate()
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode." << std::endl;
}
