/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 03:55:34 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/23 04:15:43 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		i++;
		curr = curr->next;
	}
	return (true);
}

void	check_nb_eat_and_death(t_struct *s)
{
	t_philo	*p;
	bool	end;

	p = s->first_philo;
	end = false;
	while (!end)
	{
		pthread_mutex_lock(&s->args.m_time_eat);
		if ((int) get_current_time() - (int) p->first_time >= 
			s->args.time_to_die)
		{
			end = true;
			write_philo_status(p, "died");
		}
		pthread_mutex_unlock(&s->args.m_time_eat);
		if (check_nb_eat(s->first_philo, s->args.nb_eat, s->args.nb_philo))
			break ;
		p = p->next;
	}
	join_threads(p, s->args.nb_philo);
	free_struct(&s->args, p);
}

void	check_death(t_struct *s)
{
	t_philo	*p;
	bool	end;

	p = s->first_philo;
	end = false;
	while (!end)
	{
		pthread_mutex_lock(&s->args.m_time_eat);
		if ((int) get_current_time() - (int) p->first_time >= 
			s->args.time_to_die)
			end = true;
		pthread_mutex_unlock(&s->args.m_time_eat);
		p = p->next;
	}
	join_threads(p, s->args.nb_philo);
	free_struct(&s->args, p);
}
