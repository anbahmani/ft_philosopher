/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:04:23 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/25 12:56:51 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_args(int ac, char **av, t_args *args)
{
	args = malloc(sizeof(t_args));
	if (args == NULL)
	{
		print_error("L'allocation des arguments ne s'est pas faites correctement.");
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

int	main(int ac, char **av)
{
	t_args	args;

	if (ac < 5 || ac > 6)
	{
		print_error("Bad number of arguments.");
		return (1);
	}
	
}
