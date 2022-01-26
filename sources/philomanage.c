/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philomanage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:47:32 by msierra-          #+#    #+#             */
/*   Updated: 2022/01/26 19:46:20 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

void	philo_init(t_state *state, t_philo *philo)
{
	int	i;

	i = 0;
	while(i < state->numphilo)
	{
		philo[i].id = i;
		philo[i].state = state;
		philo[i].time = gettime();
		i++;
	}
}

void	mutex_init(t_state *state, t_philo *philo)
{
	int	i;

	i = 0;
	state->mutex = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
	while (i < philo->state->numphilo)
	{
		if (0 != pthread_mutex_init(&(state->mutex)[i], NULL))
		{
			// cleanmutex(philo, 2);
			// clean(philo);
		}
		i++;
	}
}

void	join_init(t_state *state)
{
	int	i;

	i = 0;
	while(i < state->numphilo)
	{
		pthread_join(state->thread[i], NULL);
		i++;
	}
}

void	thread_init(t_state *state, t_philo *philo) //va ha crear los hilos
{
	int	i;
	int a;

	i = 0;
	state->thread = (pthread_t *) malloc(sizeof(pthread_t));
	// philo->time = state->t_die;
	while (i < philo->state->numphilo)
	{
		a = pthread_create(&(state->thread)[i], NULL, &philostate, &philo[i]);
		if (0 != a)
		{
			// cleanthread(philo, 1);
			// clean(philo);
		}
		i++;
	}
	join_init(state);
}
