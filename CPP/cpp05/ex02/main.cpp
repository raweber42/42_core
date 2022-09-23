/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 09:25:57 by raweber           #+#    #+#             */
/*   Updated: 2022/09/23 08:26:08 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


int main(void)
{
	Bureaucrat ralf("Ralf", 150);
	Bureaucrat mr_trump("Mr Trump", 1);

	//---------------------SHRUBBERY-----------------------------------------//
	
	std::cout << "\x1B[32m";
	ShrubberyCreationForm shrubbery("boxwood_form");
	std::cout << "\x1B[0m";
	std::cout << "\x1B[34m" <<  "\n### LET RALF TRY TO SIGN THIS!" << "\x1B[0m" << std::endl;
	std::cout << "\n### " << ralf.getName() << " trying to sign the form " << shrubbery.getName() << ":" << std::endl;
	try {
		ralf.signForm(shrubbery);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\x1B[34m" <<  "### LET RALF TRY TO EXECUTE THIS!" << "\x1B[0m" << std::endl;
	std::cout << "\n### " << ralf.getName() << " trying to execute the form " << shrubbery.getName() << ":" << std::endl;
	try {
		shrubbery.execute(ralf);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\x1B[34m" <<  "### LET THE PRESIDENT TRY TO SIGN THIS!" << "\x1B[0m" << std::endl;
	std::cout << "\n### " << mr_trump.getName() << " trying to sign the form " << shrubbery.getName() << ":" << std::endl;
	try {
		mr_trump.signForm(shrubbery);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\x1B[34m" <<  "### LET THE PRESIDENT TRY TO EXECUTE THIS!" << "\x1B[0m" << std::endl;
	std::cout << "\n### " << mr_trump.getName() << " trying to execute the form " << shrubbery.getName() << ":" << std::endl;
	try {
		shrubbery.execute(mr_trump);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;


	//---------------------PRESIDENTIAL PARDON-----------------------------------------//
	std::cout << "\x1B[32m" << "-------------------------------------------------------------------------" << std::endl;	
	PresidentialPardonForm presidential("Executive Order No 1");
	std::cout << "\x1B[0m";

	std::cout << "\n### PREPARING SIGNED FORM FOR EXECUTIVE ORDER..." << std::endl;
		std::cout << "\n### " << mr_trump.getName() << " trying to sign the form " << presidential.getName() << ":" << std::endl;
	try {
		mr_trump.signForm(presidential);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\x1B[34m" <<  "### LET RALF TRY TO EXECUTE THIS!" << "\x1B[0m" << std::endl;
	std::cout << "\n### " << ralf.getName() << " trying to execute the form " << presidential.getName() << ":" << std::endl;
	try {
		presidential.execute(ralf);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\x1B[34m" <<  "### LET THE PRESIDENT TRY TO EXECUTE THIS!" << "\x1B[0m" << std::endl;
	std::cout << "\n### " << mr_trump.getName() << " trying to execute the form " << presidential.getName() << ":" << std::endl;
	try {
		presidential.execute(mr_trump);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	//---------------------ROBOTOMY-----------------------------------------//
	std::cout << "\x1B[32m" << "-------------------------------------------------------------------------" << std::endl;	
	RobotomyRequestForm robotomy("Cook");
	std::cout << "\x1B[0m";

	std::cout << "### PREPARING SIGNED FORM FOR EXECUTIVE ORDER..." << std::endl;
		std::cout << "\n### " << mr_trump.getName() << " trying to sign the form " << robotomy.getName() << ":" << std::endl;
	try {
		mr_trump.signForm(robotomy);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\x1B[34m" <<  "### LET RALF TRY TO EXECUTE THIS!" << "\x1B[0m" << std::endl;
	std::cout << "\n### " << ralf.getName() << " trying to execute the form " << robotomy.getName() << ":" << std::endl;
	try {
		// robotomy.execute(ralf);
		ralf.executeForm(robotomy);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\x1B[34m" << "### LET THE PRESIDENT TRY TO EXECUTE THIS!" << "\x1B[0m" << std::endl;
	std::cout << "\n### " << mr_trump.getName() << " trying to execute the form " << robotomy.getName() << ":" << std::endl;
	try {
		// robotomy.execute(mr_trump);
		mr_trump.executeForm(robotomy);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}
