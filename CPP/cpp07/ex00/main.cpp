/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:50:24 by raweber           #+#    #+#             */
/*   Updated: 2022/09/23 12:02:56 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main( void ) {
	int a = 2;
	int b = 3;
	std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "After swap: c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << "\nMY ADDITIONAL TEST" << std::endl;
	double e = 123.456;
	double f = 789.012;
	std::cout << "Before swap: e = " << e << ", f = " << f << std::endl;
	::swap(e, f);
	std::cout << "After swap: e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
	char g = 'A';
	char h = 'Z';
	std::cout << "Before swap: g = " << g << ", h = " << h << std::endl;
	::swap(g, h);
	std::cout << "After swap: e = " << e << ", f = " << f << std::endl;
	std::cout << "g = " << g << ", h = " << h << std::endl;
	std::cout << "min( g, h ) = " << ::min( g, h ) << std::endl;
	std::cout << "max( g, h ) = " << ::max( g, h ) << std::endl << std::endl;

	std::cout << "Show that min() returns second argument if both arguments have the same value:" << std::endl;
	int i = 0, j = 0;
	std::cout << "i=0, j=0, &i = " << &i << " &j = " << &j << std::endl;
	std::cout << ">>> &min(i, j): " << &min(i,j) << std::endl;
	
	return 0;
}