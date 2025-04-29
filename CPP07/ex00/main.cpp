/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:21:28 by drubio-m          #+#    #+#             */
/*   Updated: 2025/04/29 23:21:37 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "functions.hpp"

int main()
{
	int a = 2, b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << "\n"
			  << "min: " << ::min(a, b) << "\n"
			  << "max: " << ::max(a, b) << std::endl;

	std::string c = "chaine1", d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << "\n"
			  << "min: " << ::min(c, d) << "\n"
			  << "max: " << ::max(c, d) << std::endl;
}
