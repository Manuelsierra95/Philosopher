/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:47:53 by msierra-          #+#    #+#             */
/*   Updated: 2022/01/25 17:19:30 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

/*
    
*/

int main(int argc, char **argv)
{
	t_philo			*philo;
	static t_state	state;
	int					i;

	i = 0;
	getvalues(argc, argv, &state); //TODO: errores de valores negativos
	philo = (t_philo *) malloc(state.numphilo * sizeof(t_philo));
	philo_init(&state, philo);
	mutex_init(&state, philo);
	// int a = 0;
	// state.thread = (pthread_t *) malloc(sizeof(pthread_t));

	// while (a < 5)
	// {
	// 	if (0 != pthread_create(&state.thread[a], NULL, &philostate, &philo[a]))
	// 	{
	// 		cleanthread(philo, a);
	// 		clean(philo, a);
	// 	}
	// 	printf("Threads: %p\n", state.thread + a);
	// 	a++;
	// }
	thread_init(&state, philo);

    return (0);
}
