/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 02:40:33 by drubio-m          #+#    #+#             */
/*   Updated: 2025/05/04 02:40:41 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "Span.hpp"

int main()
{
	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // 2
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;	  // 14

	// Prueba con 10,000 números
	try
	{
		Span bigSpan(10000);
		std::vector<int> bigVec;
		for (int i = 0; i < 10000; ++i)
		{
			bigVec.push_back(i);
		}
		bigSpan.addNumbers(bigVec.begin(), bigVec.end());
		std::cout << "Big shortest: " << bigSpan.shortestSpan() << std::endl; // 1
		std::cout << "Big longest: " << bigSpan.longestSpan() << std::endl;	  // 9999
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
