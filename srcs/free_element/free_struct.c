/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 13:06:38 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/24 16:13:06 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex_args(t_args *args)
{
	pthread_mutex_destroy(&args->m_end);
	pthread_mutex_destroy(&args->m_write_log);
	pthread_mutex_destroy(&args->m_start_time);
	pthread_mutex_destroy(&args->m_time_to_die);
	pthread_mutex_destroy(&args->m_time_to_eat);
	pthread_mutex_destroy(&args->m_time_to_sleep);
	pthread_mutex_destroy(&args->m_nb_eat);
	pthread_mutex_destroy(&args->m_nb_philo);
}

void	destroy_mutex_philo(t_philo *philo)
{
	pthread_mutex_destroy(&philo->fork);
	pthread_mutex_destroy(&philo->m_first_time);
	pthread_mutex_destroy(&philo->m_nb_eat);
}

void	free_struct(t_args *args, t_philo *philo)
{
	t_philo	*tmp;
	int		i;

	i = 1;
	tmp = philo;
	while (i <= args->nb_philo)
	{	
		tmp = philo->next;
		destroy_mutex_philo(philo);
		free(philo);
		philo = tmp;
		i++;
	}
	philo = NULL;
	destroy_mutex_args(args);
	if (args != NULL)
		free(args);
}

void	join_threads(t_philo *philo, int index)
{
	t_philo	*curr;
	int		i;

	i = 1;
	curr = philo;
	while (i <= index)
	{
		pthread_join(curr->th_philo, NULL);
		curr = curr->next;
		i++;
	}
}
