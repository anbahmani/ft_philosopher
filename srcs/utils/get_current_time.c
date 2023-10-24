/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 03:23:17 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/24 15:18:47 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time(long time)
{
	struct timeval	tv;
	long			res;

	if (gettimeofday(&tv, NULL) == -1)
	{
		print_error("Bad time allocation.");
		return (0);
	}
	res = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (res - time);
}
