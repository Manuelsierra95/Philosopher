/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philomanage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:47:32 by msierra-          #+#    #+#             */
/*   Updated: 2022/01/25 17:40:16 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

void	philo_init(t_state *state, t_philo *philo)
{
	int	i;

	printf("numphilo: %d\n", state->numphilo);
	i = 0;
	while(i < state->numphilo)
	{
		philo->id = i;
		philo->state = state;
		philo->time = gettime();
		printf("Id: %d\n", philo->id);

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
			cleanmutex(philo, i);
			clean(philo, i);
		}
		printf("Mutex: %p\n", state->mutex + i);
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
		printf("-------I = %d\n", i);
		a = pthread_create(&(state->thread)[i], NULL, &philostate, &philo[i]);
		printf("*******A = %d\n", a);

		if (0 != a)
		{
			cleanthread(philo, i);
			clean(philo, i);
		}
		printf("Threads: %p\n", state->thread + i);
		i++;
	}
}
