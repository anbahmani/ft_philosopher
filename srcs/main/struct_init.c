/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 15:13:09 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/03 15:30:57 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_args(int ac, char **av, t_args *args)
{
	args = malloc(sizeof(t_args));
	if (args == NULL)
	{
		return (print_error("Bad arguments allocation."));
	}
	args->nb_philo = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		args->optional_arg = true;
		args->nb_eat = ft_atoi(av[5]);
	}
}

void	init_time(t_time *time)
{
	struct timeval	tv;

	time = malloc(sizeof(t_time));
	if (time == NULL)
	{
		return (print_error("Bad time allocation."));
	}
	memset(time, 0, sizeof(t_time));
	if (gettimeofday(&tv, NULL) == -1)
	{
		free(time);
		return (print_error("Bad time allocation."));
	}
	time->start = (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
