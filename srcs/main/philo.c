/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:04:23 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/10 11:28:14 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	start_activities(t_struct *s)
{
	int	i;
	t_philo	*curr;

	i = 1;
	curr = s->first_philo;
	while (i <= s->args.nb_philo)
	{
		if (pthread_create(curr->th_philo, NULL, activities_loop, curr) != 0)
		{
			join_threads(curr, i - 1);
			free_struct(&s->args, &s->first_philo);
			print_error("Issue during the threads creation.");
			return ;
		}
		curr = curr->next;
		i++;
	}
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
		eat(philo);
		sleep(philo);
		think(philo);
	}
}

int	main(int ac, char **av)
{
	t_args	args;
	t_struct	s;

	if (!check_args(ac, av))
		return (1);
	init_args(ac, av, &args);
	if ((args.optional_arg && args.nb_eat == 0) || args.nb_philo == 0)
		return (0);
	s.args = args;
	init_philo(&s);
	if (!s.first_philo)
	{
		print_error("Issue during the philo allocation.");
		return (1);
	}
	start_activities(&s);
}
