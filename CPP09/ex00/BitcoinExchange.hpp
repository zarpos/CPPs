/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 21:58:26 by drubio-m          #+#    #+#             */
/*   Updated: 2025/05/04 21:58:41 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
private:
	std::map<std::string, float> _database;

	// Funciones de validación estáticas
	static std::string trim(const std::string &str);
	static bool isValidDate(const std::string &date);
	static bool isLeapYear(int year);
	static bool isValidValue(const std::string &valueStr, float &value);

public:
	BitcoinExchange(const std::string &databaseFile);
	void processInput(const std::string &inputFile) const;
};

#endif
