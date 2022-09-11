/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:22:39 by raweber           #+#    #+#             */
/*   Updated: 2022/09/11 08:35:02 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {

	public:
		Cure(void);
		Cure(Cure const &src);
		~Cure(void);
		Cure & operator=(Cure const &rhs);

		Cure 	*clone() const;
		void	use(ICharacter& target);

	private:
		
};

#endif