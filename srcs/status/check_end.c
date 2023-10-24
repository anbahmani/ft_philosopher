/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 03:55:34 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/24 16:45:29 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_end(t_args *args)
{
	pthread_mutex_lock(&args->m_end);
	args->end = true;
	pthread_mutex_unlock(&args->m_end);
}

bool	check_nb_eat(t_philo *first, int nb_eat)
{
	t_philo	*curr;

	curr = first;
	if (get_nb_eat(curr->args) == -1)
		return (false);
	while (curr->next != first)
	{
		pthread_mutex_lock(&curr->m_nb_eat);
		if (curr->curr_nb_eat < nb_eat)
		{
			pthread_mutex_unlock(&curr->m_nb_eat);
			return (false);
		}
		pthread_mutex_unlock(&curr->m_nb_eat);
		curr = curr->next;
	}
	return (true);
}

void	check_nb_eat_and_death(t_struct *s)
{
	t_philo	*p;

	p = s->first_philo;
	while (!is_dead(s->first_philo) && !check_nb_eat(s->first_philo,
			get_nb_eat(s->args)))
	{
		if (get_current_time(get_philo_first_time(p))
			>= (long) get_time_to_die(s->args))
		{
			write_philo_status(p, "died");
			set_end(s->args);
			break ;
		}
		if (check_nb_eat(s->first_philo, get_nb_eat(s->args)))
			break ;
		p = p->next;
	}
}

void	check_death(t_struct *s)
{
	t_philo	*p;

	p = s->first_philo;
	while (true)
	{
		if (get_current_time(get_philo_first_time(p))
			>= (long) get_time_to_die(s->args))
		{
			write_philo_status(p, "died");
			set_end(s->args);
			break ;
		}
		p = p->next;
	}
}
