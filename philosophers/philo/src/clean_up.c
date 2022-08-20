/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:56:43 by raweber           #+#    #+#             */
/*   Updated: 2022/07/01 14:57:03 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

// helper function to join all threads
int	join_threads(t_philo_rules *rules, t_philosophers **philosophers)
{
	int	i;

	i = 0;
	while (i < rules->nbr_philosophers)
	{
		if (pthread_join(*philosophers[i]->thread, NULL) != 0)
		{
			printf("Error: Failed to join thread\n");
			clean_up(rules, philosophers);
			return (1);
		}
		i++;
	}
	return (0);
}

void	destroy_mutex_and_clean(t_philo_rules *rules,
		t_philosophers **philosophers)
{
	destroy_mutex(rules);
	clean_up(rules, philosophers);
}

// helper function to destroy all mutexes
void	destroy_mutex(t_philo_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nbr_philosophers)
	{	
		pthread_mutex_destroy(&rules->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&(rules->writing));
	pthread_mutex_destroy(&(rules->death_mutex));
}

// frees all allocated memory
void	clean_up(t_philo_rules *rules, t_philosophers **philosophers)
{
	int	i;

	i = 0;
	while (i < rules->nbr_philosophers)
	{
		if (philosophers[i]->thread)
			free(philosophers[i]->thread);
		if (philosophers[i])
			free(philosophers[i]);
		i++;
	}
	if (philosophers)
		free(philosophers);
	if (rules->forks)
		free(rules->forks);
	if (rules)
		free(rules);
}
