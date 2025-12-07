/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 23:45:34 by mzapora           #+#    #+#             */
/*   Updated: 2025/12/07 00:53:11 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_fork
{
	int	fork_id;
	pthread_mutex_t fork_mutex;
} t_fork;

typedef struct s_philo
{
	pthread_t	philosopher;
	int			num_of_eat;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	t_fork		*left_fork;
	t_fork		*right_fork;
}	t_philo;

typedef struct s_data
{
	t_philo	*philo;
	int		num_philo;
	t_fork	*forks;
	
} t_data;
//	parsing.c
t_data	*parser(int ac, char **av, t_data *data);
int		mutex_pthread_init(t_data *data);
void	*routine(void);
void	fork_set(t_data *data);

//	utils.c
int	ft_atoi(const char *nptr);

#endif