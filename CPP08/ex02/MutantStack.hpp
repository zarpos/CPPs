/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 12:23:32 by drubio-m          #+#    #+#             */
/*   Updated: 2025/05/04 12:30:29 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

//MutantStack hereda de std::stack
// Template indica que mutantstack es una clase plantilla
template <typename T>
class MutantStack : public std::stack<T>
{
public:
	// Definimos los tipos de iteradores usando el contenedor subyacente (por defecto std::deque)
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	// begin(): Devuelve un iterador al primer elemento del stack
	iterator begin()
	{
		return this->c.begin(); // "c" es el contenedor protegido de std::stack
	}

	// begin() const: Versión constante para stacks constantes
	const_iterator begin() const
	{
		return this->c.begin();
	}

	// end(): Devuelve un iterador al elemento después del último
	iterator end()
	{
		return this->c.end();
	}

	// end() const: Versión constante para stacks constantes
	const_iterator end() const
	{
		return this->c.end();
	}
};

#endif