/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:35:40 by drubio-m          #+#    #+#             */
/*   Updated: 2024/11/01 09:42:26 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << GREEN << "Default claptrap constructor called" << RESET << std::endl;
	this->_name = "ct";
	this->_health = 10;
	this->_energy_points = 10;
	this->_attack_dmg = 0;
	return;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << GREEN << "ClapTrap constructor called" << RESET << std::endl;
	this->_name = name;
	this->_health = 10;
	this->_energy_points = 10;
	this->_attack_dmg = 0;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << RED << "ClapTrap destructor called" << RESET << std::endl;
	return;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ct)
{
	this->_name = ct._name;
	this->_health = ct._health;
	this->_energy_points = ct._energy_points;
	this->_attack_dmg = ct._attack_dmg;
	return *this;
}

ClapTrap::ClapTrap(const ClapTrap &ct)
{
	*this = ct;
	std::cout << GREEN << "Claptrap copy constructor called" << RESET << std::endl;
	return;
}

void ClapTrap::attack(const std::string &target)
{
	if (_energy_points < 1)
	{
		std::cout << "ClapTrap " << _name << " is exhausted!" << std::endl;
		return;
	}
	if (_health < 1)
	{
		std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_dmg << " points of damage!" << std::endl;
	_energy_points -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_health < 1)
	{
		std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage!" << std::endl;
	_health -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy_points < 1)
	{
		std::cout << "ClapTrap " << _name << " is exhausted" << std::endl;
		return;
	}
	if (_health < 1)
	{
		std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
		return;
	}
	std::cout << "Claptrap " << _name << " repaired himself " << amount << " hp" << std::endl;
	_energy_points -= 1;
	_health += amount;
}
