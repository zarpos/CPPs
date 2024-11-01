/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:29:56 by drubio-m          #+#    #+#             */
/*   Updated: 2024/11/01 22:33:09 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *_learnedMaterias[4];
	public:
		MateriaSource();
		virtual ~MateriaSource();
		MateriaSource& operator=(const MateriaSource& ms);
		MateriaSource(const MateriaSource& ms);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const& type);
};

#endif
