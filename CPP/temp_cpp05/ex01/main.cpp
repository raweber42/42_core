/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 09:25:57 by raweber           #+#    #+#             */
/*   Updated: 2022/09/13 11:30:07 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat ralf("Ralf", 50);
	Form form1("FORM1", 50, 50);

	std::cout << "\n### " << ralf.getName() << " trying to sign the form " << form1.getName() << ":" << std::endl;
	try {
		ralf.signForm(form1);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;


	Form form2("FORM2", 1, 50);
	std::cout << "\n### Check IF " << ralf.getName() << " COULD sign the form " << form2.getName() << ":" << std::endl;
	try {
		form2.beSigned(ralf);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	
	Form form3("FORM3", 150, 50);
	std::cout << "\n### " << ralf.getName() << " trying to sign the form " << form3.getName() << ":" << std::endl;
	try {
		ralf.signForm(form3);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	
	std::cout << "\nTRY INITIALIZING FORM 4 WITH TO_SIGN=0" << std::endl;
	try {
		Form form4("FORM4", 0, 150);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}


	std::cout << "\nTRY INITIALIZING FORM 5 WITH TO_SIGN=151" << std::endl;
	try {
		Form form5("FORM5", 151, 150);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}



// int main(void)
// {
// 	Bureaucrat ted("Ted", 150);
// 	Bureaucrat lilly("Lilly", 1);
// 	Bureaucrat marshall("Marshall", 75);
	
// 	std::cout << "\nTRY INITIALIZING BARNEY WITH GRADE 0" << std::endl;
// 	try {
// 		Bureaucrat barney("barney", 0);
// 	}
// 	catch (Bureaucrat::GradeTooHighException &e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}


// 	std::cout << "\nTRY INITIALIZING BARNEY WITH GRADE 151" << std::endl;
// 	try {
// 		Bureaucrat barney("barney", 151);
// 	}
// 	catch (Bureaucrat::GradeTooLowException &e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}


// 	std::cout << "\nTRY DECREMENTING TED" << std::endl;
// 	try {
// 		ted.decrementGrade();
// 	}
// 	catch (Bureaucrat::GradeTooLowException &e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}
// 	std::cout << "Ted now has the grade: " << ted.getGrade() << std::endl;

	
// 	std::cout << "\nTRY INCREMENTING LILLY" << std::endl;
// 	try {
// 		lilly.incrementGrade();
// 	}
// 	catch (Bureaucrat::GradeTooHighException &e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}
// 	std::cout << "Lilly now has the grade: " << lilly.getGrade() << std::endl;


// 	std::cout << "\nTRY INCREMENTING MARSHALL" << std::endl;
// 	try {
// 		marshall.incrementGrade();
// 	}
// 	catch (Bureaucrat::GradeTooHighException &e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}
// 	std::cout << "Marshall now has the grade: " << marshall.getGrade() << std::endl;


// 	std::cout << "\nTRY DECREMENTING MARSHALL" << std::endl;
// 	try {
// 		marshall.decrementGrade();
// 	}
// 	catch (Bureaucrat::GradeTooLowException &e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}
// 	std::cout << "Marshall now has the grade: " << marshall.getGrade() << "\n" << std::endl;

// 	return (0);
// }