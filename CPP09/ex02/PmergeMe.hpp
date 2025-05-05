/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 00:07:43 by drubio-m          #+#    #+#             */
/*   Updated: 2025/05/05 01:21:02 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe
{
public:
	// Alias para los contenedores
	typedef std::vector<unsigned int> Vector;
	typedef std::deque<unsigned int> Deque;

	// Métodos de validación
	static bool validateInput(int argc, char **argv);

	// Métodos de ordenación para vector
	static void sortVector(Vector &vec);

	// Métodos de ordenación para deque
	static void sortDeque(Deque &deq);

	// Métodos de utilidad
	static void printContainer(const std::string &msg, const Vector &vec);
	static void printTime(const std::string &container, double time, size_t size);

private:
	// Implementación del algoritmo Ford-Johnson
	template <typename Container>
	static void mergeInsertSort(Container &c);

	template <typename Container>
	static void insertionSort(Container &c, typename Container::iterator start, typename Container::iterator end);

	template <typename Container>
	static void merge(Container &c, typename Container::iterator start,
					  typename Container::iterator mid, typename Container::iterator end);
};

#endif
