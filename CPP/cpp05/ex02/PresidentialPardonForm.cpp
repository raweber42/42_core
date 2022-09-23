/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:01:14 by raweber           #+#    #+#             */
/*   Updated: 2022/09/21 12:18:58 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "PresidentialPardonForm.hpp"

//--------------CONSTRUCTORS/DESTRUCTOR------------------//

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential Pardon Form", 25, 5), _target("Default Target") {
	
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5), _target(target) {
	
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm() {
	
	*this = src;
}

//--------------FUNCTIONALS------------------//

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {

	this->setSigned(this->getIfSigned());
	this->_target = rhs._target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {

	// if (this->getIfSigned() == 0)
	// {
	// 	throw FormNotSignedException();
	// 	return ;
	// }
	// else if (this->getToExec() < executor.getGrade())
	// {
	// 	throw GradeTooLowException();
	// 	return ;
	// }
	this->checkIfAbleExec(executor);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;	
};
