/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:43:06 by msierra-          #+#    #+#             */
/*   Updated: 2022/01/22 17:46:37 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

eating(t_philo *philo)
{
	int	m1;
	int m2;

	printf("Philo id: %d is Eating\n", philo->id);
	m1 = minthread();
	m2 = maxthread();
	pthread_mutex_lock(&philo[m1]);
	printf("Philo id: %d is taking a fork\n", philo->id);
	usleep(philo->state->t_eat);
	pthread_mutex_unlock(&philo[m2]);
	printf("Philo id: %d left the fork\n", philo->id);
	philo->time = philo->state->t_die;
}

sleeping(t_philo *philo)
{
	printf("Philo id: %d is Sleeping\n", philo->id);
	usleep(philo->state->t_sleep);
	philo->time = philo->time - philo->state->t_sleep;
}

died(t_philo *philo)
{
	printf("Philo id: %d is Dead\n", philo->id);
}

thinking(t_philo *philo)
{
	int	gettime;
	
	printf("Philo id: %d is Thinking\n", philo->id);
	gettime = get_time();
	philo->time = philo->time - gettime;
	if (philo->time <= 0)
	{
		died(philo);
		clean();
	}
}

void	*philostate(void *arg)
{
	t_philo	*philo;
	int	m_eat;
	
	m_eat = philo->state->m_eat;
	philo = (t_philo *) arg;
	while (1)
	{
		if(m_eat != 0)
			clean(3, philo->state->numphilo, philo); //paramos la ejecucion
		thinking(philo);
		eating(philo);
		sleeping(philo);
		m_eat--;
	}
}
