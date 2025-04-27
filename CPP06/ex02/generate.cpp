/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 22:30:19 by drubio-m          #+#    #+#             */
/*   Updated: 2025/04/27 22:30:34 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

// Genera instancias aleatorias de A, B o C
Base *generate(void)
{
	// Inicializa la seed aleatoria usando el tiempo actual
	srand(time(NULL));
	// Genera número entre 0-2
	int r = rand() % 3;

	switch (r)
	{
	case 0:
		return new A(); // 33% de probabilidad
	case 1:
		return new B(); // 33% de probabilidad
	default:
		return new C(); // 34% de probabilidad
	}
}
