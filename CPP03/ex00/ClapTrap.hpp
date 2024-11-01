/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:29:59 by drubio-m          #+#    #+#             */
/*   Updated: 2024/11/01 09:29:28 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define CYAN    "\033[36m"

class ClapTrap
{
private:
	std::string _name;
	int _health;
	int _energy_points;
	int _attack_dmg;

public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &ct);
	ClapTrap(void);
	~ClapTrap();
	ClapTrap &operator=(const ClapTrap &clap);
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif