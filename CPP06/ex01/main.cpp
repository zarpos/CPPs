/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 22:04:30 by drubio-m          #+#    #+#             */
/*   Updated: 2025/04/27 22:12:13 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data data;
	data.value = 42;

	// Serializar
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serializado: 0x" << std::hex << raw << std::endl;

	// Deserializar
	Data *ptr = Serializer::deserialize(raw);
	std::cout << "Deserializado: " << std::dec << ptr->value << std::endl;

	// Verificar igualdad de direcciones
	if (ptr == &data)
		std::cout << "✅ Direcciones coinciden" << std::endl;
	else
		std::cout << "❌ Direcciones no coinciden" << std::endl;

	return 0;
}
