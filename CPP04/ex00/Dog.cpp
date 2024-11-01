/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:05:03 by drubio-m          #+#    #+#             */
/*   Updated: 2024/11/01 18:12:05 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << GREEN << "Dog default constructor called" << RESET << std::endl;
	this->setType("Dog");
}

Dog::Dog(const Dog &copy)
{
	std::cout << GREEN << "Dog copy constructor called" << RESET << std::endl;
	*this = copy;
}

Dog::~Dog()
{
	std::cout << RED << "Dog destructor called" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &copy)
		this->setType(copy.getType());
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << YELLOW << "Guau guau" << RESET << std::endl;
}
