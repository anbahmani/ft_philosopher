/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 11:34:24 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/24 15:58:22 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_philo_status(t_philo *philo, char *status)
{
	unsigned long	time;

	if (!is_dead(philo) && !check_nb_eat(philo, get_nb_eat(philo->args)))
	{
		pthread_mutex_lock(&philo->args->m_start_time);
		time = get_current_time(philo->args->start_time);
		pthread_mutex_unlock(&philo->args->m_start_time);
		pthread_mutex_lock(&philo->args->m_write_log);
		printf("%lu %i %s\n", time, philo->index, status);
		pthread_mutex_unlock(&philo->args->m_write_log);
	}
}
