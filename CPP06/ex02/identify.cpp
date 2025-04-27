/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 22:31:05 by drubio-m          #+#    #+#             */
/*   Updated: 2025/04/27 22:31:13 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

// Identifica el tipo usando puntero (dynamic_cast devuelve nullptr si falla)
void identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C" << std::endl;
}

// Identifica el tipo usando referencia (dynamic_cast lanza excepción si falla)
void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p); // Intenta convertir a A
		std::cout << "A" << std::endl;
		return;
	}
	catch (...)
	{
	} // Captura cualquier excepción

	try
	{
		(void)dynamic_cast<B &>(p); // Intenta convertir a B
		std::cout << "B" << std::endl;
		return;
	}
	catch (...)
	{
	}

	// Si no es A ni B, asume que es C
	std::cout << "C" << std::endl;
}
