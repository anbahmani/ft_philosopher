/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 00:32:12 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/09 17:54:21 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* 
	Paramaters	:
		- int ac => the number of arguments in the main function
	Description :
		- Checks the number of arguments in the main function (has to be 5 or 
			6)
		- Calls the function printf_syntax_error() if the number of arguments is
			incorrect
	Returns	:
		- true if the number of arguments in the main function is 5 or 6
		- false if not
*/
static bool	check_args_number(int ac)
{
	if (ac == 5 || ac == 6)
		return (true);
	printf_syntax_error();
	return (false);
}

static bool	check_overflow(char *s)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (!ft_strncmp("-2147483648", s, ft_strlen(s)))
		return (true);
	if (s[0] == '-')
	{
		i++;
	}
	while (s[i])
	{
		nb = nb * 10 + (s[i] - '0');
		if (nb < 0)
			return (false);
		i++;
	}
	return (true);
}

/* 
	Paramaters	:
		- char *nb	=> the value of the argument which has to be checked
		- int index	=> the position of the argument in argv (from main function)
	Description :
		- Checks the value of the argument "number of philosophers" (has to
			be between 0 and 200)
		- Checks the values of the time's arguments (have to be between > 60)
	Returns	:
		- true if the argument is correct
		- false if not
*/
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
	else if (index == 5 && ft_atoi(nb) >= 0)
	{
		print_error("Incorrect value of number of eat {+0}");
		return (false);
	}
	return (true);
}

/* 
	Paramaters	:
		- int ac	=> the number of arguments in the main function
		- char **av	=> arguments from the main function
	Description :
		- Checks the arguments from main function are composed by digits char
		- Calls the function check_args_value(char *nb, int index) for each
			arguments from main function
	Returns	:
		- true if all arguments are corrects
		- false if not
*/
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
		if (!check_overflow(av[i]))
		{
			print_error("Int overflow on a argument.");
			return (false);
		}
		if (!check_args_value(av[i], i))
			return (false);
		i++;
	}
	return (true);
}

/* 
	Paramaters	:
		- int ac	=> the number of arguments in the main function
		- char **av	=> arguments from the main function
	Description :
		- Calls the functions check_is_args_number(int ac, char **av) and 
			check_args_number(int ac)
	Returns	:
		- true if both called function return true
		- false if not
*/
bool	check_args(int ac, char **av)
{
	if (!check_args_number(ac) || !check_is_args_number(ac, av))
		return (false);
	return (true);
}
