/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:23:51 by drubio-m          #+#    #+#             */
/*   Updated: 2024/10/27 22:27:24 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>
# include <string>
# include <map>
# include <sstream>

class Harl
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		typedef void(Harl::*ft_ptr)();
		std::map <std::string, ft_ptr> mp;
		
	public:
		Harl();
		~Harl();
		void complain(std::string level);
};



#endif