/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 22:00:35 by drubio-m          #+#    #+#             */
/*   Updated: 2025/05/04 22:25:25 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <limits>



// El archivo debe tener el formato: "date,exchange_rate" en cada línea.
 
BitcoinExchange::BitcoinExchange(const std::string &databaseFile)
{
	// c_str convierte string a const char*
	std::ifstream file(databaseFile.c_str());
	if (!file)
	{
		throw std::runtime_error("Error: could not open database file.");
	}

	std::string line;
	// Leemos la primera línea (cabecera) y la descartamos.
	std::getline(file, line);

	// Procesamos cada línea del archivo CSV.
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		size_t comma = line.find(',');
		if (comma == std::string::npos)
			continue; // Línea malformada, la ignoramos.

		std::string date = line.substr(0, comma);
		std::string rateStr = line.substr(comma + 1);

		// Convertimos el string del rate a float.
		float rate = std::atof(rateStr.c_str());

		// Guardamos en el map: clave = fecha, valor = rate.
		_database[date] = rate;
	}
}

/*
 * Por cada línea válida, calcula el valor en dólares de la cantidad de bitcoins
 * usando la tasa más cercana anterior o igual a la fecha indicada.
 */
void BitcoinExchange::processInput(const std::string &inputFile) const
{
	std::ifstream file(inputFile.c_str());
	if (!file)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	bool isHeader = true;

	// Procesamos el archivo línea a línea.
	while (std::getline(file, line))
	{
		// Saltamos la cabecera "date | value"
		if (isHeader)
		{
			isHeader = false;
			continue;
		}

		// Buscamos el separador '|'
		size_t pipe = line.find('|');
		// npos indica que no se encontró el carácter. el valor de retorno es el máximo posible de size_t.
		if (pipe == std::string::npos)
		{
			// Si no hay '|', la línea está mal formada.
			if (!trim(line).empty())
				std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		// Extraemos la fecha y el valor, eliminando espacios en blanco.
		// Desde el principio hasta el pipe
		std::string date = trim(line.substr(0, pipe));
		// Del pipe hasta el final
		std::string valueStr = trim(line.substr(pipe + 1));

		// Validamos la fecha.
		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		// Validamos el valor y lo convertimos a float.
		float value;
		if (!isValidValue(valueStr, value))
		{
			// El método ya imprime el error correspondiente.
			continue;
		}

		// Comprobamos el rango permitido [0, 1000].
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		// Buscamos la tasa de cambio más cercana anterior o igual a la fecha dada.
		// Upper_bound devuelve el primer elemento que es mayor que date.
		std::map<std::string, float>::const_iterator it = _database.upper_bound(date);
		if (it == _database.begin())
		{
			// No hay ninguna fecha anterior en la DB.
			std::cerr << "Error: no exchange rate available for date => " << date << std::endl;
			continue;
		}
		--it; // Retrocedemos al valor válido más cercano.

		// Calculamos el resultado.
		float result = value * it->second;

		// Mostramos el resultado en el formato requerido.
		std::cout << date << " => " << valueStr << " = " << result << std::endl;
	}
}

/*
 * Elimina espacios en blanco al principio y final de un string.
 */
std::string BitcoinExchange::trim(const std::string &str)
{
	size_t start = 0;
	while (start < str.size() && std::isspace(str[start]))
		++start;
	size_t end = str.size();
	while (end > start && std::isspace(str[end - 1]))
		--end;
	return str.substr(start, end - start);
}

/*
 * Comprueba si una fecha tiene formato y valores válidos: YYYY-MM-DD.
 * También valida los días según el mes y el año bisiesto.
 */
bool BitcoinExchange::isValidDate(const std::string &date)
{
	// Comprobamos el formato: YYYY-MM-DD con guiones en la posición 4 y 7.
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int year, month, day;
	// Extraemos los valores de año, mes y día.
	std::istringstream iss(date);
	char dash1, dash2;
	// El operador >> convierte el string a int y comprueba que sea válido.
	if (!(iss >> year >> dash1 >> month >> dash2 >> day))
		return false;
	/* Ejemplo:
		"2023-05-04" se convierte a year = 2023, month = 5, day = 4.
		dash1 y dash2 deben ser '-'.
	*/
	if (dash1 != '-' || dash2 != '-')
		return false;

	// Validación básica de rangos.
	if (year < 2009 || month < 1 || month > 12 || day < 1)
		return false;

	// Días máximos por mes.
	static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int maxDay = daysInMonth[month - 1];
	// Febrero y año bisiesto.
	if (month == 2 && isLeapYear(year))
		maxDay = 29;
	if (day > maxDay)
		return false;

	return true;
}

/*
 * Comprueba si un año es bisiesto.
 */
bool BitcoinExchange::isLeapYear(int year)
{
	// Regla: un año es bisiesto si es divisible por 4, pero no por 100, a menos que también sea divisible por 400.
	/*
	2012 es bisiesto (2012 % 4 = 0, 2012 % 100 ≠ 0).
	1900 no es bisiesto (1900 % 100 = 0 pero 1900 % 400 ≠ 0)
	*/
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

/*
 * Valida si el string es un número válido (entero o float positivo) y lo almacena en value.
 */
bool BitcoinExchange::isValidValue(const std::string &valueStr, float &value)
{
	// Comprobamos si el string está vacío.
	if (valueStr.empty())
		return false;

	char *endptr = NULL;
	value = std::strtof(valueStr.c_str(), &endptr);

	// Comprobamos que todo el string fue convertido y que es un número.
	if (*endptr != '\0')
	{
		std::cerr << "Error: bad input => " << valueStr << std::endl;
		return false;
	}
	// Comprobamos que no sea infinito o NaN.
	if (value != value || value == std::numeric_limits<float>::infinity())
		return false;
	return true;
}
