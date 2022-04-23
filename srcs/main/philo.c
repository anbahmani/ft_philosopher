/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:04:23 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/23 04:22:30 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	continue_checking(t_struct *s)
{
	pthread_mutex_lock(&s->args.m_optional_arg);
	if (s->args.optional_arg)
	{
		pthread_mutex_unlock(&s->args.m_optional_arg);
		check_nb_eat_and_death(s);
	}
	else 
	{
		pthread_mutex_unlock(&s->args.m_optional_arg);
		check_death(s);
	}
}

void	start_activities(t_struct *s)
{
	int	i;
	t_philo	*curr;

	i = 1;
	curr = s->first_philo;
	while (i <= s->args.nb_philo)
	{
		if (pthread_create(&curr->th_philo, NULL, activities_loop, curr) != 0)
		{
			join_threads(curr, i - 1);
			free_struct(&s->args, s->first_philo);
			print_error("Issue during the threads creation.");
			return ;
		}
		curr = curr->next;
		i++;
	}
	continue_checking(s);
}

void	*activities_loop(t_philo *philo)
{
	int	tmp_time;
	
	if (philo->index % 2 == 0)
	{
		pthread_mutex_lock(&philo->args.m_time_eat);
		tmp_time = philo->args.time_to_eat;
		pthread_mutex_unlock(&philo->args.m_time_eat);
		usleep(tmp_time / 10);
	}
	while (true)
	{
		philo->first_time = get_current_time();
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (philo);
}

int	main(int ac, char **av)
{
	t_args	*args;
	t_struct	s;

	if (!check_args(ac, av))
		return (1);
	args = init_args(ac, av);
	s.args = *args;
	init_all_philo(&s);
	init_args_mutex(args);
	if (!s.first_philo)
	{
		print_error("Issue during the philo allocation.");
		return (1);
	}
	start_activities(&s);
}
