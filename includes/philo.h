/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 00:31:50 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/24 17:08:53 by abahmani         ###   ########.fr       */
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
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	bool			end;
	unsigned long	start_time;
	pthread_mutex_t	m_write_log;
	pthread_mutex_t	m_end;
	pthread_mutex_t	m_start_time;
	pthread_mutex_t	m_time_to_die;
	pthread_mutex_t	m_time_to_eat;
	pthread_mutex_t	m_time_to_sleep;
	pthread_mutex_t	m_nb_eat;
	pthread_mutex_t	m_nb_philo;
}	t_args;

typedef struct s_philo
{
	int				index;
	pthread_t		th_philo;
	pthread_mutex_t	fork;
	pthread_mutex_t	m_nb_eat;
	pthread_mutex_t	m_first_time;
	pthread_mutex_t	m_eat_or_die;
	t_args			*args;
	long			first_time;
	int				curr_nb_eat;
	struct s_philo	*next;
}	t_philo;

typedef struct s_struct
{
	t_args	*args;
	t_philo	*first_philo;
}	t_struct;

/*----------------------------Initalisation------------------------------*/

t_args	*init_args(int ac, char **av);
bool	init_philo(t_philo **p, int index, t_args *args);
void	init_all_philo(t_struct *s);
void	init_args_mutex(t_struct *s);

/*-------------------------------Activities-----------------------------------*/

void	taking_forks(t_philo *philo);
void	taking_forks_philo_alone(t_philo *philo);
void	eating(t_philo *philo);
void	thinking(t_philo *philo);
void	sleeping(t_philo *philo);
void	ft_usleep(long ms);
void	write_philo_status(t_philo *philo, char *status);

/*------------------------------Destroying/Free-------------------------------*/

void	destroy_mutex_args(t_args *s_args);
void	destroy_mutex_philo(t_philo *philo);
void	free_struct(t_args *args, t_philo *philo);

/*---------------------------------Getter-------------------------------------*/

int		get_time_to_die(t_args *args);
int		get_time_to_eat(t_args *args);
int		get_time_to_sleep(t_args *args);
int		get_nb_eat(t_args *args);
long	get_philo_first_time(t_philo *philo);
long	get_current_time(long time);
int		get_nb_philo(t_args *args);

/*------------------------------Death checking--------------------------------*/

void	check_death(t_struct *s);
void	check_nb_eat_and_death(t_struct *s);
bool	check_nb_eat(t_philo *first, int nb_eat);
bool	is_dead(t_philo *philo);

/*----------------------------------Main part---------------------------------*/

void	*activities_loop(void *tmp);
void	start_routine(t_struct *s);
void	join_threads(t_philo *philo, int index);

#endif