/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:27:29 by raweber           #+#    #+#             */
/*   Updated: 2022/07/01 15:17:54 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

// helper to safe lines: intializes rules and mutexes
int	init_rules_and_mutex(char **argv, int argc, t_philo_rules *rules)
{
	if (init_rules(argv, argc, rules))
	{
		printf("Error: Invalid input\n");
		free(rules);
		return (1);
	}
	if (init_mutex(rules))
	{
		printf("Error: Could not initialize mutex\n");
		free(rules->forks);
		free(rules);
		return (1);
	}
	rules->start_time = ft_time();
	return (0);
}

// initializes and checks rules by reading the command line arguments
int	init_rules(char **argv, int argc, t_philo_rules *rules)
{
	rules->nbr_philosophers = philo_atoi(argv[1]);
	if (rules->nbr_philosophers == 0)
		return (1);
	rules->time_to_die = philo_atoi(argv[2]);
	rules->time_to_eat = philo_atoi(argv[3]);
	rules->time_to_sleep = philo_atoi(argv[4]);
	rules->dead_philosopher = 0;
	if (argc == 6)
		rules->eat_x_times = philo_atoi(argv[5]);
	else
		rules->eat_x_times = -1;
	if (rules->nbr_philosophers < 0 || rules->time_to_die < 0
		|| rules->time_to_eat < 0 || rules->time_to_sleep < 0
		|| rules->eat_x_times < -1)
		return (1);
	return (0);
}

// initializes a thread and returns its pointer
pthread_t	*init_thread(t_philosophers *philosopher)
{
	pthread_t	*thread;

	thread = malloc(sizeof(pthread_t));
	if (!thread)
		return (NULL);
	if (pthread_create(thread, NULL, &routine, philosopher))
	{
		printf("Error: Failed to create thread");
		free(thread);
		return (NULL);
	}
	return (thread);
}

// initializes each philosopher (delay for uneven philosophers)
int	init_philosophers(t_philo_rules *rules, t_philosophers **philosophers)
{
	int		i;

	i = 0;
	while (i < rules->nbr_philosophers)
	{
		philosophers[i] = malloc(sizeof(t_philosophers));
		if (!philosophers[i])
			return (1);
		philosophers[i]->rules = rules;
		philosophers[i]->id = i;
		philosophers[i]->last_meal = rules->start_time;
		philosophers[i]->eat_x_times = rules->eat_x_times;
		philosophers[i]->fork_id_left = i;
		philosophers[i]->fork_id_right = (i + 1) % rules->nbr_philosophers;
		if (i % 2)
			usleep(50);
		philosophers[i]->thread = init_thread(philosophers[i]);
		if (philosophers[i++]->thread == NULL)
		{
			clean_up(rules, philosophers);
			printf("Error: Could not initialize philosophers\n");
			return (1);
		}
	}
	return (0);
}

// initializes mutexes for forks, the print function and the death
int	init_mutex(t_philo_rules *rules)
{
	int	i;

	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->nbr_philosophers);
	if (!rules->forks)
		return (1);
	i = 0;
	while (i < rules->nbr_philosophers)
	{
		if (pthread_mutex_init(&(rules->forks[i]), NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&(rules->writing), NULL))
		return (1);
	if (pthread_mutex_init(&(rules->death_mutex), NULL))
		return (1);
	return (0);
}
