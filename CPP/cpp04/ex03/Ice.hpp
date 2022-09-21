/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:22:39 by raweber           #+#    #+#             */
/*   Updated: 2022/09/10 12:16:59 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {

	public:
		Ice(void);
		Ice(Ice const &src);
		~Ice(void);
		Ice & operator=(Ice const &rhs);

		Ice 	*clone() const;
		void	use(ICharacter& target);

	private:
		
};

#endif