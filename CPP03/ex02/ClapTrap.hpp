/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:29:59 by drubio-m          #+#    #+#             */
/*   Updated: 2024/10/31 18:16:50 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
// Private are accessible only from the class and protected also from herency
protected:
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