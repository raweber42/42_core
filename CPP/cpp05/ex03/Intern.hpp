/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:56:04 by raweber           #+#    #+#             */
/*   Updated: 2022/09/13 19:02:24 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern {

	public:
		Intern(void);
		~Intern(void);
		Intern(Intern const &src);
		
		Intern & operator=(Intern const &rhs);
		
		AForm *makeShrubbery(std::string target);
		AForm *makePardon(std::string target);
		AForm *makeRobotomy(std::string target);	
		AForm *makeForm(std::string form_name, std::string target);
		
	private:
	
};

#endif