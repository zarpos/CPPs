/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:45:07 by drubio-m          #+#    #+#             */
/*   Updated: 2025/04/29 23:51:16 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
private:
	T *_elements;
	unsigned int _size;

public:
	Array();							// Constructor vacío
	explicit Array(unsigned int n);		// Constructor con tamaño
	Array(const Array &src);			// Copy constructor
	Array &operator=(const Array &rhs); // Assignment operator
	~Array();							// Destructor

	T &operator[](unsigned int index);			   // Acceso con verificación
	const T &operator[](unsigned int index) const; // Versión constante
	unsigned int size() const;			   // Tamaño del array
};

#include "Array.tpp"

#endif
