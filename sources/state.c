/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:43:06 by msierra-          #+#    #+#             */
/*   Updated: 2022/01/26 20:13:43 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

void	died(t_philo *philo)
{
	printf(RED "Philo id: %d is Dead\n" RESET, philo->id);
}

void	thinking(t_philo *philo)
{
	size_t	time;

	time = gettime();
	philo->time = time - philo->time;
	check_dead(philo, philo->time);
}

void	eating(t_philo *philo)
{
	int		m1;
	int 	m2;
	t_state	*table;

	table = philo->state;
	m1 = minthread(philo->id, (philo->id + 1)%philo->state->numphilo);
	m2 = maxthread(philo->id, (philo->id + 1)%philo->state->numphilo);
	pthread_mutex_lock(&table->mutex[m1]); //Tenedor 1
	pthread_mutex_lock(&table->mutex[m2]); //Tenedor 2
	check_dead(philo, philo->time);
	printf("Philo id: %d is taking a fork\n", philo->id);
	printf(GREEN "Philo id: %d is Eating\n" RESET, philo->id);
	usleep(philo->state->t_eat);
	pthread_mutex_unlock(&table->mutex[m1]);
	pthread_mutex_unlock(&table->mutex[m2]);
	printf("Philo id: %d left the fork\n", philo->id);
	philo->time = gettime();
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
	while (1)
	{
		if(m_eat == 0)
		{
			died(philo);
			// exit(0);
			cleanall(philo, philo->state->numphilo);
		}
		thinking(philo);
		eating(philo);
		sleeping(philo);
		m_eat--;
	}
	return (NULL);
}
