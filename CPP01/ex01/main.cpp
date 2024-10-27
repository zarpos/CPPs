/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:55:34 by drubio-m          #+#    #+#             */
/*   Updated: 2024/10/27 10:28:29 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

#define N 5

int main()
{
    Zombie *zombies = zombieHorde(N, "hola");
    for (int i = 0; i < N; i++)
    {
        zombies[i].announce();
    }
    delete [] zombies;
    return (0);
}
