/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:02:47 by drubio-m          #+#    #+#             */
/*   Updated: 2024/10/29 19:34:19 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>

class Fixed
{
private:
	int _fixedPointValue;
	static const int _fractionalBits = 8;

public:
	// Constructor por defecto
	Fixed();
	~Fixed();
	// Constructor que toma un int
	Fixed(const int value);
	// Constructor que toma un float
	Fixed(const float value);
	// Constructor de copia
	Fixed(const Fixed &other);
	// Operador de asignación
	Fixed &operator=(const Fixed &other);
	// Functions
	// Other
	float toFloat(void) const;
	int toInt(void) const;
	//  Getter
	int getRawBits(void) const;
	// Setter
	void setRawBits(int const raw);
	

	//  ******COMPARISON OPERATORS******
    bool    operator> (const Fixed &a);
    bool    operator< (const Fixed &a);
    bool    operator>= (const Fixed &a);
    bool    operator<= (const Fixed &a);
    bool    operator== (const Fixed &a);
    bool    operator!= (const Fixed &a);

//  ******ARITHMETIC OPERATORS******
    Fixed    operator+ (const Fixed &a);
    Fixed    operator- (const Fixed &a);
    Fixed    operator* (const Fixed &a);
    Fixed    operator/ (const Fixed &a);
    
//  ******INCREMENT/DECREMENT OPERATORS******
	// Pre-increment, returns value of variable incremented
    Fixed&    operator++ ();
	// Post-increment, returns value of variable before increment
    Fixed    operator++ (int);
    Fixed&    operator-- ();
    Fixed    operator-- (int);

//  ******OVERLOADED FUNCTIONS******

    static Fixed&  min(Fixed &f1, Fixed &f2);
    static const Fixed& min(const Fixed& f1, const Fixed& f2);
    static Fixed& max(Fixed &f1, Fixed &f2);
    static const Fixed& max(const Fixed& f1, const Fixed& f2);
};

/**
 * @brief Sobrecarga del operador de inserción para la clase Fixed.
 *
 * std::ostream puede escribir en todo, no solo en la salida estándar
 * Esta función permite insertar un objeto Fixed en un flujo de salida (como std::cout).
 * Convierte el valor de punto fijo a un valor de punto flotante y lo inserta en el flujo.
 *
 * @param out El flujo de salida en el que se insertará el valor. En este caso cout
 * @param fixed El objeto Fixed que se va a insertar en el flujo.
 * @return std::ostream& Una referencia al flujo de salida, permitiendo el encadenamiento de operadores.
 */
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif