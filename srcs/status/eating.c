/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:14:37 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/24 17:08:37 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking_forks_philo_alone(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	write_philo_status(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->fork);
	ft_usleep(get_time_to_die(philo->args));
}

void	taking_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	write_philo_status(philo, "has taken a fork");
	if (philo->next == philo)
	{
		pthread_mutex_unlock(&philo->fork);
		ft_usleep(get_time_to_die(philo->args));
	}
	else
	{
		pthread_mutex_lock(&philo->next->fork);
		write_philo_status(philo, "has taken a fork");
	}
}

void	eating(t_philo *philo)
{
	if (philo->next == philo)
		taking_forks_philo_alone(philo);
	else if (!is_dead(philo))
	{
		taking_forks(philo);
		write_philo_status(philo, "is eating");
		pthread_mutex_lock(&philo->m_first_time);
		philo->first_time = get_current_time(0);
		pthread_mutex_unlock(&philo->m_first_time);
		ft_usleep(get_time_to_eat(philo->args));
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		pthread_mutex_lock(&philo->m_nb_eat);
		philo->curr_nb_eat++;
		pthread_mutex_unlock(&philo->m_nb_eat);
	}
}
