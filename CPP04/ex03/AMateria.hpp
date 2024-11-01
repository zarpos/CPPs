/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:01:53 by drubio-m          #+#    #+#             */
/*   Updated: 2024/11/01 22:05:18 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria(void);
		virtual ~AMateria(void);
		AMateria &operator=(const AMateria &am);
		AMateria(const AMateria &am);
	
		AMateria(std::string const &type);
		std::string const &getType() const;
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);
};

#endif