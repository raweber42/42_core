/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:58:28 by raweber           #+#    #+#             */
/*   Updated: 2022/06/10 15:03:48 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_list	*ps_lstnew(int content)
{
	t_ps_list	*new_node;

	new_node = malloc(sizeof(t_ps_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

int	ps_lstsize(t_ps_list **lst)
{
	t_ps_list	*temp;
	int			size;

	temp = *lst;
	size = 0;
	if (!temp)
		return (size);
	size++;
	while (temp->next != NULL)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}

void	ps_lstadd_front(t_ps_list **lst, t_ps_list *new)
{
	new->next = *lst;
	*lst = new;
}

void	ps_lstadd_back(t_ps_list **lst, t_ps_list *new)
{	
	t_ps_list	*temp;

	temp = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
	}
}
