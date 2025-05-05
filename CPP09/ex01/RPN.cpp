/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 23:25:07 by drubio-m          #+#    #+#             */
/*   Updated: 2025/05/04 23:49:20 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <stack>
#include <stdexcept>

double RPN::evaluate(const std::string &expression)
{
	std::stack<double> pila; // Usamos stack como contenedor principal

	std::stringstream ss(expression);
	std::string token;

	// Separamos la expresión en tokens y vamos uno a uno
	while (ss >> token)
	{ 
		// Separamos tokens por espacios
		// Validación de token
		if (token.length() != 1)
			throw std::runtime_error("Error");
		char c = token[0];

		// Si es un número, lo convierte a double y lo mete al final de la pila
		if (isdigit(c))
		{						
			pila.push(c - '0'); 
		}
		// Si es un operador, extrae los dos últimos números de la pila y realiza la operación
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{ // Operadores válidos
			if (pila.size() < 2)
				throw std::runtime_error("Error"); // Verificar operandos

			// Extraer operandos
			// Extrae el último número de la pila
			double derecha = pila.top();
			pila.pop();
			// Extrae el penúltimo número de la pila
			double izquierda = pila.top();
			pila.pop();

			// Realizar operación
			switch (c)
			{
			case '+':
				pila.push(izquierda + derecha);
				break;
			case '-':
				pila.push(izquierda - derecha);
				break;
			case '*':
				pila.push(izquierda * derecha);
				break;
			case '/':
				if (derecha == 0)
					throw std::runtime_error("Error"); // División por cero
				pila.push(izquierda / derecha);
				break;
			}
		}
		else
		{ // Token inválido
			throw std::runtime_error("Error");
		}
	}

	// Verificar resultado final
	if (pila.size() != 1)
		throw std::runtime_error("Error");
	return pila.top();
}
