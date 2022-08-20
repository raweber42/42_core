/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 10:41:02 by raweber           #+#    #+#             */
/*   Updated: 2022/07/01 14:54:03 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h> // remove?
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo_rules
{
	int				nbr_philosophers;
	long long		time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_x_times;
	long long		start_time;
	int				dead_philosopher;
	pthread_mutex_t	*forks;
	pthread_mutex_t	writing;
	pthread_mutex_t	death_mutex;
}				t_philo_rules;

typedef struct s_philosophers
{
	struct s_philo_rules	*rules;
	pthread_t				*thread;
	int						id;
	long long				last_meal;
	int						time_to_sleep;
	int						eat_x_times;
	int						fork_id_left;
	int						fork_id_right;
}				t_philosophers;

// main.c
int			sub_routine(t_philosophers *cur_philosopher, t_philo_rules *rules);
void		*routine(void *philosopher);

// atoi.c 
int			philo_atoi(const char *str);

// utils.c
long long	ft_time(void);
void		one_philosopher(t_philosophers *cur_philosopher);
void		wait_or_sleep(long long time, t_philosophers *cur_philosopher);
void		print_philo(t_philo_rules *rules, int id, char *string);
int			check_death(t_philosophers *cur_philosopher, t_philo_rules *rules);

// init.c
int			init_rules_and_mutex(char **argv, int argc, t_philo_rules *rules);
int			init_rules(char **argv, int argc, t_philo_rules *rules);
pthread_t	*init_thread(t_philosophers *philosopher);
int			init_philosophers(t_philo_rules *rules,
				t_philosophers **philosophers);
int			init_mutex(t_philo_rules *rules);

// clean_up.c
int			join_threads(t_philo_rules *rules, t_philosophers **philosophers);
void		destroy_mutex_and_clean(t_philo_rules *rules,
				t_philosophers **philosophers);
void		destroy_mutex(t_philo_rules *rules);
void		clean_up(t_philo_rules *rules, t_philosophers **philosophers);

#endif