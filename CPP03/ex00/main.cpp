/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:40:32 by drubio-m          #+#    #+#             */
/*   Updated: 2024/10/31 12:42:06 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	// Test default constructor
	ClapTrap ct1;
	std::cout << "Created ClapTrap ct1 with default constructor" << std::endl;

	// Test parameterized constructor
	ClapTrap ct2("Clappy");
	std::cout << "Created ClapTrap ct2 with name 'Clappy'" << std::endl;

	// Test copy constructor
	ClapTrap ct3(ct2);
	std::cout << "Created ClapTrap ct3 as a copy of ct2" << std::endl;

	// Test assignment operator
	ClapTrap ct4;
	ct4 = ct2;
	std::cout << "Assigned ct2 to ct4 using assignment operator" << std::endl;

	// Test attack method
	ct2.attack("target1");
	ct2.attack("target2");

	// Test takeDamage method
	ct2.takeDamage(5);
	ct2.takeDamage(10);

	// Test beRepaired method
	ct2.beRepaired(3);
	ct2.beRepaired(5);

	// Test exhaustion and death conditions
	ct2.attack("target3");
	ct2.takeDamage(10);
	ct2.attack("target4");
	ct2.beRepaired(2);

	return 0;
}
