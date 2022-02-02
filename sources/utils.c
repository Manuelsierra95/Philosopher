/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:44:47 by msierra-          #+#    #+#             */
/*   Updated: 2022/02/01 17:27:29 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

int	minthread(int num1, int num2)
{
	if(num1 < num2)
		return (num1);
	else
		return (num2);
}

int	maxthread(int num1, int num2)
{
	if(num1 > num2)
		return (num1);
	else
		return (num2);
}

size_t	gettime(void)
{
	struct timeval	t_val;

	gettimeofday(&t_val, NULL);
	return ((t_val.tv_sec * 1000) + (t_val.tv_usec / 1000));
}

int	check_dead(t_state *state, t_philo *philo, int id)
{
	int	i;

	pthread_mutex_lock(&state->mutex[state->numphilo]);
	i = state->is_dead;
	if (i == 1)
	{
		died(id);
		cleanall(philo, 0);
	}
	pthread_mutex_unlock(&state->mutex[state->numphilo]);
	return (i);
}

void	*set_dead(void *arg)
{
	int	i;
	t_state	*table;
	t_philo	*philo;

	philo = arg;
	table = philo->state;
	while (1)
	{
		i = 0;
		while(i < table->numphilo)
		{
			if (philo[i].time - gettime() < (unsigned long int) table->t_die)
			{
				table->is_dead = 1;
				break ;
			}
			i++;
		}
		if (table->is_dead == 1)
			break ;
	}
	return (NULL);
}
