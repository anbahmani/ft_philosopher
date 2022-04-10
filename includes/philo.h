/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../includes/philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 00:31:50 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/26 13:08:53 by abahmani         ###   ########.fr       */
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
	bool	optional_arg;
	int		nb_eat;
	bool	end;
	unsigned long	start_time;
	pthread_mutex_t	m_write_log;
	pthread_mutex_t m_time_eat;
	pthread_mutex_t	m_time_sleep;
	pthread_mutex_t	m_time_think;
	pthread_mutex_t m_optional_arg;
	pthread_mutex_t m_end;
	pthread_mutex_t	m_start_time;

}	t_args;

typedef struct s_philo
{
	int				index;
	pthread_t		th_philo;
	pthread_mutex_t	fork;
	bool			alive;
	t_args			args;
	unsigned long	first_time;
	unsigned long	last_time;
	struct s_philo	*next;
}	t_philo;

typedef struct s_struct
{
	t_args	args;
	t_philo	*first_philo;
}	t_struct;

int		ft_atoi(const char *str);
void	init_args(int ac, char **av, t_args *args);
unsigned int	get_current_time(void);
void	free_struct(t_args *args, t_philo *philo);
void	*activities_loop();
void	init_philo(t_struct *s);
void	start_routine(t_struct *s);
void	join_threads(t_philo *philo, int index);

#endif