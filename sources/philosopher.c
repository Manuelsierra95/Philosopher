/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:47:53 by msierra-          #+#    #+#             */
/*   Updated: 2022/02/26 19:08:47 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

/*
	Arreglar que no mueren con 310 200 100, cuando si deberia morir algun philo *Hay que sumar los valores de la comida anterior 
																				para checkear si debe de morir
*/
int	main(int argc, char **argv)
{
	t_philo			*philo;
	static t_state	state;
	int				i;

	i = 0;
	errorcontrol(argc, argv);
	getvalues(argc, argv, &state);
	philo = (t_philo *) malloc(state.numph * (sizeof(t_philo) + 1));
	fork_init(&state);
	philo_init(&state, philo);
	mutex_init(&state);
	thread_init(&state, philo);
	write(1, "El programa se ha cerrado bien\n", 31);
	cleanall(philo, 0);
	return (0);
}
