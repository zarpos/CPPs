/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:02:47 by drubio-m          #+#    #+#             */
/*   Updated: 2024/10/28 15:49:47 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>
# include <iomanip>
# include <string>
# include <sstream>
# include <limits>

class Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
		
	public:
		// Constructor por defecto
    	Fixed();

    	// Constructor de copia
    	Fixed(const Fixed &other);
		
		// Operador de asignación
    	Fixed &operator=(const Fixed &other);
		
		~Fixed();
		
		
		//Functions
		// Getter
		int getRawBits(void) const;
		// Setter
    	void setRawBits(int const raw);
};

#endif