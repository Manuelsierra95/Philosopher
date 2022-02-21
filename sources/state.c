/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:43:06 by msierra-          #+#    #+#             */
/*   Updated: 2022/02/21 14:52:52 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

void	died(t_philo *philo)
{
	size_t	time;

	time = (gettime() - philo->state->t_init);
	printf(RED "[%zu ms]\tPhilo %d is Dead\n" RESET, time, philo->id);
}

void	thinking(t_philo *philo)
{
	size_t	time;

	time = (gettime() - philo->state->t_init);
	if (check_dead(philo->state, philo) == 0)
	{
		printf(YELLOW "[%zu ms]\tPhilo %d is Thinking\n" RESET, time, philo->id);
	}
}

void	eating(t_philo *philo)
{
	t_state	*table;

	if (check_dead(philo->state, philo) == 0)
	{
		table = philo->state;
		manage_fork(philo, table);
		philo->time -= table->t_eat;
	}
}

void	sleeping(t_philo *philo)
{
	size_t	time;

	time = (gettime() - philo->state->t_init);
	if (check_dead(philo->state, philo) == 0)
	{
		printf(PINK "[%zu ms]\tPhilo %d is Sleeping\n" RESET, time, philo->id);
		usleep(philo->state->t_sleep);
		philo->time -= philo->state->t_sleep;
	}
}

void	*phstate(void *arg)
{
	t_philo	*philo;
	int		m_eat;
	size_t	time;

	philo = (t_philo *) arg;
	m_eat = philo->state->m_eat;
	while (1)
	{
		time = (gettime() - philo->state->t_init);
		if (m_eat == 0)
		{
			printf("[%zu ms]\tPhilo %d finish eating\n", time, philo->id);
			break ;
		}
		thinking(philo);
		eating(philo);
		sleeping(philo);
		philo->time = gettime();
		m_eat--;
	}
	return (NULL);
}
