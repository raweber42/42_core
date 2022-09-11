/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 07:42:49 by raweber           #+#    #+#             */
/*   Updated: 2022/09/09 16:56:25 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fract_bits = 8;

Fixed::Fixed() {
	
	std::cout << "Default constructor called" << std::endl;
	_number = 0;
}

//--------------FIRST NEW---------------------------//
Fixed::Fixed(const int param) {
	
	std::cout << "Int constructor called" << std::endl;
	this->_number = param << this->_fract_bits;
}

Fixed::Fixed(const float param) {

	std::cout << "Float constructor called" << std::endl;
	this->_number = roundf(param * (1 << this->_fract_bits));
}
//--------------END FIRST NEW-----------------------//

Fixed::Fixed(Fixed const & src) {
	
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed & Fixed::operator=(Fixed const & rhs) {
	
	std::cout << "Copy assignment operator called" << std::endl;
	this->_number = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_number);
}

void Fixed::setRawBits(int const raw) {
	
	// std::cout << "setRawBits member function called" << std::endl;
	this->_number = raw;
}

//--------------SECOND NEW---------------------------//

float	Fixed::toFloat(void) const {
	
	return ((float)this->_number / (float)(1 << this->_fract_bits));
}

int		Fixed::toInt(void) const {
	
	return (this->_number >> this->_fract_bits);
}

// An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter.
std::ostream & operator<<(std::ostream & o, Fixed const & rhs) {

	o << rhs.toFloat();
	return (o);
}

//--------------END SECOND NEW---------------------------//
