/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:55:56 by drubio-m          #+#    #+#             */
/*   Updated: 2024/10/27 10:22:28 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>
# include <iostream>

// Colors
const std::string RESET = "\033[0m";
const std::string GREEN = "\033[32m";
const std::string RED = "\033[31m";

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie(std::string name);				//Constructor
		~Zombie(); 								//Destructor
		void announce(void);
};

// External Functions
Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif