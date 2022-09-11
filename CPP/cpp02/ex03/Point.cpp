/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:53:52 by raweber           #+#    #+#             */
/*   Updated: 2022/09/08 11:18:43 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(Fixed(0)), _y(Fixed(0)) {

}

Point::Point(const float a, const float b) : _x(a), _y(b){

}

Point::Point(Point const & src) : _x(src.get_x_value()), _y(src.get_y_value()) {
	
}

Point::~Point(void) {

}

Point & Point::operator=(Point const &) {
	
	return (*this); // like this?
}

Fixed const & Point::get_x_value(void) const {

	return (this->_x);
}

Fixed const & Point::get_y_value(void) const {
	
	return (this->_y);
}
