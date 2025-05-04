/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 02:39:35 by drubio-m          #+#    #+#             */
/*   Updated: 2025/05/04 02:41:49 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

// Almacena hasta N enteros y calcula distancias entre ellos
class Span
{
private:
	std::vector<int> _numbers; // Contenedor para los números
	unsigned int _max_size;	   // Capacidad máxima

public:
	// Constructor: recibe el tamaño máximo
	Span(unsigned int N);

	// Añade un solo número al Span
	void addNumber(int num);

	// Añade varios números usando un rango de iteradores
	// Es una función plantilla, debe ir en el header
	template <typename InputIt>
	void addNumbers(InputIt first, InputIt last)
	{
		// Calcula cuántos elementos nuevos se quieren añadir
		size_t numNew = std::distance(first, last);
		// Si al añadirlos se supera la capacidad, lanza excepción
		if (_numbers.size() + numNew > _max_size)
		{
			throw std::out_of_range("Span is full");
		}
		// Inserta los nuevos elementos al final del vector
		_numbers.insert(_numbers.end(), first, last);
	}

	// Calcula la menor distancia entre dos números almacenados
	int shortestSpan() const;

	// Calcula la mayor distancia entre dos números almacenados
	int longestSpan() const;
};

#endif
