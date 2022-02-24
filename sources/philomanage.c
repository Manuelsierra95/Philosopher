/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philomanage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:47:32 by msierra-          #+#    #+#             */
/*   Updated: 2022/02/24 17:54:53 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

void	fork_init(t_state *state)
{
	int	i;

	i = 0;
	state->fork = malloc(state->numph);
	while (i < state->numph)
	{
		state->fork[i] = 0;
		i++;
	}
}

void	philo_init(t_state *state, t_philo *philo)
{
	int	i;

	i = 0;
	while (i <= state->numph)
	{
		philo[i].id = i;
		philo[i].state = state;
		philo[i].time = 0;
		i++;
	}
}

void	mutex_init(t_state *state)
{
	int	i;
	int	n;

	i = 0;
	n = state->numph;
	state->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (n + 1));
	while (i <= n)
	{
		if (0 != pthread_mutex_init(&(state->mutex)[i], NULL))
			state->need_clean = 1;
		i++;
	}
}

void	thread_init(t_state *state, t_philo *philo)
{
	int	i;
	int	n;

	n = state->numph;
	i = 0;
	state->thread = malloc(sizeof(int) * (n + 1));
	while (i < n)
	{
		if (0 != pthread_create(&(state->thread)[i], NULL, &phstate, &philo[i]))
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

void	join_init(t_state *state, t_philo *philo)
{
	int	i;

	i = 0;
	while (i <= state->numph)
	{
		if (0 != pthread_join(state->thread[i], NULL))
			cleanall(philo, 4);
		pthread_detach(state->thread[i]);
		i++;
	}
}
