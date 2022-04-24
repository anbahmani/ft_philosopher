/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 07:28:27 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/24 07:32:27 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_philo_first_time(t_philo *philo, long new_time)
{
	pthread_mutex_lock(&philo->m_first_time);
	philo->first_time = new_time;
	pthread_mutex_unlock(&philo->m_first_time);
}
