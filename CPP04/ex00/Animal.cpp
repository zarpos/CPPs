/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:19:44 by drubio-m          #+#    #+#             */
/*   Updated: 2024/11/01 10:31:31 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << GREEN << "Animal default constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << GREEN << "Animal copy constructor called" << RESET << std::endl;
	*this = copy;
}

Animal &Animal::operator=(const Animal &copy)
{
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &copy)
		this->_type = copy._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << RED << "Animal destructor called" << RESET << std::endl;
}

std::string Animal::getType(void) const
{
	return this->_type;
}

void Animal::setType(std::string type)
{
	this->_type = type;
}

void Animal::makeSound() const
{
	std::cout << YELLOW << "Random animal sound" << RESET << std::endl;
}

