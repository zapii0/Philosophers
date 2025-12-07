/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 01:01:25 by mzapora           #+#    #+#             */
/*   Updated: 2025/12/07 01:18:46 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void);

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
	i = mutex_pthread_init(data);
	if (i == -1)
		return (NULL);
	return (data);
}

int	mutex_pthread_init(t_data *data)
{
	int i;

	i = 0;
	data->forks = malloc(sizeof(t_fork) * data->num_philo);
	if (!data->forks)
		return (-1);
	while (i < data->num_philo)
	{
		data->forks[i].fork_id = i + 1;
		pthread_mutex_init(&data->forks[i].fork_mutex, NULL);
		pthread_create(&data->philo[i].philosopher, NULL, (void *)routine, NULL);
		i++;
	}
	i = 0;
	while (i <data->num_philo)
	{
		pthread_join(data->philo[i].philosopher, NULL);
		i++;
	}
	fork_set(data);
	return (0);
}

void	fork_set(t_data *data)
{
	int i;

	i = 1;
	data->philo[0].right_fork = &data->forks[data->num_philo - 1];
	data->philo[0].left_fork = &data->forks[0];
	while (i < data->num_philo)
	{
		data->philo[i].left_fork = &data->forks[i];
		data->philo[i].right_fork = &data->forks[i - 1];
		i++;
	}
	return ;
}

void	*routine(void)
{
	printf("thread sie tworzy\n");
	return (NULL);
}
