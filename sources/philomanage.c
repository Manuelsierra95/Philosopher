/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philomanage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:47:32 by msierra-          #+#    #+#             */
/*   Updated: 2022/02/01 18:40:48 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

void	fork_init(t_state *state)
{
	int	i;

	i = 0;
	state->fork = malloc(state->numphilo);
	while(i < state->numphilo)
	{
		state->fork[i] = 0;
		i++;
	}
}

void	philo_init(t_state *state, t_philo *philo)
{
	int	i;

	i = 0;
	while(i <= state->numphilo)
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
	state->mutex = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * state->numphilo + 1);
	while (i <= philo->state->numphilo)
	{
		if (0 != pthread_mutex_init(&(state->mutex)[i], NULL))
			state->need_clean = 1;
		i++;
	}
}

void	join_init(t_state *state, t_philo *philo)
{
	int	i;

	i = 0;
	while(i <= state->numphilo)
	{
		if(0 != pthread_join(state->thread[i], NULL))
			cleanall(philo, 4);
		pthread_detach(state->thread[i]);
		i++;
	}
}

void	thread_init(t_state *state, t_philo *philo) //va ha crear los hilos
{
	int	i;

	i = 0;
	state->thread = (pthread_t *) malloc(sizeof(pthread_t) * state->numphilo + 1);
	while (i < philo->state->numphilo)
	{
		if (0 != pthread_create(&(state->thread)[i], NULL, &philostate, &philo[i]))
		{
			if (state->need_clean == 1)
				cleanmutex(philo, 1);
			cleanthread(philo, 1);
			clean(philo);
		}
		i++;
	}
	pthread_create(&(state->thread)[i], NULL, &set_dead, philo);
	join_init(state, philo);
}
