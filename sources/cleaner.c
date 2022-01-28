/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:57:30 by msierra-          #+#    #+#             */
/*   Updated: 2022/01/28 18:12:42 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

void	cleanthread(t_philo *philo, int num, int print)
{
	int		n;
	t_state	*clean;

	clean = philo->state;
	n = num - 1;
	while (n >= 0)
	{
		pthread_detach(clean->thread[n]);
		n--;
	}
	if (print == 1)
		errormsg(1);
}

void	cleanmutex(t_philo *philo, int num, int print)
{
	int		n;
	t_state	*clean;
	
	clean = philo->state;
	n = num - 1;
	while (n >= 0)
	{
		pthread_mutex_destroy(&clean->mutex[n]);
		n--;
	}
	if (print == 1)
		errormsg(2);
}

void	cleanall(t_philo *philo, int num, int print)
{
	// usleep(1000);
	cleanmutex(philo, num, print);
	cleanthread(philo, num, print);
	clean(philo);
}

void	clean(t_philo *philo)
{
	free(philo);
	exit(0);
}

// void	clean(int flag, int num, t_philo *philo)
// {
// 	if (flag == 1) //clean mutex
// 	{
// 		cleanmutex(philo->state, num);
// 	}
// 	if (flag == 2) //clean thread
// 	{
// 		cleanthread(philo->state, num);
// 	}
// 	if (flag == 3)
// 	{
// 		cleanmutex(philo->state, num);	
// 		cleanthread(philo->state, num);
// 	}
// 	if (flag == 4) //clean philo
// 	{
// 		cleanphilo(philo, num);		
// 	}
// 	exit(0);
// }
