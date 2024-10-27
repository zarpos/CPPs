/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:23:14 by drubio-m          #+#    #+#             */
/*   Updated: 2024/10/27 11:36:03 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <string>

class Weapon 
{
	private:
		std::string	_type;
		
	public:
		Weapon(std::string type);
		//Getters
		const std::string &getType(void);
		//Setters
		void setType(std::string type);
};

#endif