/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 09:25:57 by raweber           #+#    #+#             */
/*   Updated: 2022/09/21 12:09:46 by raweber          ###   ########.fr       */
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

	std::cout << "\nPRINT FORM WITH OPERATOR OVERLOAD" << std::endl;
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	std::cout << form3 << std::endl;
	std::cout << std::endl;
}
