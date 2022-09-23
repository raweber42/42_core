/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:01:14 by raweber           #+#    #+#             */
/*   Updated: 2022/09/21 12:18:46 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "RobotomyRequestForm.hpp"

//--------------CONSTRUCTORS/DESTRUCTOR------------------//

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Request Form", 72, 45), _target("Default Target") {
	
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45), _target(target) {
	
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm() {
	
	*this = src;
}

//--------------FUNCTIONALS------------------//

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {

	this->setSigned(this->getIfSigned());
	this->_target = rhs._target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {

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
	srand((unsigned int)time(NULL));
	std::cout << "Brrrr......Drilling.....Brrrrrr" << std::endl;
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomization has failed!" << std::endl;
	
};
