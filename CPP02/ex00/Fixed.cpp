/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:03:49 by drubio-m          #+#    #+#             */
/*   Updated: 2024/10/28 15:52:27 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructor normal
Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Constructor de copia
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPointValue = other.getRawBits();
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Operador de asignación
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	// Comprobamos que la dirección de memoria es diferente para evitar auto-asignaciones
	if (this != &other)
	{
		this->_fixedPointValue = other.getRawBits();
	}
	return (*this);
}

// Getter
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

// Setter
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}
