/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:05:03 by drubio-m          #+#    #+#             */
/*   Updated: 2024/11/01 19:01:26 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << GREEN << "Dog default constructor called" << RESET << std::endl;
	this->_brain = new Brain();
	this->_type = "Dog";
	this->setType("Dog");
}

Dog::Dog(const Dog &copy)
{
	std::cout << GREEN << "Dog copy constructor called" << RESET << std::endl;
	*this = copy;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << RED << "Dog destructor called" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &copy)
	{
		delete _brain;
		this->_brain = new Brain(*copy._brain);
		this->setType(copy.getType());
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << YELLOW << "Guau guau" << RESET << std::endl;
}
