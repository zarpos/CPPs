/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:18:46 by drubio-m          #+#    #+#             */
/*   Updated: 2024/11/01 22:22:59 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
	//std::cout << "Default Cure constructor" << std::endl;
}

Cure::Cure(const Cure &other)
{
	*this = other;
	//std::cout << "Cure copy constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

Cure::~Cure() {}

AMateria *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
