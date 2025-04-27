/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 21:47:53 by drubio-m          #+#    #+#             */
/*   Updated: 2025/04/27 21:48:07 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cfloat>
#include <cmath>
#include <iomanip>
#include <iostream>

static void printImpossible()
{
	std::cout << "impossible" << std::endl;
}

static void printNonDisplayable()
{
	std::cout << "Non displayable" << std::endl;
}

static bool isSpecial(const std::string &literal)
{
	return (literal == "nan" || literal == "nanf" || literal == "+inf" ||
			literal == "+inff" || literal == "-inf" || literal == "-inff");
}

static void handleSpecial(const std::string &literal)
{
	std::cout << "char: ";
	printImpossible();
	std::cout << "int: ";
	printImpossible();
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

static bool isCharLiteral(const std::string &literal)
{
	return (literal.length() == 3 && literal.front() == '\'' && literal.back() == '\'');
}

static bool isIntLiteral(const std::string &literal)
{
	size_t i = 0;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	for (; i < literal.length(); i++)
	{
		if (!isdigit(literal[i]))
			return false;
	}
	return literal.length() > 0;
}

static bool isFloatLiteral(const std::string &literal)
{
	if (literal.length() < 2 || literal.back() != 'f')
		return false;
	std::string withoutF = literal.substr(0, literal.length() - 1);
	char *endptr;
	strtof(withoutF.c_str(), &endptr);
	return (*endptr == '\0');
}

static bool isDoubleLiteral(const std::string &literal)
{
	char *endptr;
	strtod(literal.c_str(), &endptr);
	return (*endptr == '\0');
}

void ScalarConverter::convert(const std::string &literal)
{
	if (isSpecial(literal))
	{
		handleSpecial(literal);
		return;
	}

	if (isCharLiteral(literal))
	{
		char c = literal[1];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
		return;
	}

	if (isIntLiteral(literal))
	{
		errno = 0;
		long val = strtol(literal.c_str(), NULL, 10);
		if (errno == ERANGE || val > INT_MAX || val < INT_MIN)
		{
			std::cout << "char: ";
			printImpossible();
			std::cout << "int: ";
			printImpossible();
			std::cout << "float: ";
			printImpossible();
			std::cout << "double: ";
			printImpossible();
			return;
		}
		int i = static_cast<int>(val);
		std::cout << "char: ";
		if (i >= 32 && i <= 126)
			std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
		else
			printNonDisplayable();
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
		return;
	}

	if (isFloatLiteral(literal))
	{
		errno = 0;
		std::string withoutF = literal.substr(0, literal.length() - 1);
		char *endptr;
		float f = strtof(withoutF.c_str(), &endptr);
		if (errno == ERANGE)
		{
			std::cout << "char: ";
			printImpossible();
			std::cout << "int: ";
			printImpossible();
			std::cout << "float: ";
			printImpossible();
			std::cout << "double: ";
			printImpossible();
			return;
		}
		int i = static_cast<int>(f);
		std::cout << "char: ";
		if (f < 0 || f > 127)
			printImpossible();
		else if (i >= 32 && i <= 126)
			std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
		else
			printNonDisplayable();
		std::cout << "int: ";
		if (f < INT_MIN || f > INT_MAX || std::isnan(f))
			printImpossible();
		else
			std::cout << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
		return;
	}

	if (isDoubleLiteral(literal))
	{
		errno = 0;
		char *endptr;
		double d = strtod(literal.c_str(), &endptr);
		if (errno == ERANGE)
		{
			std::cout << "char: ";
			printImpossible();
			std::cout << "int: ";
			printImpossible();
			std::cout << "float: ";
			printImpossible();
			std::cout << "double: ";
			printImpossible();
			return;
		}
		int i = static_cast<int>(d);
		std::cout << "char: ";
		if (d < 0 || d > 127)
			printImpossible();
		else if (i >= 32 && i <= 126)
			std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
		else
			printNonDisplayable();
		std::cout << "int: ";
		if (d < INT_MIN || d > INT_MAX || std::isnan(d))
			printImpossible();
		else
			std::cout << i << std::endl;
		std::cout << "float: ";
		if (d < -FLT_MAX || d > FLT_MAX || std::isnan(d))
			printImpossible();
		else
			std::cout << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
		return;
	}

	// Si no es ninguno de los tipos válidos
	std::cout << "char: ";
	printImpossible();
	std::cout << "int: ";
	printImpossible();
	std::cout << "float: ";
	printImpossible();
	std::cout << "double: ";
	printImpossible();
}
