/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 00:56:47 by mzapora           #+#    #+#             */
/*   Updated: 2025/12/06 01:08:59 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	if (c <= 57 && c >= 48)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;	
	int	num;
	int	flag;
	int	m;

	flag = 0;
	num = 0;
	i = 0;
	m = 1;
	while ((nptr[i] < 14 && nptr[i] > 8) || nptr[i] == ' ')
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			m = m * -1;
		i++;
		flag++;
	}
	while (ft_isdigit(nptr[i]) == 1 && nptr[i])
		num = num * 10 + nptr[i++] - 48;
	if (flag > 1)
		return (0);
	return (num * m);
}
