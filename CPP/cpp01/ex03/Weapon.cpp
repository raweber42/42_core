/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 07:08:15 by raweber           #+#    #+#             */
/*   Updated: 2022/09/05 14:27:12 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {//: _type(type) {

	if (type.empty())
		this->_type = "default weapon";
	else
		this->_type = type; // empty name check
}

Weapon::~Weapon(void) {
	
}

std::string Weapon::getType(void) const {

	return (this->_type);
}

void	Weapon::setType(std::string new_type) {
	
	if (new_type.empty())
		this->_type = "default weapon";
	else
		this->_type = new_type; // empty name check
}
