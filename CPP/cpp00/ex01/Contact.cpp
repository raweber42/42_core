/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:14:11 by raweber           #+#    #+#             */
/*   Updated: 2022/09/03 11:39:28 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

// ##---------------CONSTRUCTOR + DESTRUCTOR--------------------##

Contact::Contact(void) {
	
	// std::cout << "Contact constructor called" << std::endl;
	// return ;
}

Contact::~Contact(void) {
	
	// std::cout << "Contact destructor called" << std::endl;
	// return ;
}

// ##---------------GETTERS--------------------##

int	Contact::get_index(void) {
	
	return (this->index);
}

std::string	Contact::get_first_name(void) {
	
	return (this->first_name);
}

std::string	Contact::get_last_name(void) {
	
	return (this->last_name);
}

std::string	Contact::get_nick_name(void) {
	
	return (this->nick_name);
}

std::string	Contact::get_phone_number(void) {
	
	return (this->phone_number);
}

std::string	Contact::get_secret(void) {
	
	return (this->darkest_secret);
}

// ##---------------SETTERS--------------------##

void	Contact::set_index(int value) {
	
	this->index = value;
}

void	Contact::set_first_name(std::string value) {
	
	this->first_name = value;
}

void	Contact::set_last_name(std::string value) {
	
	this->last_name = value;
}

void	Contact::set_nick_name(std::string value) {
	
	this->nick_name = value;
}

void	Contact::set_phone_number(std::string value) {
	
	this->phone_number = value;
}

void	Contact::set_secret(std::string value) {
	
	this->darkest_secret = value;
}
