/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:27:34 by drubio-m          #+#    #+#             */
/*   Updated: 2024/11/01 18:31:44 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << GREEN << "WrongAnimal default constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << GREEN << "WrongAnimal copy constructor called" << RESET << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "WrongAnimal destructor called" << RESET << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << YELLOW << "Random WrongAnimal sound" << RESET << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	std::cout << "WrongAnimal getType called" << std::endl;
	return this->_type;
}

void WrongAnimal::setType(std::string type)
{
	std::cout << "WrongAnimal setType called" << std::endl;
	this->_type = type;
}
