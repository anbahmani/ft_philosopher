/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 13:06:38 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/03 15:30:57 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_struct(t_args *args, t_time *time, t_philo *philo)
{
	if (time != NULL)
		free(time);
	if (args != NULL)
		free(args);
	if (philo != NULL)
		free(philo);
}
 