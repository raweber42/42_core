/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:50:57 by raweber           #+#    #+#             */
/*   Updated: 2022/09/16 17:02:51 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array {
	
	public:
		Array(void) : _arr(new T[0]), _size(0) {};
		Array(unsigned int n) : _arr(new T[n]), _size(n) {};
		~Array(void) {delete[] this->_arr;};
		Array(Array const &src) {*this = src;};

		Array & operator=(Array const &rhs) {
			
			delete [] this->_arr;
			this->_arr = new T[rhs.size()];
			this->_size = rhs._size;
			for (unsigned int i = 0; i < this->_size; i++)
				this->_arr[i] = rhs._arr[i];
			return (*this);
		};
		T & operator[](unsigned int index) {
			
			if (index < 0 || index > _size - 1)
				throw OutOfBoundException();
			return (this->_arr[index]);
		}

		int	size(void) const {return (this->_size);};

		//--------Exception classes-------------------//
		class OutOfBoundException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Exception: Index is out of bounds!");
				}
		};

	private:
		T		*_arr; // right so?
		size_t	_size;
};

#endif