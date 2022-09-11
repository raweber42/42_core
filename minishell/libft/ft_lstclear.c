/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 10:26:49 by raweber           #+#    #+#             */
/*   Updated: 2022/05/02 10:59:19 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp_1;
	t_list	*temp_2;

	if (!lst || !del)
		return ;
	temp_1 = *lst;
	while (temp_1 != NULL)
	{
		temp_2 = temp_1->next;
		del(temp_1->content);
		free(temp_1);
		temp_1 = temp_2;
	}
	*lst = NULL;
}
