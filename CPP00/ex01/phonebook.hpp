/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:03:04 by drubio-m          #+#    #+#             */
/*   Updated: 2024/10/26 17:42:21 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "contact.hpp"

class Phonebook 
{
	private:
		Contact _contacts[8];
		//int _index;
		
	public:
		//Getters
		Contact GetContact(int index);
		void show_contact(void);
		void show_full_contact(Contact contact);
		//Setters
		void SetContact(Contact contact, int index);
		void add_contact(int& last_contact);
		Contact new_contact(void);
};

#endif