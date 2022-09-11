/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 07:42:49 by raweber           #+#    #+#             */
/*   Updated: 2022/09/09 17:00:37 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fract_bits = 8;

Fixed::Fixed() {
	
	// std::cout << "Default constructor called" << std::endl;
	_number = 0;
}

Fixed::Fixed(const int param) {
	
	// std::cout << "Int constructor called" << std::endl;
	this->_number = param << this->_fract_bits;
}

Fixed::Fixed(const float param) {

	// std::cout << "Float constructor called" << std::endl;
	this->_number = roundf(param * (1 << this->_fract_bits));
}

Fixed::Fixed(Fixed const & src) {
	
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed & Fixed::operator=(Fixed const & rhs) {
	
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_number = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_number);
}

void Fixed::setRawBits(int const raw) {
	
	// std::cout << "setRawBits member function called" << std::endl;
	this->_number = raw;
}

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

//--------------NEW---------------------------//

bool Fixed::operator>(Fixed const & rhs) const {

	if (this->_number > rhs.getRawBits())
		return (true);
	else
		return (false);
}
bool Fixed::operator<(Fixed const & rhs) const {

	if (this->_number < rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator>=(Fixed const & rhs) const {

	if (this->_number >= rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator<=(Fixed const & rhs) const {

	if (this->_number <= rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator==(Fixed const & rhs) const {

	if (this->_number == rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator!=(Fixed const & rhs) const {

	if (this->_number != rhs.getRawBits())
		return (true);
	else
		return (false);
}

Fixed Fixed::operator+(Fixed const & rhs) const {

	Fixed ret;
	ret.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (ret);
}

Fixed  Fixed::operator-(Fixed const & rhs) const {

	Fixed ret;
	ret.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (ret);
}

Fixed  Fixed::operator*(Fixed const & rhs) const {

	Fixed ret(this->toFloat() * rhs.toFloat());
	return (ret);
}

Fixed  Fixed::operator/(Fixed const & rhs) const {

	Fixed ret(this->toFloat() / rhs.toFloat());
	return (ret);
}

Fixed & Fixed::operator++(void) {
	
	this->_number++;
	return (*this);
}

Fixed Fixed::operator++(int) {
	
	Fixed ret(*this);

	this->_number++;
	return (ret);
}

Fixed & Fixed::operator--(void) {
	
	this->_number--;
	return (*this);
}

Fixed Fixed::operator--(int) {
	
	Fixed ret(*this);

	this->_number--;
	return (ret);
}

Fixed & Fixed::min(Fixed & ref1, Fixed & ref2) {

	if (ref1.getRawBits() > ref2.getRawBits())
		return (ref2);
	else
		return (ref1);
}

const Fixed & Fixed::min(Fixed const & ref1, Fixed const & ref2) {

	if (ref1.getRawBits() > ref2.getRawBits())
		return (ref2);
	else
		return (ref1);
}

Fixed & Fixed::max(Fixed & ref1, Fixed & ref2) {

	if (ref1.getRawBits() < ref2.getRawBits())
		return (ref2);
	else
		return (ref1);
}

const Fixed & Fixed::max(Fixed const & ref1, Fixed const & ref2) {

	if (ref1.getRawBits() < ref2.getRawBits())
		return (ref2);
	else
		return (ref1);
}