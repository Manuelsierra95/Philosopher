/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:47:53 by msierra-          #+#    #+#             */
/*   Updated: 2022/01/22 15:12:20 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

/*
    
*/

initmutex(t_state *state) //Se crea un mutex por cada philo, en la tabla de recurso compartido
{
	int	i;

	i = 0;
	while (i < state->numphilo)
	{
		pthread_mutex_init(state->mutex, NULL);	
		i++;
	}
}

joinpthreads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->state->numphilo)
	{
		pthread_join(&philo[i], NULL);	
	}
}

int main(int argc, char **argv)
{
	t_philo			*philo;
	static t_state	state;
	int					i;

	i = 0;
	getvalues(argc, argv, &state);
	initmutex(&state);
    ft_pthreadcreate(argc, argv, philo);
	// joinpthreads(philo, numphilo);
	ft_managepthreads(philo);

    return (0);
}
