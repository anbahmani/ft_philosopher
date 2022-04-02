/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 00:32:12 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/02 15:18:56 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	check_args_number(int ac)
{
	if (ac == 5 || ac == 6)
		return (true);
	printf_syntax_error();
	return (false);
}

static bool	check_args_value(char *nb, int index)
{
	if (index == 1 && ft_atoi(nb) > 200)
	{
		print_error("Incorrect number of philosophers {0-200}.");
		return (false);
	}
	else if (index <= 4 && ft_atoi(nb) < 60)
	{
		print_error("Incorrect time {+60}.");
		return (false);
	}
	return (true);
}

static bool	check_is_args_number(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_number(av[i]))
		{
			printf_syntax_error();
			return (false);
		}
		if (!check_args_value(av[i], i))
			return (false);
		i++;
	}
	return (true);
}

bool	check_args(int ac, char **av)
{
	if (!check_args_number(ac) || !check_is_args_number(ac, av))
		return (false);
	return (true);
}
