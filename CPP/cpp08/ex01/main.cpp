/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:22:58 by raweber           #+#    #+#             */
/*   Updated: 2022/09/23 12:23:01 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void) {

	std::cout << "### CREATE SPAN OF SIZE 5 ###" << std::endl;
	Span testing(5);
	std::cout << "### FILL SPAN WITH FIVE VALUES ###" << std::endl;
	testing.addNumber(-100);
	testing.addNumber(100);
	testing.addNumber(1);
	testing.addNumber(9);
	testing.addNumber(22);
	for (int i = 0; i < testing.getSize(); i++)
		std::cout << "Element Nr." << i << " has the value: " << testing.getValue(i) << std::endl;
	std::cout << "\n### TRY ADDING A SIXTH VALUE ###" << std::endl;
	try {
		testing.addNumber(1);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n### GET THE SHORTEST SPAN ###" << std::endl;
	try {
		std::cout << "Shortest span is: " << testing.shortestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n### GET THE LONGEST SPAN ###" << std::endl;
	try {
		std::cout << "Longest span is: "  << testing.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n### ADD 100,000 VALUES OF '100' TO SPAN ###" << std::endl;
	std::vector<int> toInsert(100000, 100);
	testing.addMultiple(toInsert);
	std::cout << "Array size is now: " << testing.getSize() << std::endl;
	// for (int i = 0; i < testing.getSize(); i++)
	// 	std::cout << "Element Nr." << i << " has the value: " << testing.getValue(i) << std::endl;
	std::cout << "\n### AGAIN: GET THE LONGEST SPAN ###" << std::endl;
	try {
		std::cout << "Longest span is: "  << testing.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;

// 	return 0;
// }