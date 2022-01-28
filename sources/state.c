/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:43:06 by msierra-          #+#    #+#             */
/*   Updated: 2022/01/28 18:14:01 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

void	died(t_philo *philo)
{
	int		i;
	t_state	*table;

	i = 0;
	table = philo->state;
	printf(RED "Philo id: %d is Dead\n" RESET, philo->id);
	while(i < table->numphilo)
	{
		pthread_exit(&table->thread[i]);
		i++;
	}
}

void	thinking(t_philo *philo)
{
	size_t	time;

	if (philo->state->is_dead == 0)
	{
		printf(YELLOW "Philo id: %d is Thinking\n" RESET, philo->id);
		time = gettime();
		philo->time = time - philo->time;
	}
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
	// coge tenedor 1
	pthread_mutex_lock(&table->mutex[m2]); //Tenedor 2
	// coge tenedor 2
	// check_dead(philo, philo->time);
	printf(BLUE "Philo id: %d is taking a fork\n" RESET, philo->id);
	printf(GREEN "Philo id: %d is Eating\n" RESET, philo->id);
	usleep(philo->state->t_eat);
	pthread_mutex_unlock(&table->mutex[m1]);
	pthread_mutex_unlock(&table->mutex[m2]);
	printf(BLUE "Philo id: %d left the fork\n" RESET, philo->id);
	philo->time = gettime();
}

void	sleeping(t_philo *philo)
{
	if (philo->state->is_dead == 0)
	{
		printf(PINK "Philo id: %d is Sleeping\n" RESET, philo->id);
		usleep(philo->state->t_sleep);
		philo->time = philo->time - philo->state->t_sleep;
	}
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
			printf("Philo %d finish eating\n", philo->id);
			break ;
		}
		thinking(philo);
		if (philo->state->is_dead == 0)
			eating(philo);
		sleeping(philo);
		m_eat--;
	}
	pthread_exit(&philo->state->thread[philo->id]);
	return (NULL);
}
