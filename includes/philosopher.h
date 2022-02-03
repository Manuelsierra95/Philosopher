/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:47:43 by msierra-          #+#    #+#             */
/*   Updated: 2022/02/01 18:36:39 by msierra-         ###   ########.fr       */
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
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define RESET	"\033[0m"
#define PINK	"\033[35m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"

typedef struct s_state
{
    int				t_die;
    int				t_eat;
    int				t_sleep;
    int				m_eat;
	int				is_dead;
	int				numphilo;
	int				need_clean;
	char			*fork;
	pthread_t		*thread;
	pthread_mutex_t	*mutex;
}	t_state;
typedef struct s_philo
{
	t_state *state;
	int		id;
	size_t	time;
	
}	t_philo;
// init
void	mutex_init(t_state *state, t_philo *philo);
void	thread_init(t_state *state, t_philo *philo);
void	philo_init(t_state *state, t_philo *philo);
void	join_init(t_state *state, t_philo *philo);
void	fork_init(t_state *state);
// Includes
int		atoi(const char *str);
// Cleaner mallocs
void	clean(t_philo *philo);
void	cleanmutex(t_philo *philo, int print);
void	cleanthread(t_philo *philo, int print);
void	cleanall(t_philo *philo, int print);
// Parse
void    getvalues(int argc, char **argv, t_state *state);
// Thread state & manage
void	*philostate(void *arg);
void	died(int id);
// Utils
size_t	gettime(void);
void	printtime();
int		minthread(int num1, int num2);
int		maxthread(int num1, int num2);
void	*set_dead(void *arg);
int		check_dead(t_state *state, t_philo *philo, int id);
void	lock_mutex(pthread_mutex_t *mutex, t_state *state, int i);
void	unlock_mutex(pthread_mutex_t *mutex, t_state *state, int i);
void	manage_fork(t_philo *philo, t_state *table);

// Error
void	errormsg(int flag);
#endif
