/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:34:18 by drubio-m          #+#    #+#             */
/*   Updated: 2025/04/22 00:18:50 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// Constructor principal
Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

// Constructor de copia (copia todos los miembros)
Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: _name(other._name), _grade(other._grade) {}

// Operador de asignación (solo copia el grado, el nombre es constante)
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{								 // Evita auto-asignación (ej: buro1 = buro1)
		this->_grade = other._grade; // Solo se copia el grado
	}
	return *this; // Retorna referencia al objeto actual
}

// Destructor (no hace nada porque no hay memoria dinámica)
Bureaucrat::~Bureaucrat() {}

// --- Getters ---
const std::string &Bureaucrat::getName() const
{
	return _name; // Devuelve referencia constante (evita copia)
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

// --- Métodos de modificación ---
void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--; // Subir grado = disminuir el número (ej: 3 → 2)
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++; // Bajar grado = aumentar el número (ej: 149 → 150)
}

// --- Implementación de excepciones ---
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high (max 1)";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low (min 150)";
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this); // Paso 1: Intenta firmar el formulario
		// Si no lanza excepción, se firmó correctamente
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		// Si hay excepción, muestra el error
		std::cout << _name << " couldn't sign " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

// Sobrecarga del operador << (función global)
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os; // Permite encadenamiento: cout << buro1 << buro2
}
