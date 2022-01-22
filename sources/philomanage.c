/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philomanage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:47:32 by msierra-          #+#    #+#             */
/*   Updated: 2022/01/22 17:51:41 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

void	philo_init(t_state *state, t_philo *philo) //va ha crear los hilos
{
	int	i;

	i = 0;
	state->thread = (pthread_t *) malloc(sizeof(pthread_t));
	state->mutex = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
	philo = (t_philo *) malloc(philo->state->numphilo * sizeof(t_philo));
	philo->time = state->t_die;
	while (i < philo->state->numphilo)
	{
		philo[i] = philo_create(i, state);
		if (0 != pthread_create(&(state->thread)[i], NULL, &philostate, &philo[i]))
		{
			clean(1); //meter exit | meter errormsg dentro de clean();
		}
		if (0 != pthread_mutex_init(&(state->mutex)[i], NULL))
		{
			clean(3, i, philo);
			//error
		}
		i++;
	}
}

t_philo	philo_create(int i, t_state *state) //va a darle los valores a cada philo
{	
	t_philo	result;

	result.id = i;
	result.l_eat = state->m_eat; //Veces que le quedan por comer, igualado a las que debe comer
	result.time = gettime(); //hacer funcion;
	result.state = state; //Dandole los valores de la tabla (el estado)
	return (result);
}
