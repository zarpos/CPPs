/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:42:02 by drubio-m          #+#    #+#             */
/*   Updated: 2024/11/01 18:56:34 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
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

class Brain
{
	protected:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &copy);
		virtual ~Brain();
		Brain &operator=(const Brain &copy);
		std::string getIdea(int i) const;
		void setIdea(int i, std::string idea);
};

#endif