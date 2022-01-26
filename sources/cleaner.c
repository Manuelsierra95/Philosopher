/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:57:30 by msierra-          #+#    #+#             */
/*   Updated: 2022/01/26 19:49:10 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

void	cleanthread(t_philo *philo, int num)
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
	errormsg(1);
}

void	cleanmutex(t_philo *philo, int num)
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
	errormsg(2);
}

void	cleanall(t_philo *philo, int num)
{
	usleep(1000);
	cleanmutex(philo, num);
	cleanthread(philo, num);
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
