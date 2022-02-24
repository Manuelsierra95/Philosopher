/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:43:06 by msierra-          #+#    #+#             */
/*   Updated: 2022/02/24 17:59:24 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

void	died(t_philo *philo)
{
	t_state	*table;

	table = philo->state;
	t_sleep(philo, table->t_die);
	print_msg(philo, 6, philo->id);
}

void	thinking(t_philo *philo)
{
	if (check_dead(philo->state, philo) == 0)
	{
		print_msg(philo, 5, philo->id);
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
	t_state	*table;

	if (check_dead(philo->state, philo) == 0)
	{
		table = philo->state;
		t_sleep(philo, table->t_sleep);
		print_msg(philo, 4, philo->id);
		philo->time -= table->t_sleep;
	}
}

void	*phstate(void *arg)
{
	t_philo	*philo;
	int		m_eat;

	philo = (t_philo *) arg;
	m_eat = philo->state->m_eat;
	while (1)
	{
		if (m_eat == 0)
		{
			print_msg(philo, 7, philo->id);
			// printf("[%zu ms]\tPhilo %d finish eating\n", time, philo->id);
			break ;
		}
		eating(philo);
		sleeping(philo);
		thinking(philo);
		philo->time = 0;
		m_eat--;
	}
	printf("Acaba hilo\n");
	return (NULL);
}
