/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:35:21 by drubio-m          #+#    #+#             */
/*   Updated: 2025/04/22 00:18:57 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

// Declaramos de forma anticipada para evitar una dependencia circular
class Form; // Declaración anticipada de la clase Form

class Bureaucrat
{
private:
	const std::string _name;
	int _grade; // Grado (1-150)

public:
	// --- Constructores y operadores ---
	Bureaucrat(const std::string &name, int grade); // Constructor principal
	Bureaucrat(const Bureaucrat &other);			// Constructor de copia
	Bureaucrat &operator=(const Bureaucrat &other); // Operador de asignación
	~Bureaucrat();									// Destructor

	// --- Getters (métodos de acceso) ---
	const std::string &getName() const; // Devuelve referencia constante al nombre
	int getGrade() const;				// Devuelve el grado actual

	// --- Métodos para modificar el grado ---
	void incrementGrade(); // Aumenta el grado (disminuye el valor numérico)
	void decrementGrade(); // Disminuye el grado (aumenta el valor numérico)

	// --- Excepciones personalizadas ---
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw(); // Sobrescribe what()
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	// --- Método para firmar un formulario ---
	void signForm(Form &form); // Permite al burocrata firmar un formulario
};

// Sobrecarga del operador de inserción (NO es miembro de la clase)
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif