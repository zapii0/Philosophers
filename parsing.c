/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 01:01:25 by mzapora           #+#    #+#             */
/*   Updated: 2025/12/06 02:38:26 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*parser(int ac, char **av, t_data *data)
{
	int	i;
	
	i = 0;
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->num_philo = ft_atoi(av[1]);
	if (data->num_philo > 0)
		data->philo = malloc(sizeof(t_philo) * data->num_philo);
	if (!data->philo)
		return (NULL);
	while (i < data->num_philo)
	{
		data->philo[i].time_to_die = ft_atoi(av[2]);
		data->philo[i].time_to_eat = ft_atoi(av[3]);
		data->philo[i].time_to_sleep = ft_atoi(av[4]);
		if (ac == 6)
			data->philo[i].num_of_eat = ft_atoi(av[5]);
		i++;
	}
	i = mutex_init(data);
	if (i == -1)
		return (NULL);
	return (data);
}

int	mutex_init(t_data *data)
{
	data->forks = malloc(sizeof(t_fork) * data->num_philo);
	if (!data->forks)
		return (-1);
	
}