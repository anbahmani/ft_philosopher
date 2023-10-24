/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 10:00:50 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/24 15:19:39 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_nb_philo(t_args *args)
{
	int	nb_philo;

	pthread_mutex_lock(&args->m_nb_philo);
	nb_philo = args->nb_philo;
	pthread_mutex_lock(&args->m_nb_philo);
	return (nb_philo);
}
