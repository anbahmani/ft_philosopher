/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 00:31:50 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/23 22:25:36 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "error.h"
# include "utils.h"

typedef struct s_args
{
	int		nb_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		time_to_think;
	bool	optional_arg;
	int		nb_eat;
	bool	end;
	unsigned long	start_time;
	pthread_mutex_t	m_write_log;
	pthread_mutex_t m_end;
	pthread_mutex_t	m_start_time;
}	t_args;

typedef struct s_philo
{
	int				index;
	pthread_t		th_philo;
	pthread_mutex_t	fork;
	pthread_mutex_t	m_nb_eat;
	t_args			args;
	long	first_time;
	int				curr_nb_eat;
	struct s_philo	*next;
}	t_philo;

typedef struct s_struct
{
	t_args	args;
	t_philo	*first_philo;
}	t_struct;

int		ft_atoi(const char *str);
t_args	*init_args(int ac, char **av);
long	get_current_time(long time);
void	free_struct(t_args *args, t_philo *philo);
void	*activities_loop(void *tmp);
void	init_philo(t_philo **p, int index, t_args args);
void	init_all_philo(t_struct *s);
void	start_routine(t_struct *s);
void	join_threads(t_philo *philo, int index);
void	taking_forks(t_philo *philo);
void	eating(t_philo *philo);
void	write_philo_status(t_philo *philo, char *status);
void	thinking(t_philo *philo);
void	sleeping(t_philo *philo);
void	check_death(t_struct *s);
void	init_args_mutex(t_args *args);
void	check_nb_eat_and_death(t_struct *s);
bool 	check_nb_eat(t_philo *first, int nb_eat, int nb_philo);
bool	is_dead(t_philo *philo);
void	ft_usleep(long ms);

#endif