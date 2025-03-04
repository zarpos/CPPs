/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:26:53 by drubio-m          #+#    #+#             */
/*   Updated: 2024/11/01 22:27:52 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character: public ICharacter
{

private:
	AMateria	*_addresses[100];
	void	saveAdress(AMateria *adress);
public:	
	Character(void);
	Character(std::string name);
	Character(const Character& c);
	
	Character &operator=(const Character& c);
	~Character(void);
	std::string const& getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use (int idx, ICharacter& target);
};
#endif