/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:43:06 by msierra-          #+#    #+#             */
/*   Updated: 2022/03/01 17:59:06 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

void	died(t_philo *philo)
{
	t_state	*table;

	table = philo->state;
	// printf("id: %d\n", id);
	if (table->numph > 1)
		t_sleep(philo, 1);
	print_msg(philo, 6, table->philo_dead);
}

void	thinking(t_philo *philo)
{
	if (check_dead(philo->state, philo) == 0)
	{
		print_msg(philo, 5, philo->id);
		usleep(50);
	}
}

void	eating(t_philo *philo)
{
	t_state	*table;

	if (check_dead(philo->state, philo) == 0)
	{
		table = philo->state;
		manage_fork(philo, table);
		add_timer(philo, table->t_eat);
		usleep(50);
		// philo->last_eat = ((int)gettime() - table->t_init);
		// table->l_eat = philo->last_eat;
		// philo->time += table->t_eat;
		// printf("philo %d: time en eating: %zu\n", philo->id, philo->time);
	}
}

void	sleeping(t_philo *philo)
{
	t_state	*table;

	if (check_dead(philo->state, philo) == 0)
	{
		table = philo->state;
		print_msg(philo, 4, philo->id);
		t_sleep(philo, table->t_sleep);
		add_timer(philo, table->t_sleep);
		philo->need_food = 1;
		usleep(50);
		// philo->time += table->t_sleep;
		// printf("philo %d: time en sleeping: %zu\n", philo->id, philo->time);
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
		// printf("philo %d: time al principio: %zu\n", philo->id, philo->time);
		// printf("t_eat: %zu\n", philo->state->t_eat);
		eating(philo);
		usleep(50);
		sleeping(philo);
		usleep(50);
		thinking(philo);
		usleep(50);
		philo->time = (int)gettime();
		m_eat--;
		philo->state->all_eat--;
	}
	return (NULL);
}
