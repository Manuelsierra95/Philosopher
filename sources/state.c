/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:43:06 by msierra-          #+#    #+#             */
/*   Updated: 2022/01/20 16:01:01 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

thinking()
{
	write(1, "Thinking\n", 7);
	
}

eating()
{
	write(1, "Eating\n", 7);
	
}

sleeping()
{
	write(1, "Sleeping\n", 7);
	
}

died()
{
	write(1, "Died\n", 7);
	
}

void	*philostate(void *arg)
{
	t_philo	*philo;
	int		i;
	
	i = 0;
	philo = (t_philo *) arg;
	while (i < philo->state->numphilo)
	{
		thinking();
		if (philo[i])
		i++;
	}
	printf("philo is thinking\n");
	
	pthread_mutex_lock(philo);
	pthread_mutex_unlock();
	
}
