/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:20:24 by drubio-m          #+#    #+#             */
/*   Updated: 2024/10/31 18:22:07 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    // Constructor por defecto
    FragTrap();
    // Constructor con nombre
    FragTrap(std::string name);
    // Constructor de copia
    FragTrap(const FragTrap &ft);
    // Destructor
    ~FragTrap();

    // Operador de asignación
    FragTrap &operator=(const FragTrap &ft);

    // Método específico de FragTrap
    void highFivesGuys();
};

#endif