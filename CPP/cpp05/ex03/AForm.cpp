/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:35:37 by raweber           #+#    #+#             */
/*   Updated: 2022/09/13 09:21:24 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//--------------CONSTRUCTORS/DESTRUCTOR------------------//

AForm::AForm(void) : _name("DEFAULT AFORM"), _grade_to_sign(150), _grade_to_exec(150), _signed(0) {
	
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int to_sign, int to_exec) : _name(name), _grade_to_sign(to_sign), _grade_to_exec(to_exec), _signed(0) {
	
	if (this->_grade_to_sign < 1 || this->_grade_to_exec < 1)
		throw AForm::GradeTooHighException();
	else if (to_sign > 150 || to_sign > 150)
		throw AForm::GradeTooLowException();
	std::cout << "AForm constructor called with name " << this->_name << " minimum grade to sign: " << this->getToSign() << ", minimum grade to execute: " << this->getToExec() << std::endl;
}

AForm::~AForm(void) {
	
	// std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(AForm const &src) : _name(src._name), _grade_to_sign(src._grade_to_sign), _grade_to_exec(src._grade_to_exec), _signed(0) {
	
	*this = src;
	// std::cout << "AForm copy constructor called" << std::endl;
}

//--------------FUNCTIONALS------------------//

const std::string AForm::getName(void) const {

	return (this->_name);
}

int AForm::getToSign(void) const {
	
	return(this->_grade_to_sign);
}

int AForm::getToExec(void) const {
	
	return(this->_grade_to_exec);
}

int AForm::getIfSigned(void) const {

	return (this->_signed);
}

void AForm::beSigned(Bureaucrat guy) {

	if (guy.getGrade() > this->getToSign())
		throw AForm::GradeTooLowException();
	else
		this->setSigned(1);
}

void AForm::setSigned(int status) {

	if (status == 1)
		this->_signed = true;
	else
		return;
}

void AForm::checkIfAbleExec(Bureaucrat const & executor) const {

	if (this->getIfSigned() == 0)
	{
		throw FormNotSignedException();
		return ;
	}
	else if (this->getToExec() < executor.getGrade())
	{
		throw GradeTooLowException();
		return ;
	}
}




//--------------OPERATOR OVERLOAD------------------//


AForm & AForm::operator=(AForm const &rhs) {
	
	this->_signed = rhs._signed;
	return (*this);
}

std::ostream & operator<<(std::ostream & o, AForm const & rhs) {

	o << rhs.getName() << ", minimum grade to sign: " << rhs.getToSign() << ", minimum grade to execute: " << rhs.getToExec() << ". Signed? " << (rhs.getIfSigned()?"Yes":"No");
	return (o);
}

