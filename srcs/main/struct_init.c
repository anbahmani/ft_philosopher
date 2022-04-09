/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 15:13:09 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/09 18:55:03 by abahmani         ###   ########.fr       */
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
	args->end = false;
}

void	init_time(unsigned long *time)
{
	struct timeval	tv;

	time = malloc(sizeof(unsigned long));
	if (time == NULL)
	{
		return (print_error("Bad time allocation."));
	}
	if (gettimeofday(&tv, NULL) == -1)
	{
		free(time);
		return (print_error("Bad time allocation."));
	}
	*time = (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	init_philo_struct(t_args *args)
{
	int	index = 1;

	while (index <= args->nb_philo)
	{
		
	}
}