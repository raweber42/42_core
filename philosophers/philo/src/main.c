/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 10:40:39 by raweber           #+#    #+#             */
/*   Updated: 2022/08/04 08:38:59 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

// line saver for sub_routine
int	sub_sub_routine(t_philosophers *cur_philosopher, t_philo_rules *rules)
{
	if (check_death(cur_philosopher, rules))
	{
		pthread_mutex_unlock(&(rules->forks[cur_philosopher->fork_id_left]));
		pthread_mutex_unlock(&(rules->forks[cur_philosopher->fork_id_right]));
		return (1);
	}
	pthread_mutex_unlock(&(rules->forks[cur_philosopher->fork_id_left]));
	pthread_mutex_unlock(&(rules->forks[cur_philosopher->fork_id_right]));
	print_philo(rules, cur_philosopher->id, "is sleeping");
	wait_or_sleep(rules->time_to_eat, cur_philosopher);
	print_philo(rules, cur_philosopher->id, "is thinking");
	if (check_death(cur_philosopher, rules))
		return (1);
	return (0);
}

// sub routine that handles the different states of the philosophers
// and checks regularly, if a philosopher died (and returns true then)
int	sub_routine(t_philosophers *cur_philosopher, t_philo_rules *rules)
{
	if (check_death(cur_philosopher, rules))
		return (1);
	pthread_mutex_lock(&(rules->forks[cur_philosopher->fork_id_left]));
	print_philo(rules, cur_philosopher->id, "has taken a fork");
	if (check_death(cur_philosopher, rules))
	{
		pthread_mutex_unlock(&(rules->forks[cur_philosopher->fork_id_left]));
		return (1);
	}
	pthread_mutex_lock(&(rules->forks[cur_philosopher->fork_id_right]));
	print_philo(rules, cur_philosopher->id, "has taken a fork");
	if (check_death(cur_philosopher, rules))
	{
		pthread_mutex_unlock(&(rules->forks[cur_philosopher->fork_id_left]));
		pthread_mutex_unlock(&(rules->forks[cur_philosopher->fork_id_right]));
		return (1);
	}
	cur_philosopher->eat_x_times--;
	cur_philosopher->last_meal = ft_time();
	print_philo(rules, cur_philosopher->id, "is eating");
	wait_or_sleep(rules->time_to_eat, cur_philosopher);
	if (sub_sub_routine(cur_philosopher, rules))
		return (1);
	return (0);
}

/* 
function called by each thread:
iterates until:
-> a philosopher dies
-> all philosophers had all their meals
-> ... or runs infinitely
*/
void	*routine(void *philosopher)
{
	t_philo_rules	*rules;
	t_philosophers	*cur_philosopher;

	rules = ((t_philosophers *)philosopher)->rules;
	cur_philosopher = ((t_philosophers *)philosopher);
	one_philosopher(cur_philosopher);
	while (cur_philosopher->eat_x_times)
	{
		if (sub_routine(cur_philosopher, rules))
			break ;
	}
	return (NULL);
}

// allocates rules and philosophers, 
// starts the threading and cleans up
int	main(int argc, char **argv)
{
	t_philo_rules			*rules;
	t_philosophers			**philosophers;

	if (argc != 5 && argc != 6)
	{
		printf("Error: Wrong number of arguments\n");
		return (1);
	}
	rules = malloc(sizeof(t_philo_rules));
	if (!rules)
		return (1);
	if (init_rules_and_mutex(argv, argc, rules))
		return (1);
	philosophers = malloc(sizeof(t_philosophers *) * rules->nbr_philosophers);
	if (!philosophers)
	{
		free(rules);
		return (1);
	}
	if (init_philosophers(rules, philosophers))
		return (1);
	if (join_threads(rules, philosophers))
		return (1);
	destroy_mutex_and_clean(rules, philosophers);
	return (0);
}
