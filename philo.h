/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 23:45:34 by mzapora           #+#    #+#             */
/*   Updated: 2025/12/06 00:12:53 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

typedef struct s_fork
{
	int	fork_id;
	pthread_mutex_t fork_mutex;
} t_fork;

typedef struct s_philo
{
	int			num_of_eat;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	t_fork		*left_fork;
	t_fork		*right_fork;
}	t_philo;

typedef struct t_data
{
	t_philo	*philo;
	int		num_philo
	
}

# endif