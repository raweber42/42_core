/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 09:25:52 by raweber           #+#    #+#             */
/*   Updated: 2022/09/13 12:54:35 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//--------------CONSTRUCTORS/DESTRUCTOR------------------//

Bureaucrat::Bureaucrat(void) : _name("Default name"), _grade(150) {
	
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string new_name) : _name(new_name) {
	
	std::cout << "Bureaucrat constructor called with name " << this->_name << std::endl;
}

Bureaucrat::Bureaucrat(std::string new_name, size_t grade) : _name(new_name) {
	
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
	
	std::cout << "Bureaucrat constructor called with name " << this->_name << " and grade " << this->getGrade() << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
	
	// std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) {
	
	*this = src;
	// std::cout << "Bureaucrat copy constructor called" << std::endl;
}

//--------------FUNCTIONALS------------------//


Bureaucrat & Bureaucrat::operator=(Bureaucrat const &rhs) {
	
	this->_grade = rhs.getGrade();
	return (*this);
}


std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs) {

	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (o);
}

const std::string Bureaucrat::getName(void) const{

	return (this->_name);
}

int Bureaucrat::getGrade(void) const {
	
	return(this->_grade);
}

void Bureaucrat::incrementGrade(void) {

	if (this->getGrade() - 1 < 1 )
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::decrementGrade(void) {

	if (this->getGrade() + 1 > 150 )
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

void Bureaucrat::signForm(AForm &form) {
	
	try {
		form.beSigned(*this);
	}
	catch (const std::exception &e) {
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	
	std::cout << this->getName() << " signed " << form.getName() << std::endl;
	
}