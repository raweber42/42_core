/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:23:14 by raweber           #+#    #+#             */
/*   Updated: 2022/08/18 19:38:55 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

// helper function to get the current unix time in miliseconds
long long	ft_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

// lets philosopher sleep a given time and checks for death inbetween
void	wait_or_sleep(long long time, t_philosophers *cur_philosopher)
{
	long long	i;

	i = ft_time();
	while (1)
	{
		if ((ft_time() - cur_philosopher->last_meal)
			>= cur_philosopher->rules->time_to_sleep)
		{
			print_philo(cur_philosopher->rules, cur_philosopher->id, "died");
			pthread_mutex_lock(&(cur_philosopher->rules->death_mutex));
			cur_philosopher->rules->dead_philosopher = 1;
			pthread_mutex_unlock(&(cur_philosopher->rules->death_mutex));
			break ;
		}
		if ((ft_time() - i) >= (time))
			break ;
		usleep(50);
	}
	if (cur_philosopher)
		return ;
}

// if only one philosopher, he should die after time to die and do nothing else
void	one_philosopher(t_philosophers *cur_philosopher)
{
	if (cur_philosopher->rules->nbr_philosophers == 1)
	{
		print_philo(cur_philosopher->rules, cur_philosopher->id,
			"has taken a fork");
		wait_or_sleep(cur_philosopher->rules->time_to_die, cur_philosopher);
		print_philo(cur_philosopher->rules, cur_philosopher->id, "died");
		cur_philosopher->rules->dead_philosopher = 1;
	}
}

// helper function to print messages to the terminal
void	print_philo(t_philo_rules *rules, int id, char *string)
{
	pthread_mutex_lock(&(rules->writing));
	pthread_mutex_lock(&(rules->death_mutex));
	if (rules->dead_philosopher == 0)
		printf("%lld %d %s\n", (ft_time() - rules->start_time),
			(id + 1), string);
	pthread_mutex_unlock(&(rules->death_mutex));
	pthread_mutex_unlock(&(rules->writing));
}

// helper to mutex-access rules->dead_philosopher
int	check_death(t_philosophers *cur_philosopher, t_philo_rules *rules)
{
	if ((ft_time() - cur_philosopher->last_meal) >= rules->time_to_die)
	{
		print_philo(rules, cur_philosopher->id, "died");
		pthread_mutex_lock(&(rules->death_mutex));
		rules->dead_philosopher = 1;
		pthread_mutex_unlock(&(rules->death_mutex));
		return (1);
	}
	return (0);
}
