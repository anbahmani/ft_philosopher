/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:25:16 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/23 22:26:53 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long ms)
{
	long int	start_time;
	long int	current_time;

	start_time = get_current_time(0);
	current_time = get_current_time(0);
	while ((current_time - start_time) <= ms)
	{
		usleep(100);
		current_time = get_current_time(0);
	}
}
