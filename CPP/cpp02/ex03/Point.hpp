/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:54:07 by raweber           #+#    #+#             */
/*   Updated: 2022/09/08 11:18:14 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {

	public:
		Point(void);
		Point(const float a, const float b);
		Point(Point const & src);
		~Point(void);

		Point & operator=(Point const &);
		Fixed const & get_x_value(void) const;
		Fixed const & get_y_value(void) const;

	private:
		Fixed const _x;
		Fixed const _y;
};

#endif