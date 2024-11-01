/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:12:13 by drubio-m          #+#    #+#             */
/*   Updated: 2024/11/01 10:31:01 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# define RESET   "\033[0m"
# define BLACK   "\033[30m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(const Animal &copy);
		Animal &operator=(const Animal &copy);
		// Al ser virtual asegura que se destruya tanto la clase base como la derivada
		virtual ~Animal();
		// Methods
		// Al ser virtual te aseguras de que cada animal incluya su propia versión de la función
		virtual void makeSound() const;
		// Getter
		std::string getType() const;
		// Setter
		void setType(std::string type);
};

#endif