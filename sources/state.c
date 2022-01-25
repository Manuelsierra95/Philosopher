/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:43:06 by msierra-          #+#    #+#             */
/*   Updated: 2022/01/25 17:40:33 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

void	died(t_philo *philo)
{
	printf("Philo id: %d is Dead\n", philo->id);
}

void	thinking(t_philo *philo)
{
	size_t	time;
	
	printf("Philo id: %d is Thinking\n", philo->id);
	time = gettime();
	printf("Time: %zu\n", time);
	printf("Time philo: %zu\n", philo->time);
	// exit(0);
	philo->time = time - philo->time;
	printf("---time philo: %zu\n", philo->time);
	if (philo->time < 0)
	{
		died(philo);
		cleanall(philo, philo->state->numphilo);
	}
}

void	eating(t_philo *philo)
{
	int		m1;
	int 	m2;
	t_state	*table;

	table = philo->state;
	m1 = minthread(philo->id, (philo->id + 1)%philo->state->numphilo); //solucionar
	m2 = maxthread(philo->id, (philo->id + 1)%philo->state->numphilo); //solucionar
	printf("Philo id: %d is Eating\n", philo->id);
	pthread_mutex_lock(&table->mutex[m1]);
	pthread_mutex_lock(&table->mutex[m2]);
	printf("Philo id: %d is taking a fork\n", philo[m1].id);
	usleep(philo->state->t_eat);
	pthread_mutex_unlock(&table->mutex[m1]);
	pthread_mutex_unlock(&table->mutex[m2]);
	printf("Philo id: %d left the fork\n", philo[m1].id);
	philo->time = philo->state->t_die;
}

void	sleeping(t_philo *philo)
{
	printf("Philo id: %d is Sleeping\n", philo->id);
	usleep(philo->state->t_sleep);
	philo->time = philo->time - philo->state->t_sleep;
}

void	*philostate(void *arg)
{
	t_philo	*philo;
	int	m_eat;
	
	philo = (t_philo *) arg;
	m_eat = philo->state->m_eat;
	printf("///////Philo ID: %d\n", philo->id);
	while (1)
	{
		if(m_eat == 0)
			cleanall(philo, philo->state->numphilo);
		thinking(philo);
		eating(philo);
		sleeping(philo);
		m_eat--;
	}
	return (NULL);
}
