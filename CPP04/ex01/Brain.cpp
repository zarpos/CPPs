/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:51:30 by drubio-m          #+#    #+#             */
/*   Updated: 2024/11/01 19:00:28 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "idea ";
	std::cout << GREEN << "Brain default constructor called" << RESET << std::endl;
}

Brain::~Brain()
{
	std::cout << RED << "Brain destructor called" << RESET << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << GREEN << "Brain copy constructor called" << RESET << std::endl;
	*this = copy;
}

Brain &Brain::operator=(const Brain &copy)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = copy.ideas[i];
	}
	return (*this);
}

std::string Brain::getIdea(int i) const
{
	return (this->ideas[i]);
}

void Brain::setIdea(int i, std::string idea)
{
	ideas[i] = idea;
}
