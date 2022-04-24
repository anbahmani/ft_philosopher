/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:14:37 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/24 02:40:35 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	write_philo_status(philo, "has taken a fork");
	if (philo->next != philo)
	{
		pthread_mutex_lock(&philo->next->fork);
		write_philo_status(philo, "has taken a fork"); 
	}
	while (philo->next == philo)
	{
		ft_usleep(10);
	}
}

void	eating(t_philo *philo)
{
	if (!is_dead(philo))
	{
		taking_forks(philo);
		write_philo_status(philo, "is eating");
		philo->first_time = get_current_time(0);
		ft_usleep((long) philo->args->time_to_eat);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		pthread_mutex_lock(&philo->m_nb_eat);
		if (philo->args->optional_arg)
			philo->curr_nb_eat++;
		pthread_mutex_unlock(&philo->m_nb_eat);
	}
}
