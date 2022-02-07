/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:43:06 by msierra-          #+#    #+#             */
/*   Updated: 2022/02/07 17:53:07 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

void	died(t_philo *philo)
{
	int	time;

	time = philo->state->pt;
	printf(RED "[%d]\tPhilo %d is Dead\n" RESET, time, philo->id);
}

void	thinking(t_philo *philo)
{
	int	time;

	time = philo->state->pt;
	if (check_dead(philo->state, philo) == 0)
		printf(YELLOW "[%d]\tPhilo %d is Thinking\n" RESET, time, philo->id);
}

void	eating(t_philo *philo)
{
	t_state	*table;

	if (check_dead(philo->state, philo) == 0)
	{
		table = philo->state;
		manage_fork(philo, table);
		sleeptime(philo->state->t_eat, philo);
		philo->time = gettime();
	}
}

void	sleeping(t_philo *philo)
{
	int	time;

	time = philo->state->pt;
	if (check_dead(philo->state, philo) == 0)
	{
		printf(PINK "[%d]\tPhilo %d is Sleeping\n" RESET, time, philo->id);
		sleeptime(philo->state->t_sleep, philo);
		philo->time = philo->time - philo->state->t_sleep;
	}
}

void	*phstate(void *arg)
{
	t_philo	*philo;
	int		m_eat;
	int		time;

	philo = (t_philo *) arg;
	time = philo->state->pt;
	m_eat = philo->state->m_eat;
	while (1)
	{
		if (m_eat == 0)
		{
			printf("[%d]\tPhilo %d finish eating\n", time, philo->id);
			break ;
		}
		thinking(philo);
		eating(philo);
		sleeping(philo);
		m_eat--;
	}
	return (NULL);
}
