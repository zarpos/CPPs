/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:25:13 by drubio-m          #+#    #+#             */
/*   Updated: 2024/10/26 18:05:56 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class Contact
{
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;
		
	public:
		//Getters
		std::string GetFirstName(void);
		std::string GetLastName(void);
		std::string GetNickName(void);
		std::string GetPhoneNumber(void);
		std::string GetDarkestSecret(void);
		
		//Setters
		void SetFirstName(std::string first_name);
		void SetLastName(std::string last_name);
		void SetNickName(std::string nickname);
		void SetPhoneNumber(std::string phone_number);
		void SetDarkestSecret(std::string darkest_secret);
};

void	print_value(std::string value);

#endif