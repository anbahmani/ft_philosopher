/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:14:37 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/10 16:12:42 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	taking_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	write_philo_status(philo, "has taken  fork");
	if (philo->next != philo)
	{
		pthread_mutex_lock(&philo->next->fork);
		write_philo_status(philo, "has taken  fork"); 
	}
}

void	eat(t_philo *philo)
{
	int	i;
	int	eat_time;

	taking_forks(philo);
	pthread_mutex_lock(&philo->args.m_time_eat);
	eat_time = philo->args.time_to_eat;
	pthread_mutex_unlock(&philo->args.m_time_eat);
	i = 0;
	while (eat_time - 10 * i > 0)
	{
		usleep(10);
		i++;
	}
	usleep(eat_time % 10);
	philo->first_time = get_current_time();
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
	pthread_mutex_lock(&philo->args.m_optional_arg);
	if (philo->args.optional_arg)
		philo->curr_nb_eat++;
	pthread_mutex_unlock(&philo->args.m_optional_arg);
}
