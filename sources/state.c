/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:43:06 by msierra-          #+#    #+#             */
/*   Updated: 2022/02/01 18:33:50 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/philosopher.h"

void	died(int id)
{
	printf(RED "Philo %d is Dead\n" RESET, id);
}

void	thinking(t_philo *philo)
{
	size_t	time;

	if (check_dead(philo->state, philo->id) == 0)
	{
		time = gettime();
		philo->time = time - philo->time;
		printf(YELLOW "Philo %d is Thinking\n" RESET, philo->id);
	}
	// else
	// {
	// 	died(philo, philo->id);
	// 	cleanall(philo, 2);
	// 	exit(0);
	// }
}

void	eating(t_philo *philo)
{
	t_state	*table;

	table = philo->state;
	
	printf(BLUE "Philo %d is taking a fork\n" RESET, philo->id);
	printf(GREEN "Philo %d is Eating\n" RESET, philo->id);
	manage_fork(philo, table);
	usleep(philo->state->t_eat);
	printf(BLUE "Philo %d left the fork\n" RESET, philo->id);
	philo->time = gettime();
}

void	sleeping(t_philo *philo)
{
	if (check_dead(philo->state, philo->id) == 0)
	{
		printf(PINK "Philo %d is Sleeping\n" RESET, philo->id);
		usleep(philo->state->t_sleep);
		philo->time = philo->time - philo->state->t_sleep;
	}
	// else
	// {
	// 	died(philo, philo->id);
	// 	cleanall(philo, 2);
	// 	exit(0);
	// }
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
		if (check_dead(philo->state, philo->id) == 0)
			eating(philo);
		sleeping(philo);
		m_eat--;
	}
	return (NULL);
}
