/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 22:00:39 by drubio-m          #+#    #+#             */
/*   Updated: 2025/05/04 22:27:55 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>


// Sintaxis para ejecutar el programa: ./btc data.csv
int main(int argc, char **argv)
{
	// Comprobamos que el usuario ha pasado exactamente un argumento (el archivo de entrada)
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	try
	{
		// Instanciamos el objeto BitcoinExchange, que carga la base de datos de precios.
		// El nombre del archivo de la base de datos es constante "data.csv"
		BitcoinExchange exchange("data.csv");

		// Procesamos el archivo de entrada pasado como argumento.
		exchange.processInput(argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
