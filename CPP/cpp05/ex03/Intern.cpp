/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:56:06 by raweber           #+#    #+#             */
/*   Updated: 2022/09/13 19:07:23 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


//--------------CONSTRUCTORS/DESTRUCTOR------------------//

Intern::Intern(void) {
	
}

Intern::~Intern(void) {
	
}

Intern::Intern(Intern const &src) {
	
	*this = src;
}

Intern & Intern::operator=(Intern const &rhs) {
	
	(void)rhs;
	return (*this);
}

//--------------FUNCTIONALS------------------//


AForm *Intern::makeShrubbery(std::string target) {
	
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makePardon(std::string target) {
	
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeRobotomy(std::string target) {
	
	return (new RobotomyRequestForm(target));
}

AForm * Intern::makeForm(std::string form_name, std::string target) {

	std::string arr[3] = {"ShrubberyCreationForm", "PresidentialPardonForm", "RobotomyRequestForm"};
	AForm *(Intern::*fptr[4])(std::string) = {&Intern::makeShrubbery, &Intern::makePardon, &Intern::makeRobotomy};
	
	int i;	
	for (i = 0; i < 3; i++)
		if (!form_name.compare(arr[i]))
		{
			return ((this->*fptr[i])(target));
		}
	std::cout << "Intern was unable to create the form " << form_name << ", it doesn't exist!" << std::endl;
	return NULL;
}
