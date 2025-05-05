/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 00:08:24 by drubio-m          #+#    #+#             */
/*   Updated: 2025/05/05 02:01:25 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <iterator>

// Validación de entrada
bool PmergeMe::validateInput(int argc, char **argv)
{
	if (argc < 2)
		return false;

	for (int i = 1; i < argc; ++i)
	{
		std::string str = argv[i];
		
		// Valida que no sea una cadena vacía y que contenga solo dígitos
		if (str.empty() || !std::all_of(str.begin(), str.end(), ::isdigit))
			return false;
		
		// Convierte el string a unsigned long y verifica que no exceda el rango de unsigned int
		unsigned long num;
		
		// Convertimos el string a un stream para así poder usar el operador >> y verificar si la conversión fue exitosa
		std::istringstream iss(str); // str = argv[i]
		
		// std::numeric_limits<unsigned int>::max() devuelve el valor máximo que puede almacenar un unsigned int
		// y lo convierte a unsigned long para evitar problemas de rango
		if (!(iss >> num) || num > static_cast<unsigned long>(std::numeric_limits<unsigned int>::max()))
			return false;
	}
	return true;
}

// Algoritmo principal para vector
void PmergeMe::sortVector(Vector &vec)
{
	mergeInsertSort(vec);
}

// Algoritmo principal para deque
void PmergeMe::sortDeque(Deque &deq)
{
	mergeInsertSort(deq);
}

// Implementación del algoritmo Ford-Johnson
template <typename Container>
void PmergeMe::mergeInsertSort(Container &c)
{
	// 1. Caso base: si el contenedor tiene 0 o 1 elemento, ya está ordenado
	if (c.size() <= 1)
		return;
	// 2. Encontrar el punto medio del contenedor
	typename Container::iterator mid = c.begin() + c.size() / 2;

	// Dividir en dos subcontenedores
	Container left(c.begin(), mid);
	Container right(mid, c.end());

	// Ordenar recursivamente
	mergeInsertSort(left);
	mergeInsertSort(right);

	// Combina desde el principio de ambos subcontenedores hasta el final en "C"
	std::merge(left.begin(), left.end(), right.begin(), right.end(), c.begin());

	// Insertion sort para elementos restantes
	insertionSort(c, c.begin(), c.end());
}

template <typename Container>
// Hemos quitado la letra 'c' de la variable 'Container c' para evitar confusiones ya que no es necesario
void PmergeMe::insertionSort(Container&, typename Container::iterator start, typename Container::iterator end)
{
	// Recorrer el contenedor desde el segundo elemento hasta el final
	for (typename Container::iterator i = start; i != end; ++i)
	{
		typename Container::iterator j = i;
		
		// Comparamos "J" con los elementos anteriores en caso encontrar un elemento mayor hacemos un swap
		while (j != start && *(j - 1) > *j)
		{
			std::iter_swap(j - 1, j);
			--j;
		}
	}
}

template <typename Container>
// Hemos quitado la letra 'c' de la variable 'Container c' para evitar confusiones ya que no es necesario
void PmergeMe::merge(Container&, typename Container::iterator start,
					 typename Container::iterator mid, typename Container::iterator end)
{
	// 1. Contenedor temporal para almacenar el resultado fusionado
	Container temp;
	
	// 2. Iteradores para recorrer las dos mitades ordenadas
	typename Container::iterator left = start;   // Inicio de la primera mitad
    typename Container::iterator right = mid;    // Inicio de la segunda mitad

	// 3. Comparamos los elementos de ambas mitades y elegimos el menor en cada iteración hsata que una de las mitades se haya recorrido completamente
	// Ejemplo de fusión (merge) de dos mitades ordenadas:
	// left = [2, 5, 7]
	// right = [1, 3, 8]
	// Resultado tras el merge: [1, 2, 3, 5, 7, 8]
	while (left != mid && right != end)
	{
		if (*left <= *right)
			temp.push_back(*left++);
		else
			temp.push_back(*right++);
	}

	// 4. Copiamos los elementos restantes de la mitad izquierda (si los hay)
	temp.insert(temp.end(), left, mid);
	// 5. Copiamos los elementos restantes de la mitad derecha (si los hay)
	temp.insert(temp.end(), right, end);

	// 6. Copiamos el resultado fusionado de vuelta al contenedor original
	std::copy(temp.begin(), temp.end(), start);
}

// Métodos "utils"
void PmergeMe::printContainer(const std::string &msg, const Vector &vec)
{
	std::cout << msg;
	for (Vector::const_iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";
}

void PmergeMe::printTime(const std::string &container, double time, size_t size)
{
	std::cout << "Time to process a range of " << size
			  << " elements with " << container << ": "
			  << time << " us\n";
}
