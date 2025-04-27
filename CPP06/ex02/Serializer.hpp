/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 22:03:13 by drubio-m          #+#    #+#             */
/*   Updated: 2025/04/27 22:41:24 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Serializer.hpp
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Base.hpp" // ¡Incluir la definición de Base!

// Declaraciones de funciones
Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif
