/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:22:48 by raweber           #+#    #+#             */
/*   Updated: 2022/09/23 12:21:05 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>
#include <cmath>
#include <algorithm>


//--------------CONSTRUCTORS/DESTRUCTOR------------------//

Span::Span(void) : _max_length(0), _cur_length(0) {
	
}

Span::Span(unsigned int n) : _max_length(n), _cur_length(0) {

}

Span::~Span(void) {

}

Span::Span(Span const &src) {
	*this = src;
}

//--------------FUNCTIONALS------------------//

Span & Span::operator=(Span const &rhs) {
	
	this->_max_length = rhs._max_length;
	this->_cur_length = rhs._cur_length;
	this->_arr = rhs._arr;
	return (*this);
}

int	Span::getSize(void) {
	
	return (this->_arr.size());
}

int	Span::getValue(int index) {
	
	return (this->_arr[index]);
}

void Span::addNumber(int number) {
	
	if (this->_cur_length < this->_max_length)
	{
		this->_arr.push_back(number);
		this->_cur_length++;
	}
	else
		throw MaxSizeReachedException();
}

long Span::shortestSpan(void) {
	
	if (this->_cur_length <= 1)
		throw NoSpanPossibleException();
	int shortest = INT_MAX;
	std::sort(this->_arr.begin(), this->_arr.end());
	for (int i = 0; i < this->_cur_length - 1; i++)
	{
		if (abs(this->_arr[i + 1] - this->_arr[i]) < shortest)
			shortest = this->_arr[i + 1] - this->_arr[i];
	}
	return (shortest);
}

long Span::longestSpan(void) {
	
	if (this->_cur_length <= 1)
		throw NoSpanPossibleException();
	std::sort(this->_arr.begin(), this->_arr.end());
	return (abs(this->_arr[this->_cur_length - 1] - this->_arr[0]));	
}

void Span::addMultiple(std::vector<int> toInsert) {

	this->_arr.insert(this->_arr.end(), toInsert.begin(), toInsert.end());
}
