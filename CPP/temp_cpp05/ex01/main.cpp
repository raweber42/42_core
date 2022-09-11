/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 09:25:57 by raweber           #+#    #+#             */
/*   Updated: 2022/09/11 18:39:20 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat ralf("Ralf", 2);
	Form form1("FORM1", 1, 65);
	try {
		form1.beSigned(ralf);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	// std::cout << form1 << std::endl;
}

// NOW: THOROUGH TESTING!!!



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