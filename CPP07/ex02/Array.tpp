/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drubio-m <drubio-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:52:17 by drubio-m          #+#    #+#             */
/*   Updated: 2025/04/29 23:58:44 by drubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm> // Para std::copy (aunque en C++98 sería mejor usar bucles)

// Constructor por defecto, elements se inicializa a nullptr y size a 0
template <typename T>
Array<T>::Array() : _elements(nullptr), _size(0) {}

// Constructor con tamaño, elements se inicializa a un nuevo array de T
template <typename T>
Array<T>::Array(unsigned int n) : _elements(new T[n]()), // Inicialización por defecto
								  _size(n)
{
}

// Constructor de copia, se crea un nuevo array y se copian los elementos de manera profunda (el bucle)
template <typename T>
Array<T>::Array(const Array &src) : _elements(new T[src._size]),
									_size(src._size)
{
	for (unsigned int i = 0; i < _size; ++i)
	{
		_elements[i] = src._elements[i];
	}
}

// Verifica que el objeto sea diferente, libera la memoria, 
//reserva nueva memoria del tamaño correcto, copia profunda elemento por elemento
template <typename T>
Array<T> &Array<T>::operator=(const Array &rhs)
{
	if (this != &rhs)
	{
		delete[] _elements;
		_size = rhs._size;
		_elements = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
		{
			_elements[i] = rhs._elements[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _elements;
}


// Lanza error si el índice está fuera de límites versión modificable
template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
	{
		throw std::out_of_range("Índice fuera de límites");
	}
	return _elements[index];
}


// Lanza error si el índice está fuera de límites versión constante
template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
	{
		throw std::out_of_range("Índice fuera de límites");
	}
	return _elements[index];
}

// Devuelve el tamaño del array
template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}
