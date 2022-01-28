/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:47:53 by msierra-          #+#    #+#             */
/*   Updated: 2022/01/28 18:29:46 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

/*
	TODO: 	Corregir mensajes despues de muerto | Cortar programa cuando eso ?Con un mutex?
			Añadir los tenedores de forma que puedas coger el segundo tenedor!!!			
*/

int main(int argc, char **argv)
{
	t_philo			*philo;
	static t_state	state;
	int				i;

	i = 0;
	getvalues(argc, argv, &state); //TODO: errores de valores negativos
	philo = (t_philo *) malloc(state.numphilo * sizeof(t_philo));
	philo_init(&state, philo);
	mutex_init(&state, philo);
	thread_init(&state, philo);
	cleanall(philo, state.numphilo, 0); 
    return (0);
}
