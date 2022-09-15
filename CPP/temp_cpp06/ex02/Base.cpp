/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:20:41 by raweber           #+#    #+#             */
/*   Updated: 2022/09/15 16:07:46 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(void) {
	
	// std::cout << "Base destructor called" << std::endl;
}

Base * generate(void) {
	
	srand((unsigned int)time(NULL));
	int randNbr = rand() % 3;
	switch (randNbr)
	{
		case 0:
			return (static_cast<Base *>(new A));
			break;
		case 1:
			return (static_cast<Base *>(new B));
			break;
		case 2:
			return (static_cast<Base *>(new C));
			break;
		default:
			return (NULL);
	}
}

void	identify(Base* p) {
	
	if (dynamic_cast<A *>(p))
		std::cout << "Type of pointer is <A>" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Type of pointer is <B>" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Type of pointer is <C>" << std::endl;
	else
		std::cout << "Type of pointer is <INVALID>" << std::endl;
}

void	identify(Base& p) {

	Base ref;
	try {
		ref = dynamic_cast<A &>(p);
		std::cout << "Type of reference is <A>" << std::endl;
	}
	catch (std::bad_cast &bc) {
		
	}
	try {
		ref = dynamic_cast<B &>(p);
		std::cout << "Type of reference is <B>" << std::endl;
	}
	catch (std::bad_cast &bc) {
		
	}
	try {
		ref = dynamic_cast<C &>(p);
		std::cout << "Type of reference is <C>" << std::endl;
	}
	catch (std::bad_cast &bc) {
		
	}
}