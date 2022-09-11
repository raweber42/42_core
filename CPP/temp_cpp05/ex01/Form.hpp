/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:35:39 by raweber           #+#    #+#             */
/*   Updated: 2022/09/11 18:39:07 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	public:
		Form(void);
		Form(std::string name, int to_sign, int to_exec);
		~Form(void);
		Form(Form const &src);

		Form & operator=(Form const &rhs);
		
		const std::string 	getName(void) const;
		int					getToSign(void) const;
		int 				getToExec(void) const;
		int 				getIfSigned(void) const;
		void				beSigned(Bureaucrat guy);
	
		//--------Exception classes-------------------//
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Exception: Grade is too high for form!");
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what () const throw () {
					return ("Exception: Grade is too low for form!");
				}
		};
		//--------Exception classes end ---------------//

	private:
		const std::string	_name;
		const int			_grade_to_sign;
		const int			_grade_to_exec;
		bool				_signed;
};

std::ostream & operator<<(std::ostream & o, Form const & rhs);


#endif