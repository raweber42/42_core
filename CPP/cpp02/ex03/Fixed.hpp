/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 07:42:59 by raweber           #+#    #+#             */
/*   Updated: 2022/09/08 08:01:29 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	
	public:
		Fixed(void);
		Fixed(const int param);
		Fixed(const float param);
		~Fixed(void);
		Fixed(Fixed const & src);

		Fixed & operator=(Fixed const & rhs);
		
		//--------new------------------------
		bool operator>(Fixed const & rhs) const;
		bool operator<(Fixed const & rhs) const;
		bool operator>=(Fixed const & rhs) const;
		bool operator<=(Fixed const & rhs) const;
		bool operator==(Fixed const & rhs) const;
		bool operator!=(Fixed const & rhs) const;

		Fixed operator+(Fixed const & rhs) const;
		Fixed operator-(Fixed const & rhs) const;
		Fixed operator*(Fixed const & rhs) const;
		Fixed operator/(Fixed const & rhs) const;

		Fixed & operator++(void);
		Fixed	operator++(int);
		Fixed & operator--(void);
		Fixed	operator--(int);

		static Fixed &			min(Fixed & ref1, Fixed & ref2);
		static const Fixed &	min(Fixed const & ref1, Fixed const & ref2);
		static Fixed &			max(Fixed & ref1, Fixed & ref2);
		static const Fixed &	max(Fixed const & ref1, Fixed const & ref2);
		//---------end new--------------------
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		
	private:
		int					_number;
		static const int	_fract_bits;
};

// An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter.
std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif