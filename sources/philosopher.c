/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:47:53 by msierra-          #+#    #+#             */
/*   Updated: 2022/02/01 16:00:22 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

/*
	TODO:
*/

void	leak(void)
{
	system("leaks philosopher");
}

int main(int argc, char **argv)
{
	t_philo			*philo;
	static t_state	state;
	int				i;

	// atexit(leak);
	i = 0;
	getvalues(argc, argv, &state);
	philo = (t_philo *) malloc(state.numphilo * (sizeof(t_philo) + 1));
	fork_init(&state);
	philo_init(&state, philo);
	mutex_init(&state, philo);
	thread_init(&state, philo);
	cleanall(philo, 0);
    return (0);
}
