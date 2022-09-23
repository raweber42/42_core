/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:35:37 by raweber           #+#    #+#             */
/*   Updated: 2022/09/21 12:17:50 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//--------------CONSTRUCTORS/DESTRUCTOR------------------//

Form::Form(void) : _name("DEFAULT FORM"), _grade_to_sign(150), _grade_to_exec(150), _signed(false) {
	
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int to_sign, int to_exec) : _name(name), _grade_to_sign(to_sign), _grade_to_exec(to_exec), _signed(false) {
	
	if (this->_grade_to_sign < 1 || this->_grade_to_exec < 1)
		throw Form::GradeTooHighException();
	else if (to_sign > 150 || to_sign > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form constructor called with name " << this->_name << " minimum grade to sign: " << this->getToSign() << ", minimum grade to execute: " << this->getToExec() << std::endl;
}

Form::~Form(void) {
	
	// std::cout << "Form destructor called" << std::endl;
}

Form::Form(Form const &src) : _name(src._name), _grade_to_sign(src._grade_to_sign), _grade_to_exec(src._grade_to_exec), _signed(false) {
	
	*this = src;
	// std::cout << "Form copy constructor called" << std::endl;
}

//--------------FUNCTIONALS------------------//

const std::string Form::getName(void) const {

	return (this->_name);
}

int Form::getToSign(void) const {
	
	return(this->_grade_to_sign);
}

int Form::getToExec(void) const {
	
	return(this->_grade_to_exec);
}

bool Form::getIfSigned(void) const {

	return (this->_signed);
}

void Form::beSigned(Bureaucrat &guy) {

	if (guy.getGrade() > this->getToSign())
		throw Form::GradeTooLowException();
	this->_signed = true;
}



//--------------OPERATOR OVERLOAD------------------//


Form & Form::operator=(Form const &rhs) {
	
	this->_signed = rhs._signed;
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Form const & rhs) {

	o << rhs.getName() << ", minimum grade to sign: " << rhs.getToSign() << ", minimum grade to execute: " << rhs.getToExec() << ". Signed? " << (rhs.getIfSigned()?"Yes":"No");
	return (o);
}

