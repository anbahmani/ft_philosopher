/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:06:44 by abahmani          #+#    #+#             */
/*   Updated: 2022/03/31 14:10:40 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(char *msg)
{
	printf("Error !\n%s\n", msg);
}

void	printf_syntax_error(void)
{
	print_error("");
	printf("Bad arguments syntax.\n");
	printf("./philo [number_of_philosophers] [time_to_die] [time_to_eat] ");
	printf("[time_to_sleep] ");
	printf("[number_of_times_each_philosopher_must_eat] (optional)");
}