/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 00:31:50 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/24 22:11:47 by abahmani         ###   ########.fr       */
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
	int 	time_to_sleep;
	bool	optional_arg;
	int		nb_eat;
}	t_args;

typedef struct s_time
{
	unsigned long	start;
	unsigned long	first;
	unsigned long	last;
}	t_time;

typedef struct s_philo
{
	int				index;
	bool			alive;
	t_args			arg;
	t_time			time;
	struct s_philo	*next;
	struct s_philo	*previous;
}	t_philo;


int		ft_atoi(const char *str);

#endif