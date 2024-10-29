/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:03:49 by drubio-m          #+#    #+#             */
/*   Updated: 2024/10/29 19:39:43 by drubio-m         ###   ########.fr       */
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
	this->_fixedPointValue = other._fixedPointValue;
}

// Constructor que toma un entero
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value << _fractionalBits;
}

// Constructor que toma un flotante
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(value * (1 << _fractionalBits));
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
		this->_fixedPointValue = other._fixedPointValue;
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

// Convierte a float desplazando un número a la izquierda fractional_bits veces y dividiendo
// Desplazar a la izquierda es equivalente a multiplicar x2
/*
Si _fixedPointValue es 256 y _fractionalBits es 8:

1 << 8: Es 256.
static_cast<float>(256): Es 256.0.
256.0 / 256: Es 1.0.
*/
float Fixed::toFloat(void) const
{
	return static_cast<float>(this->_fixedPointValue) / (1 << _fractionalBits);
}

// Convierte a int desplazando a la derecha el valor fractional_bits veces
int Fixed::toInt(void) const
{
	return this->_fixedPointValue >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

//  ******COMPARISON OPERATORS******
bool  Fixed::operator> (const Fixed &a)
{
    return this->getRawBits() > a.getRawBits();
}

bool  Fixed::operator< (const Fixed &a)
{
    return this->getRawBits() < a.getRawBits();
}

bool  Fixed::operator>= (const Fixed &a)
{
    return this->getRawBits() >= a.getRawBits();
}

bool  Fixed::operator<= (const Fixed &a)
{
    return this->getRawBits() <= a.getRawBits();
}

bool  Fixed::operator== (const Fixed &a)
{
    return this->getRawBits() == a.getRawBits();
}

bool  Fixed::operator!= (const Fixed &a)
{
    return this->getRawBits() != a.getRawBits();
}

//  ******ARITHMETIC OPERATORS******

Fixed   Fixed::operator+(const Fixed &a)
{
    return (a.toFloat() + this->toFloat());
}

Fixed   Fixed::operator-(const Fixed &a)
{
    return (a.toFloat() - this->toFloat());
}

Fixed   Fixed::operator*(const Fixed &a)
{
    return (a.toFloat() * this->toFloat());
}

Fixed   Fixed::operator/(const Fixed &a)
{
    return (a.toFloat() / this->toFloat());
}


//*******INCREMENTE/DECREMENT OPERATORS****
Fixed&   Fixed::operator++( void )
{
    ++this->_fixedPointValue;
    return *this;
}

Fixed   Fixed::operator++( int )
{
    Fixed tmp( *this );
    tmp._fixedPointValue = this->_fixedPointValue++;
    return tmp;
}

Fixed& Fixed::operator--( void )
{
    --this->_fixedPointValue;
    return *this;
}

Fixed Fixed::operator--( int )
{
    Fixed tmp( *this );
    tmp._fixedPointValue = this->_fixedPointValue--;
    return tmp;
}

//  ******OVERLOADED FUNCTIONS******

Fixed& Fixed::min( Fixed &a, Fixed &b )
{
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

Fixed& Fixed::max( Fixed &a, Fixed &b )
{
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}

const Fixed& Fixed::max( const Fixed &a, const Fixed &b )
{
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}
