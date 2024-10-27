/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:29:23 by drubio-m          #+#    #+#             */
/*   Updated: 2024/10/27 11:38:40 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {}

//Getter
const std::string &Weapon::getType(void)
{
	return _type;
}

//Setter
void Weapon::setType(std::string type)
{
	_type = type;
}
