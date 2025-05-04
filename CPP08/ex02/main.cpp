/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 12:23:07 by drubio-m          #+#    #+#             */
/*   Updated: 2025/05/04 12:26:23 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
	// Creamos un MutantStack de enteros
	MutantStack<int> mstack;

	// Probamos operaciones básicas de stack
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl; // Debería imprimir 17

	mstack.pop();										 // Quitamos el 17
	std::cout << "Size: " << mstack.size() << std::endl; // Debería imprimir 1

	// Añadimos más elementos
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	// Añadimos un 0 al final
	mstack.push(0);

	// Probamos los iteradores personalizados
	std::cout << "Iterando MutantStack:" << std::endl;
	MutantStack<int>::iterator it = mstack.begin(); // Apunta al primer elemento
	MutantStack<int>::iterator ite = mstack.end();	// Apunta al final (después del último)

	++it; // Avanzamos el iterador una posición
	--it; // Volvemos atrás (ahora apunta de nuevo al primero)

	// Recorremos e imprimimos todos los elementos
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	// Demostramos que MutantStack se puede copiar a un std::stack
	std::stack<int> s(mstack);

	// --- Comparativa con std::list ---
	std::cout << "\nComparativa con std::list:" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << "Back: " << lst.back() << std::endl;
	lst.pop_back();
	std::cout << "Size: " << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::cout << "Iterando lista:" << std::endl;
	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();
	++lit;
	--lit;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}

	return 0;
}
