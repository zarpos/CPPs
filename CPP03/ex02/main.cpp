/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:13:17 by drubio-m          #+#    #+#             */
/*   Updated: 2024/10/31 18:24:22 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
int main()
{
    // Creación de un objeto FragTrap
    std::cout << "=== FragTrap Creation ===" << std::endl;
    FragTrap frag("Fraggy");

    // Uso de los métodos de ClapTrap
    frag.attack("target1");
    frag.takeDamage(25);
    frag.beRepaired(15);

    // Uso del método exclusivo de FragTrap
    std::cout << "\n=== Testing highFivesGuys ===" << std::endl;
    frag.highFivesGuys();

    // Prueba de constructor de copia y operador de asignación
    std::cout << "\n=== Testing Copy and Assignment ===" << std::endl;
    FragTrap frag2 = frag;  // Constructor de copia
    FragTrap frag3("Another Fraggy");
    frag3 = frag;            // Operador de asignación

    std::cout << "\n=== End of main, Destructors Called ===" << std::endl;
    return 0;
}

