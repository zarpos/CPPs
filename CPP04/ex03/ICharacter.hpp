/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:24:26 by drubio-m          #+#    #+#             */
/*   Updated: 2024/11/01 22:26:11 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
class AMateria;

class ICharacter
{
protected:
	std::string _name;
	AMateria *_materias[4];

public:	
	virtual ~ICharacter() {}
	virtual std::string const& getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use (int idx, ICharacter& target) = 0;	
};

#endif
