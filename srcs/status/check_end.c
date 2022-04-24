/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 03:55:34 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/24 02:25:36 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_end(t_args *args)
{
	pthread_mutex_lock(&args->m_end);
	args->end = true;
	pthread_mutex_unlock(&args->m_end);
}

bool check_nb_eat(t_philo *first, int nb_eat, int nb_philo)
{
	t_philo	*curr;
	int		i;

	curr = first;
	i = 1;
	while (i <= nb_philo)
	{
		pthread_mutex_lock(&curr->m_nb_eat);
		if (curr->curr_nb_eat < nb_eat)
			return (false);
		pthread_mutex_unlock(&curr->m_nb_eat);
		i++;
		curr = curr->next;
	}
	return (true);
}

void	check_nb_eat_and_death(t_struct *s)
{
	t_philo	*p;

	p = s->first_philo;
	while (true)
	{
		if ((int) get_current_time(0) - (int) p->first_time >= 
			s->args->time_to_die)
		{
			write_philo_status(p, "died");
			set_end(s->args);
			break ;
		}
		if (check_nb_eat(s->first_philo, s->args->nb_eat, s->args->nb_philo))
		{
			set_end(s->args);
			break ;
		}
		p = p->next;
	}
}

void	check_death(t_struct *s)
{
	t_philo	*p;

	p = s->first_philo;
	while (true)
	{
		if (get_current_time(p->first_time) >=
			(long) s->args->time_to_die)
		{
			write_philo_status(p, "died");
			set_end(s->args);
			break ;
		}
		p = p->next;
	}
}
