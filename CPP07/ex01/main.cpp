/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:38:27 by drubio-m          #+#    #+#             */
/*   Updated: 2025/04/29 23:38:40 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

// Función para incrementar números
void increment(int &x)
{
	x += 10;
}

// Función template para imprimir cualquier tipo
template <typename T>
void print(const T &x)
{
	std::cout << x << " ";
}

// Función específica para strings
void capitalize(std::string &s)
{
	for (size_t i = 0; i < s.size(); ++i)
	{
		s[i] = toupper(s[i]);
	}
}

int main()
{
	// Test 1: Array de ints
	int numbers[] = {1, 2, 3, 4, 5};
	const int numbers_length = 5;

	std::cout << "Original: ";
	iter(numbers, numbers_length, print<int>);
	std::cout << "\n";

	iter(numbers, numbers_length, increment);

	std::cout << "Modificado: ";
	iter(numbers, numbers_length, print<int>);
	std::cout << "\n\n";

	// Test 2: Array de strings
	std::string words[] = {"hello", "world", "from", "iter"};
	const int words_length = 4;

	std::cout << "Original: ";
	iter(words, words_length, print<std::string>);
	std::cout << "\n";

	iter(words, words_length, capitalize);

	std::cout << "Modificado: ";
	iter(words, words_length, print<std::string>);
	std::cout << "\n";

	return 0;
}
