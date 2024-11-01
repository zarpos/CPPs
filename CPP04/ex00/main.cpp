/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:15:36 by drubio-m          #+#    #+#             */
/*   Updated: 2024/11/01 18:38:18 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *doggy = new Dog();
	const Animal *catty = new Cat();
	std::cout << doggy->getType() << " " << std::endl;
	std::cout << catty->getType() << " " << std::endl;
	meta->makeSound();
	catty->makeSound();
	doggy->makeSound();

	delete meta;
	delete doggy;
	delete catty;

	const WrongAnimal *nova = new WrongAnimal();
	const WrongAnimal *k = new WrongCat();
	const WrongCat *l = new WrongCat();
	std::cout << k->getType() << " " << std::endl;
	std::cout << l->getType() << " " << std::endl;
	nova->makeSound();
	k->makeSound();
	std::cout << "NOTE: output of WrongAnimal makeSound() member function"
			  << std::endl;
	l->makeSound();
	std::cout << "NOTE: didn't call the WrongCat destructor" << std::endl;
	delete nova;
	delete k;
	delete l;
	return 0;
}
