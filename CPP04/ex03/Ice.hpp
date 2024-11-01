/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:06:16 by drubio-m          #+#    #+#             */
/*   Updated: 2024/11/01 22:20:35 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	~Ice();
	Ice(const Ice &other);
	Ice &operator=(const Ice &other);

	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif