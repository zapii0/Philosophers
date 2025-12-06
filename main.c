/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzapora <mzapora@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 23:41:27 by mzapora           #+#    #+#             */
/*   Updated: 2025/12/06 02:28:10 by mzapora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;
	
	if (ac < 5 || ac > 6)
		return (write(2, "Invalid input :(", 16), 1);
	data = parser(ac, av), data;
	if (!data)
		return (write(2, "Invalid input :(", 16), 1);
	return (0);	
}
