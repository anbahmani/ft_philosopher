/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 15:13:09 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/24 16:12:59 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_args	*init_args(int ac, char **av)
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	if (args == NULL)
	{
		print_error("Bad arguments allocation.");
		return (NULL);
	}
	args->nb_philo = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		args->nb_eat = ft_atoi(av[5]);
	else
		args->nb_eat = -1;
	args->end = false;
	args->start_time = get_current_time(0);
	return (args);
}

bool	init_philo(t_philo **p, int index, t_args *args)
{
	*p = malloc(sizeof(t_philo));
	if (!p)
	{
		p = NULL;
		return (false);
	}
	(*p)->index = index;
	(*p)->args = args;
	(*p)->curr_nb_eat = 0;
	(*p)->first_time = get_current_time(0);
	if (pthread_mutex_init(&(*p)->fork, NULL)
		|| pthread_mutex_init(&(*p)->m_nb_eat, NULL)
		|| pthread_mutex_init(&(*p)->m_first_time, NULL))
		return (false);
	return (true);
}

void	init_all_philo(t_struct *s)
{
	int		index;
	t_philo	*current_philo;

	init_philo(&s->first_philo, 1, s->args);
	if (s->first_philo == NULL)
		return (free_struct(s->args, s->first_philo));
	current_philo = s->first_philo;
	index = 1;
	while (++index <= s->args->nb_philo)
	{
		if (!init_philo(&current_philo->next, index, s->args))
			return (free_struct(s->args, s->first_philo));
		current_philo = current_philo->next;
	}
	current_philo->next = s->first_philo;
}

void	init_args_mutex(t_struct *s)
{
	if (pthread_mutex_init(&s->args->m_write_log, NULL)
		|| pthread_mutex_init(&s->args->m_end, NULL)
		|| pthread_mutex_init(&s->args->m_start_time, NULL)
		|| pthread_mutex_init(&s->args->m_time_to_die, NULL)
		|| pthread_mutex_init(&s->args->m_time_to_eat, NULL)
		|| pthread_mutex_init(&s->args->m_time_to_sleep, NULL)
		|| pthread_mutex_init(&s->args->m_nb_eat, NULL)
		|| pthread_mutex_init(&s->args->m_nb_philo, NULL))
		free_struct(s->args, s->first_philo);
}
