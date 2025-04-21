/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:03:37 by drubio-m          #+#    #+#             */
/*   Updated: 2025/04/22 00:19:25 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	// 1. Creamos un burócrata de máximo nivel (grado 1)
	Bureaucrat ceo("CEO", 1); // Puede firmar y ejecutar cualquier formulario

	// ==============================================
	// 2. Prueba con ShrubberyCreationForm (Árboles)
	// ==============================================
	ShrubberyCreationForm shrub("home"); // Requiere grado 145 para firmar, 137 para ejecutar

	// 2a. El CEO firma el formulario (siempre tendrá éxito por su alto grado)
	ceo.signForm(shrub); // Output esperado: "CEO signed Shrubbery Creation"

	// 2b. El CEO ejecuta el formulario (creará el archivo home_shrubbery)
	ceo.executeForm(shrub); // Output esperado: "CEO executed Shrubbery Creation"

	// ==============================================
	// 3. Prueba con RobotomyRequestForm (Robotización)
	// ==============================================
	RobotomyRequestForm robot("Bender"); // Requiere grado 72 para firmar, 45 para ejecutar

	// 3a. Firma (éxito asegurado)
	ceo.signForm(robot); // Output: "CEO signed Robotomy Request"

	// 3b. Ejecución (50% de éxito aleatorio)
	ceo.executeForm(robot); // Output alternará entre éxito y fallo

	// ==============================================
	// 4. Prueba con PresidentialPardonForm (Perdón)
	// ==============================================
	PresidentialPardonForm pardon("Zoidberg"); // Requiere grado 25 para firmar, 5 para ejecutar

	// 4a. Firma (éxito asegurado)
	ceo.signForm(pardon); // Output: "CEO signed Presidential Pardon"

	// 4b. Ejecución (siempre muestra el mensaje de perdón)
	ceo.executeForm(pardon); // Output: "Zoidberg has been pardoned by Zaphod Beeblebrox."

	return 0;
}
