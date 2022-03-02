/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:47:53 by msierra-          #+#    #+#             */
/*   Updated: 2022/03/01 18:25:29 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

void	leak(void)
{
	system("leaks philo");
}

int	main(int argc, char **argv)
{
	t_philo			*philo;
	static t_state	state;
	int				i;

	i = 0;
	atexit(leak);
	errorcontrol(argc, argv);
	getvalues(argc, argv, &state);
	philo = (t_philo *) malloc(state.numph * (sizeof(t_philo) + 1));
	fork_init(&state);
	philo_init(&state, philo);
	mutex_init(&state);
	thread_init(&state, philo);
	cleanall(philo, 0);
	return (0);
}
