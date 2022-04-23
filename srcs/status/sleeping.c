/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:14:33 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/18 17:17:07 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeping(t_philo *philo)
{
	int	sleep_time;
	int	i;

	i = 0;
	pthread_mutex_lock(&philo->args.m_time_sleep);
	sleep_time = philo->args.time_to_sleep;
	pthread_mutex_unlock(&philo->args.m_time_sleep);
	write_philo_status(philo, "is sleeping");
	while (sleep_time - 10 * i > 0)
	{
		usleep(10);
		//check death
		i++;
	}
	usleep(sleep_time % 10);
}