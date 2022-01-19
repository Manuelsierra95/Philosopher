/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:47:43 by msierra-          #+#    #+#             */
/*   Updated: 2022/01/19 14:21:43 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

/*
Required
*/
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_state
{
    int t_die;
    int t_eat;
    int t_sleep;
    int m_eat;
}	t_state;
typedef struct s_philo
{
	int     		count;
    int     		time;
	pthread_mutex_t	*mutex;
	t_state 		state;
}	t_philo;
int	ft_atoi(const char *str);


void    ft_parse(int argc, char **argv, t_philo *philo);
void	*philostate();
#endif
