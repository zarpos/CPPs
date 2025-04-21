/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:34:06 by drubio-m          #+#    #+#             */
/*   Updated: 2024/11/02 13:53:24 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main(void)
{
	// Crear una fuente de materias
	IMateriaSource *src = new MateriaSource();

	// Aprender nuevas materias
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// Crear un personaje
	ICharacter *me = new Character("me");

	// Crear y equipar materias
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	// Crear otro personaje
	ICharacter *bob = new Character("bob");

	// Usar materias en el personaje "bob"
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob); // Esta línea no hará nada útil ya que no hay mmakateria en el índice 2

	// Desequipar materias
	me->unequip(0);
	me->unequip(0); // Esta línea no hará nada útil ya que el índice 0 ya está vacío
	me->unequip(1);
	me->unequip(1); // Esta línea no hará nada útil ya que el índice 1 ya está vacío
	me->unequip(2); // Esta línea no hará nada útil ya que no hay materia en el índice 2

	// Liberar memoria
	delete bob;
	delete me;
	delete src;

	return 0;
}

