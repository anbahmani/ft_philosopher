/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 11:34:24 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/10 13:09:47 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_philo_status(t_philo *philo, char *status)
{
	unsigned long	time;
	
	pthread_mutex_lock(&philo->args.m_write_log);
	pthread_mutex_lock(&philo->args.m_start_time);
	time = get_current_time() - philo->args.start_time;
	pthread_mutex_unlock(&philo->args.m_start_time);
	printf("%lu %i %s", time, philo->index, status);
	pthread_mutex_unlock(&philo->args.m_write_log);	
}