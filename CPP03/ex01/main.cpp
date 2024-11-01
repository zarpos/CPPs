/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:13:17 by drubio-m          #+#    #+#             */
/*   Updated: 2024/11/01 09:41:37 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"



int main()
{
    // Prueba de creación de ClapTrap
    std::cout << CYAN << "=== ClapTrap Creation ===" << RESET << std::endl;
    ClapTrap clap("Clappy");
    clap.attack("target1");
    clap.takeDamage(3);
    clap.beRepaired(2);

    std::cout << CYAN << "\n=== ScavTrap Creation ===" << RESET << std::endl;
    // Prueba de creación de ScavTrap usando el constructor con nombre
    ScavTrap scav("Scavvy");

    // Prueba del método attack() y de los atributos específicos de ScavTrap
    scav.attack("target2");  // Ataque específico de ScavTrap
    scav.takeDamage(20);     // Prueba de recibir daño
    scav.beRepaired(15);     // Prueba de reparación

    // Prueba del método guardGate() exclusivo de ScavTrap
    std::cout << CYAN << "\n=== Testing guardGate ===" << RESET << std::endl;
    scav.guardGate();

    // Prueba del operador de asignación
    std::cout << CYAN << "\n=== Testing Copy and Assignment ===" << RESET << std::endl;
    ScavTrap scav2 = scav;   // Llama al constructor de copia
    scav2.attack("another target");  // Debería atacar sin problemas

    std::cout << CYAN << "\n=== End of main, Destructors Called ===" << RESET << std::endl;
    return 0;
}
