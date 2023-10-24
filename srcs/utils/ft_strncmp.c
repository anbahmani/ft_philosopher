/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:55:00 by abahmani          #+#    #+#             */
/*   Updated: 2022/04/18 15:56:20 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	i = 0;
	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	while (tmp_s1[i] && tmp_s2[i] && tmp_s1[i] == tmp_s2[i] && i < n)
	{
		i++;
	}
	if (i >= n)
		return (0);
	return (tmp_s1[i] - tmp_s2[i]);
}
