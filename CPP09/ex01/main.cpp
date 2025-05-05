/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 23:34:00 by drubio-m          #+#    #+#             */
/*   Updated: 2025/05/04 23:37:21 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

// Un inverted Polish notation (RPN) es una forma de escribir expresiones matemáticas sin paréntesis ni jerarquía de operaciones. 
//En RPN, los operadores siguen a sus operandos. 
//Por ejemplo, la expresión "3 + 4" se escribiría como "3 4 +". Esto permite evaluar la expresión de izquierda a derecha sin necesidad de paréntesis.
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: uso incorrecto\nEjemplo: ./RPN \"3 4 + 2 *\"" << std::endl;
		return 1;
	}

	try
	{
		double resultado = RPN::evaluate(argv[1]);
		std::cout << resultado << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	return 0;
}

/*
Ejemplo de uso:
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
./RPN "7 7 * 7 -"
42
./RPN "1 2 * 2 / 2 * 2 4 - +"
0
./RPN "(1 + 1)"
Error
*/