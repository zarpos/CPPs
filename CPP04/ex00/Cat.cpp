/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:05:03 by drubio-m          #+#    #+#             */
/*   Updated: 2024/11/01 18:15:09 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << GREEN << "Cat default constructor called" << RESET << std::endl;
	this->setType("Cat");
}

Cat::Cat(const Cat &copy)
{
	std::cout << GREEN << "Cat copy constructor called" << RESET << std::endl;
	*this = copy;
}

Cat::~Cat()
{
	std::cout << RED << "Cat destructor called" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &copy)
		this->setType(copy.getType());
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << YELLOW << "Miau Miau" << RESET << std::endl;
}
