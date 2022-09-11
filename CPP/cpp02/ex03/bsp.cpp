/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:02:11 by raweber           #+#    #+#             */
/*   Updated: 2022/09/08 15:15:18 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point) {

	Fixed denom((b.get_y_value() - c.get_y_value()) * (a.get_x_value() - c.get_x_value()) + (c.get_x_value() - b.get_x_value()) * (a.get_y_value() - c.get_y_value()));
	Fixed x(((b.get_y_value() - c.get_y_value()) * (point.get_x_value() - c.get_x_value()) + (c.get_x_value() - b.get_x_value()) * (point.get_y_value() - c.get_y_value())) / denom);
	Fixed y(((c.get_y_value() - a.get_y_value()) * (point.get_x_value() - c.get_x_value()) + (a.get_x_value() - c.get_x_value()) * (point.get_y_value() - c.get_y_value())) / denom);
	Fixed z(Fixed(1) - x - y);
	
	return (Fixed(0) <= x && x <= Fixed(1) && Fixed(0) <= y && y <= Fixed(1) && Fixed(0) <= z && z <= Fixed(1));
}
