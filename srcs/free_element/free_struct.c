/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 13:06:38 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/09 18:53:18 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_struct(t_args *args, t_philo *philo)
{
	free(args->start_time);
	if (args != NULL)
		free(args);
	if (philo != NULL)
		free(philo);
}
 