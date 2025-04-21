/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:34:18 by drubio-m          #+#    #+#             */
/*   Updated: 2025/04/22 00:19:19 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp" // Este es el nuevo formulario que cambia respecto al anterior ejercicio

// --- Constructores y operadores ---
Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: _name(name), _grade(grade)
{ // Lista de inicialización
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: _name(other._name), _grade(other._grade) {} // Copia manual

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{								 // Evita auto-asignación (buro1 = buro1)
		this->_grade = other._grade; // Solo copia el grado (nombre es const)
	}
	return *this; // Retorna referencia al objeto actual
}

Bureaucrat::~Bureaucrat() {} // Destructor vacío (no hay recursos dinámicos)

// --- Getters ---
const std::string &Bureaucrat::getName() const
{
	return _name; // Devuelve referencia (no copia)
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

// --- Modificación del grado ---
void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--; // Ej: 3 → 2 (mejora de grado)
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++; // Ej: 149 → 150 (empeora grado)
}

// --- Interacción con Formularios (Ejercicio 02) ---
void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this); // Intenta firmar el formulario
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << _name << " couldn't sign " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this); // Delega la ejecución al formulario
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << _name << " failed to execute " << form.getName()
				  << ": " << e.what() << std::endl;
	}
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

// --- Sobrecarga del operador << ---
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os; // Permite encadenamiento: cout << buro1 << buro2
}
