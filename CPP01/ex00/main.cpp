/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:55:34 by drubio-m          #+#    #+#             */
/*   Updated: 2024/10/27 10:37:15 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

int main()
{
	Zombie *zombie = newZombie("Zombie1");
	zombie->announce();
	delete zombie;
	randomChump("Zombie2");
	return 0;
}

/* int main()
{
    // Array de nombres para los zombies
    std::string names[] = {"Zombie1", "Zombie2", "Zombie3", "Zombie4", "Zombie5"};
    int numZombies = sizeof(names) / sizeof(names[0]);

    // Crear y anunciar zombies usando newZombie
    for (int i = 0; i < numZombies; ++i) {
        Zombie *zombie = newZombie(names[i]);
        zombie->announce();
        delete zombie; // Liberar memoria
    }

    // Crear y anunciar zombies usando randomChump
    for (int i = 0; i < numZombies; ++i) {
        randomChump(names[i]);
    }

    return 0;
} */
