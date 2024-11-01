/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:15:36 by drubio-m          #+#    #+#             */
/*   Updated: 2024/11/01 21:56:55 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Dog.hpp"
#include "./Cat.hpp"
#include "./Brain.hpp"
#include "./Animal.hpp"

int main()
{
	//Animal animalito; Esto da error ya que la clase es abstracta
	Animal *animals[50];
	Animal *a = new Dog();

	a->makeSound();
	for (size_t i = 0; i < 25; i++)
	{
		animals[i] = new Cat();
		std::cout << "------------------------" << std::endl;
	}

	for (size_t i = 25; i < 50; i++)
	{
		animals[i] = new Dog();
		std::cout << "------------------------" << std::endl;
	}

	for (size_t i = 0; i < 50; i++)
	{
		delete animals[i];
		std::cout << "------------------------" << std::endl;
	}
	delete a;
	return 0;
}
