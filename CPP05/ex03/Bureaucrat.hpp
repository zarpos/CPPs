/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:35:21 by drubio-m          #+#    #+#             */
/*   Updated: 2025/04/22 00:19:54 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

class AForm; // Declaración adelantada para evitar inclusión circular

class Bureaucrat
{
private:
	const std::string _name; // Nombre constante (no modificable)
	int _grade;				 // Grado actual (1-150)

public:
	// --- Constructores y operadores ---
	Bureaucrat(const std::string &name, int grade); // Constructor principal
	Bureaucrat(const Bureaucrat &other);			// Constructor de copia
	~Bureaucrat();									// Destructor
	Bureaucrat &operator=(const Bureaucrat &other); // Operador de asignación

	// --- Getters (acceso a datos) ---
	const std::string &getName() const; // Devuelve referencia constante al nombre
	int getGrade() const;				// Devuelve el grado actual

	// --- Modificación del grado ---
	void incrementGrade(); // Aumenta el grado (disminuye valor numérico)
	void decrementGrade(); // Disminuye el grado (aumenta valor numérico)

	// --- Interacción con Formularios (Ejercicio 02) ---
	void signForm(AForm &form);				   // Firma un formulario
	void executeForm(const AForm &form) const; // Ejecuta un formulario

	// --- Excepciones personalizadas ---
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw(); // Mensaje de error
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

// Sobrecarga del operador de inserción (NO es miembro de la clase)
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif