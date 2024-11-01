/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:34:09 by drubio-m          #+#    #+#             */
/*   Updated: 2024/11/01 18:35:25 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << GREEN << "WrongCat default constructor called" << RESET << std::endl;
	this->setType("WrongCat");
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << GREEN << "WrongCat copy constructor called" << RESET << std::endl;
	*this = copy;
}

WrongCat::~WrongCat()
{
	std::cout << RED << "WrongCat destructor called" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	std::cout << "WrongCat assignation operator called" << std::endl;
	if (this != &copy)
		this->setType(copy.getType());
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << YELLOW << "Wrong Miau ;( " << RESET << std::endl;
}
