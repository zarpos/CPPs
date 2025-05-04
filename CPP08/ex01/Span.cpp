/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 02:40:14 by drubio-m          #+#    #+#             */
/*   Updated: 2025/05/04 02:43:13 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// inicializa el tamaño máximo y el vector vacío
Span::Span(unsigned int N) : _max_size(N) {}

// Añade un número al Span, lanza excepción si está lleno
void Span::addNumber(int num)
{
	if (_numbers.size() >= _max_size)
	{
		throw std::out_of_range("Span is full");
	}
	_numbers.push_back(num);
}

// Calcula la menor distancia (span) entre dos números
int Span::shortestSpan() const
{
	// Deben haber al menos dos números para calcular un span
	if (_numbers.size() < 2)
	{
		throw std::logic_error("Not enough elements");
	}
	// Copiamos y ordenamos los números para comparar adyacentes
	std::vector<int> sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());

	// Inicializamos el mínimo con la diferencia de los dos primeros
	int min_span = sorted[1] - sorted[0];
	// Recorremos el vector ordenado para comparar cada par adyacente
	for (size_t i = 2; i < sorted.size(); ++i)
	{
		int span = sorted[i] - sorted[i - 1];
		if (span < min_span)
		{
			min_span = span;
		}
	}
	return min_span;
}

// Calcula la mayor distancia (span) entre el menor y el mayor valor
int Span::longestSpan() const
{
	if (_numbers.size() < 2)
	{
		throw std::logic_error("Not enough elements");
	}
	// El span más largo es la diferencia entre el mayor y el menor
	std::vector<int> sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());
	return sorted.back() - sorted.front();
}
