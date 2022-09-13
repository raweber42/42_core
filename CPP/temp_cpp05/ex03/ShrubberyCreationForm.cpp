/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:55:32 by raweber           #+#    #+#             */
/*   Updated: 2022/09/13 15:41:59 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

//--------------CONSTRUCTORS/DESTRUCTOR------------------//

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Creation Form", 145 ,137), _target("Default Target") {
	
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145 ,137), _target(target) {
	
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) {
	
	*this = src;
}

//--------------FUNCTIONALS------------------//

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {

	this->setSigned(this->getIfSigned());
	this->_target = rhs._target;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	
	this->checkIfAbleExec(executor);
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
	std::string filename = this->_target + "_shrubbery";
	std::ofstream outfile (filename);

	outfile <<"                                                         ." << std::endl;
	outfile <<"                                              .         ;  " << std::endl;
	outfile <<"                 .              .              ;%     ;;   " << std::endl;
	outfile <<"                   ,           ,                :;%  %;   " << std::endl;
	outfile <<"                    :         ;                   :;%;'     .,   " << std::endl;
	outfile <<"           ,.        %;     %;            ;        %;'    ,;" << std::endl;
	outfile <<"             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
	outfile <<"              %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
	outfile <<"               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
	outfile <<"                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
	outfile <<"                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
	outfile <<"                    `:%;.  :;bd%;          %;@%;'" << std::endl;
	outfile <<"                      `@%:.  :;%.         ;@@%;'  "  << std::endl;
	outfile <<"                        `@%.  `;@%.      ;@@%;     "     << std::endl;
	outfile <<"                          `@%%. `@%%    ;@@%;       "  << std::endl;
	outfile <<"                            ;@%. :@%%  %@@%;       " << std::endl;
	outfile <<"                              %@bd%%%bd%%:;    "  << std::endl;
	outfile <<"                                #@%%%%%:;;" << std::endl;
	outfile <<"                                %@@%%%::;" << std::endl;
	outfile <<"                                %@@@%(o);  . '"        << std::endl;  
	outfile <<"                                %@@@o%;:(.,'   "       << std::endl;
	outfile <<"                            `.. %@@@o%::;       "   << std::endl;
	outfile <<"                               `)@@@o%::;        "  << std::endl;
	outfile <<"                                %@@(o)::;        " << std::endl;
	outfile <<"                               .%@@@@%::;         " << std::endl;
	outfile <<"                               ;%@@@@%::;.         "  << std::endl;
	outfile <<"                              ;%@@@@%%:;;;. " << std::endl;
	outfile <<"                          ...;%@@@@@%%:;;;;,..    credit: Gilo97" << std::endl;
	outfile << std::endl;

	outfile.close();
	std::cout << "Successfully created file " << filename << "!" << std::endl;
}

