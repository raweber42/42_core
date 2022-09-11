/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 07:43:27 by raweber           #+#    #+#             */
/*   Updated: 2022/09/09 17:06:58 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {

	Fixed a (1);
	Fixed b (6.05f);

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << std::endl;
	std::cout << "TEST basic calulations" << std::endl;
	std::cout << "result addition: " << (a + b) << std::endl;
	std::cout << "result subtraction: " << (a - b) << std::endl;
	std::cout << "result multiplication: " << (a * b) << std::endl;
	std::cout << "result division: " << (a / b) << std::endl;
	std::cout << std::endl;
	std::cout << "TEST ++/--" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "result a++: " << (a++) << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "result ++a: " << (++a) << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "result a--: " << (a--) << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "result --a: " << (--a) << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << std::endl;
	std::cout << "TEST comparison" << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;
	std::cout << std::endl;
	std::cout << "TEST min/max" << std::endl;
	std::cout << "min(a,b): " << (Fixed::min(a,b)) << std::endl;
	std::cout << "max(a,b): " << (Fixed::max(a,b)) << std::endl;
	std::cout << std::endl;

	return 0;
}


// FROM SUBJECT:

// int main( void ) {

// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }