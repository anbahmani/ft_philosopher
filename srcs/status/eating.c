/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:14:37 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/24 10:55:00 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	write_philo_status(philo, "has taken a fork");
	if (philo->next == philo)
	{
		pthread_mutex_unlock(&philo->fork);
		ft_usleep(get_time_to_die(philo->args));
	}
	pthread_mutex_lock(&philo->next->fork);
	write_philo_status(philo, "has taken a fork");
}

void	eating(t_philo *philo)
{
	if (!is_dead(philo))
	{
		taking_forks(philo);
		write_philo_status(philo, "is eating");
		set_philo_first_time(philo, get_current_time(0));
		ft_usleep(get_time_to_eat(philo->args));
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		if (get_nb_eat(philo->args) != -1)
			philo->curr_nb_eat++;
	}
}
