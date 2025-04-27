/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 22:31:48 by drubio-m          #+#    #+#             */
/*   Updated: 2025/04/27 22:39:31 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Serializer.hpp"
#include <iostream>

int main()
{
	// Genera objeto aleatorio (A, B o C)
	Base *obj = generate();

	// Identifica mediante puntero
	std::cout << "Identificación por puntero: ";
	identify(obj);

	// Identifica mediante referencia
	std::cout << "Identificación por referencia: ";
	identify(*obj);

	// Libera memoria
	delete obj;

	return 0;
}
