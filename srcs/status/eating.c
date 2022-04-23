/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:14:37 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/23 22:27:39 by abahmani         ###   ########.fr       */
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
}

void	eating(t_philo *philo)
{
	taking_forks(philo);
	write_philo_status(philo, "is eating");
	ft_usleep((long) philo->args.time_to_eat);
	philo->first_time = get_current_time(0);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
	pthread_mutex_lock(&philo->m_nb_eat);
	if (philo->args.optional_arg)
		philo->curr_nb_eat++;
	pthread_mutex_unlock(&philo->m_nb_eat);
}
