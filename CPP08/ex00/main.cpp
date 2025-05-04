/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:02:09 by drubio-m          #+#    #+#             */
/*   Updated: 2025/05/04 02:33:24 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include "easyfind.hpp"
#include <iostream>

// Función template para imprimir cualquier contenedor
template <typename T>
void printContainer(const T &container, const std::string &name)
{
	std::cout << name << " contiene: ";
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main()
{
	// Prueba con vector
	std::vector<int> v;
	v.push_back(1);
	v.push_back(42);

	printContainer(v, "Vector");

	try
	{
		std::vector<int>::iterator it = easyfind(v, 42);
		std::cout << "Encontrado en vector: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error en vector: " << e.what() << std::endl;
	}

	// Prueba con lista
	std::list<int> l;
	l.push_back(10);

	printContainer(l, "Lista");

	try
	{
		std::list<int>::iterator it = easyfind(l, 5);
		std::cout << "Encontrado en lista: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error en lista: " << e.what() << std::endl;
	}

	return 0;
}
