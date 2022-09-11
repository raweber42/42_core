/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 07:43:27 by raweber           #+#    #+#             */
/*   Updated: 2022/09/08 11:46:15 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) { 
	
	Point const a(0, 0);
	Point const b(0, 10);
	Point const c(10, 0);
	Point const d(1, 1);
	Point const e(10, 10);
	Point const f(0, 0);
	Point const g(3, 3);
	Point const h(3, 3);

	std::cout << "\n### THE TRIANGLE ###" << std::endl;
	std::cout << "Point 'a' : x value: " << a.get_x_value() << ", y value: " << a.get_y_value() << std::endl;
	std::cout << "Point 'b' : x value: " << b.get_x_value() << ", y value: " << b.get_y_value() << std::endl;
	std::cout << "Point 'c' : x value: " << c.get_x_value() << ", y value: " << c.get_y_value() << std::endl;
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "### SEARCHING FOR THE POINT ###" << std::endl;
	std::cout << "We are looking for the point with x value: " << d.get_x_value() << " and y value: " << d.get_y_value() << std::endl;
	std::cout << "Is the point inside the triangle? " << (bsp(a, b, c, d) ? "YES" : "NO") << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "### SEARCHING FOR THE POINT ###" << std::endl;
	std::cout << "We are looking for the point with x value: " << e.get_x_value() << " and y value: " << e.get_y_value() << std::endl;
	std::cout << "Is the point inside the triangle? " << (bsp(a, b, c, e) ? "YES" : "NO") << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "### SEARCHING FOR THE POINT ###" << std::endl;
	std::cout << "We are looking for the point with x value: " << f.get_x_value() << " and y value: " << f.get_y_value() << std::endl;
	std::cout << "Is the point inside the triangle? " << (bsp(a, b, c, f) ? "YES" : "NO") << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "### SEARCHING FOR THE POINT ###" << std::endl;
	std::cout << "We are looking for the point with x value: " << g.get_x_value() << " and y value: " << g.get_y_value() << std::endl;
	std::cout << "Is the point inside the triangle? " << (bsp(a, b, c, g) ? "YES" : "NO") << std::endl;

	std::cout << "\n### THE END ###\n" << std::endl;
	return (0);
}