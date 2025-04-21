/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:59:19 by drubio-m          #+#    #+#             */
/*   Updated: 2025/04/22 00:19:57 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Estructura que asocia un nombre de formulario con una función creadora.
// Así, el Intern puede buscar el nombre y llamar a la función correspondiente
struct FormCreator
{
	// El nombre textual del formulario que el Intern puede crear
	std::string name;

	// Puntero a función que toma el 'target' como parámetro
	// y devuelve un puntero a un nuevo objeto AForm (o derivado)
	// Ejemplo: AForm *createShrubbery(const std::string &target);
	// El & del final no es una dirección de memoria, es una referencia a un string
	AForm *(*create)(const std::string &);
};

// Funciones estáticas (no visibles fuera de este archivo) para crear cada tipo de formulario
namespace
{
	// Crea un ShrubberyCreationForm con el target dado
	AForm *createShrubbery(const std::string &target)
	{
		return new ShrubberyCreationForm(target);
	}

	// Crea un RobotomyRequestForm con el target dado
	AForm *createRobotomy(const std::string &target)
	{
		return new RobotomyRequestForm(target);
	}

	// Crea un PresidentialPardonForm con el target dado
	AForm *createPardon(const std::string &target)
	{
		return new PresidentialPardonForm(target);
	}
}

// Tabla de búsqueda: nombre del formulario -> función creadora
const FormCreator creators[] = {
	{"shrubbery creation", &createShrubbery},
	{"robotomy request", &createRobotomy},
	{"presidential pardon", &createPardon}};

Intern::Intern() {}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	for (size_t i = 0; i < sizeof(creators) / sizeof(creators[0]); ++i)
	{
		if (creators[i].name == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return creators[i].create(target);
		}
	}
	std::cerr << "Error: Unknown form '" << formName << "'" << std::endl;
	return NULL;
}
