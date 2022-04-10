/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 15:13:09 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/10 03:24:04 by abahmani         ###   ########.fr       */
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
	args->start_time = get_current_time();
}

static void	init_philo(t_philo *p, int index, t_args args)
{
	p = malloc(sizeof(t_philo));
	if (!p)
	{
		p = NULL;
		return ;
	}
	p->index = index;
	p->alive = true;
	p->args = args;
	p->first_time = 0;
	p->last_time = 0;
}

void	init_all_philo(t_struct *s)
{
	int	index;
	t_philo *current_philo;
	
	init_philo(s->first_philo, 1, s->args);
	if (!s->first_philo)
		return (free_struct(&s->args, s->first_philo));
	current_philo = s->first_philo;
	index = 1;
	while (++index <= s->args.nb_philo)
	{
		init_philo(current_philo->next, index, s->args);
		if (!current_philo->next)
			return (free_struct(&s->args, s->first_philo));
		current_philo = current_philo->next;
	}
}
