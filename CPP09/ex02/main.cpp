/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 00:08:59 by drubio-m          #+#    #+#             */
/*   Updated: 2025/05/05 02:12:05 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <chrono>
#include <vector>
#include <deque>
#include <sstream>
#include <ctime>

int main(int argc, char **argv)
{
	if (!PmergeMe::validateInput(argc, argv))
	{
		std::cerr << "Error\n";
		return 1;
	}

	
	// Crear contenedores
	
	/*Ventajas y desventajas de vector (Memoria cotigua)
	Ventajas: Acceso aleatorio rápido, mejor rendimiento en operaciones al final del contenedor (push_back, pop_back)
	Desventajas: Coste de inserción y eliminación en el medio alto, reubicación completa de memoria si se excede la capacidad
	*/

	/*Ventajas y desventajas de deque (Memoria no contigua)
	Ventajas: Inserción y eliminación rápida en ambos extremos, no requiere reubicación completa de memoria
	Desventajas: Acceso aleatorio más lento que vector, 
		mayor sobrecarga de memoria debido a la gestión de bloques (usa más memoria que vector para lo mismo) 
	*/
	PmergeMe::Vector vec;
	PmergeMe::Deque deq;
	

	// Llenar contenedores
	for (int i = 1; i < argc; ++i)
	{
		unsigned int num;
		std::istringstream iss(argv[i]);
		iss >> num;
		vec.push_back(num);
		deq.push_back(num);
	}

	// Mostrar antes
	PmergeMe::printContainer("Before: ", vec);

	// Medir tiempo para vector
	std::clock_t start = std::clock();
	PmergeMe::sortVector(vec);
	std::clock_t end = std::clock();
	// Calcular tiempo en microsegundos
	double vectorTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000; 

	// Medir tiempo para deque
    start = std::clock();
    PmergeMe::sortDeque(deq);
    end = std::clock();
	// Calcular tiempo en microsegundos
    double dequeTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

	// Mostrar después
	PmergeMe::printContainer("After: ", vec);

	// Mostrar tiempos
	PmergeMe::printTime("std::vector", vectorTime, vec.size());
	PmergeMe::printTime("std::deque", dequeTime, deq.size());

	return 0;
}
