/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:47:43 by msierra-          #+#    #+#             */
/*   Updated: 2022/01/26 20:10:39 by msierra-         ###   ########.fr       */
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
#define RED	"\x1b[41m"
#define GREEN	"\x1b[42m"
#define RESET	"\x1b[0m"

typedef struct s_state
{
    int				t_die;
    int				t_eat;
    int				t_sleep;
    int				m_eat;
	int				is_dead;
	int				numphilo;
	pthread_t		*thread;
	pthread_mutex_t	*mutex;
}	t_state;
typedef struct s_philo
{
	t_state *state;
	int		id;
	size_t		time;
	
}	t_philo;
// init
void	mutex_init(t_state *state, t_philo *philo);
void	thread_init(t_state *state, t_philo *philo);
void	philo_init(t_state *state, t_philo *philo);
void	join_init(t_state *state);
// Includes
int	ft_atoi(const char *str);
// Cleaner mallocs
void	clean(t_philo *philo);
void	cleanmutex(t_philo *philo, int num);
void	cleanthread(t_philo *philo, int num);
void	cleanall(t_philo *philo, int num);
// Parse
void    getvalues(int argc, char **argv, t_state *state);
// Thread state & manage
void	*philostate(void *arg);
void	died(t_philo *philo);
// Utils
size_t	gettime(void);
int	minthread(int num1, int num2);
int	maxthread(int num1, int num2);
void	check_dead(t_philo *philo, long int checktimer);
// Error
void	errormsg(int flag);

#endif
