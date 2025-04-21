/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:25:38 by drubio-m          #+#    #+#             */
/*   Updated: 2025/04/22 00:19:07 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	// Test 1: Burocrata firma formulario válido
	try
	{
		Bureaucrat b("Alice", 3);
		Form f("Tax Form", 5, 15);
		b.signForm(f); // Alice firma exitosamente
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test 2: Burocrata con grado insuficiente
	try
	{
		Bureaucrat b("Bob", 50);
		Form f("Secret Document", 30, 10);
		b.signForm(f); // Bob no puede firmar
	}
	catch (...)
	{
	}

	// Test 3: Formulario con grado inválido
	try
	{
		Form f("Invalid", 0, 150); // Lanza GradeTooHighException
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}

/*
Bureaucrat
+-------------+           Form
| - _name     |<>--------| - _isSigned
| - _grade    |           | - _gradeToSign
+-------------+           | - _gradeToExecute
| + signForm()|           +----------------+
+-------------+           | + beSigned()   |
                          +----------------+

*/