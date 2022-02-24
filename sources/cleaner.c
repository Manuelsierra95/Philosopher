/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:57:30 by msierra-          #+#    #+#             */
/*   Updated: 2022/02/21 16:46:50 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

void	cleanthread(t_philo *philo, int print)
{
	int		i;
	t_state	*clean;

	clean = philo->state;
	i = 0;
	while (i <= clean->numph)
	{
		pthread_detach(clean->thread[i]);
		i++;
	}
	if (print == 1)
		errormsg(1);
}

void	cleanmutex(t_philo *philo, int print)
{
	int		i;
	t_state	*clean;

	clean = philo->state;
	i = 0;
	while (i <= clean->numph)
	{
		pthread_mutex_destroy(&clean->mutex[i]);
		i++;
	}
	if (print == 1)
		errormsg(2);
}

void	cleanall(t_philo *philo, int print)
{
	if (print == 4)
		errormsg(4);
	cleanmutex(philo, print);
	cleanthread(philo, print);
	free(philo->state->fork);
	exit(0);
}

void	clean(t_philo *philo)
{
	free(philo);
	exit(0);
}
