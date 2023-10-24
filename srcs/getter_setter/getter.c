/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 06:07:15 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/24 15:56:19 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time_to_die(t_args *args)
{
	int	time_die;

	pthread_mutex_lock(&args->m_time_to_die);
	time_die = args->time_to_die;
	pthread_mutex_unlock(&args->m_time_to_die);
	return (time_die);
}

int	get_time_to_eat(t_args *args)
{
	int	time_eat;

	pthread_mutex_lock(&args->m_time_to_eat);
	time_eat = args->time_to_eat;
	pthread_mutex_unlock(&args->m_time_to_eat);
	return (time_eat);
}

int	get_time_to_sleep(t_args *args)
{
	int	time_sleep;

	pthread_mutex_lock(&args->m_time_to_sleep);
	time_sleep = args->time_to_sleep;
	pthread_mutex_unlock(&args->m_time_to_sleep);
	return (time_sleep);
}

int	get_nb_eat(t_args *args)
{
	int	nb_eat;

	pthread_mutex_lock(&args->m_nb_eat);
	nb_eat = args->nb_eat;
	pthread_mutex_unlock(&args->m_nb_eat);
	return (nb_eat);
}

long	get_philo_first_time(t_philo *philo)
{
	long	r_time;

	pthread_mutex_lock(&philo->m_first_time);
	r_time = philo->first_time;
	pthread_mutex_unlock(&philo->m_first_time);
	return (r_time);
}
