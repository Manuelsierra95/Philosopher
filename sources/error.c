/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:35:29 by msierra-          #+#    #+#             */
/*   Updated: 2022/01/22 18:02:27 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

void	errormsg(int flag)
{
		
}

void	cleanthread(t_state *state, int num)
{
	num--;
	while (num != 0)
	{
		pthread_detach(&state->thread[num]);
		num--;
	}
}

void	cleanmutex(t_state *state, int num)
{
	num--;
	while (num != 0)
	{
		pthread_mutex_destroy(&state->mutex[num]);
		free(state->mutex);
		num--;
	}
}

void	cleanphilo(t_philo *philo, int num)
{
	num--;
	while (num != 0)
	{
		free(&philo[num]);
		num--;
	}
}

void	clean(int flag, int num, t_philo *philo)
{
	if (flag == 1) //clean mutex
	{
		cleanmutex(philo->state, num);
	}
	if (flag == 2) //clean thread
	{
		cleanthread(philo->state, num);
	}
	if (flag == 3)
	{
		cleanmutex(philo->state, num);	
		cleanthread(philo->state, num);
	}
	if (flag == 4) //clean philo
	{
		cleanphilo(philo, num);		
	}
	exit(0);
}
