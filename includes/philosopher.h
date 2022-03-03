/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:47:43 by msierra-          #+#    #+#             */
/*   Updated: 2022/03/03 15:50:54 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define RESET	"\033[0m"
# define PINK	"\033[35m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define CYAN	"\033[36m"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_state
{
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				t_init;
	int				is_dead;
	int				m_eat;
	int				all_eat;
	int				numph;
	int				need_clean;
	int				l_eat;
	int				philo_dead;
	char			*fork;
	pthread_t		*thread;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	print;
	pthread_mutex_t	if_eat;
}	t_state;
typedef struct s_philo
{
	int		n_food;
	t_state	*state;
	int		id;
	int		time;
}	t_philo;
// init
void	mutex_init(t_state *state);
void	thread_init(t_state *state, t_philo *philo);
void	philo_init(t_state *state, t_philo *philo);
void	join_init(t_state *state, t_philo *philo);
void	fork_init(t_state *state);
void	join_init(t_state *state, t_philo *philo);
// Includes
int		atoi(const char *str);
// Cleaner mallocs
void	clean(t_philo *philo);
void	cleanmutex(t_philo *philo, int print);
void	cleanthread(t_philo *philo, int print);
void	cleanall(t_philo *philo, int print);
// Parse
void	getvalues(int argc, char **argv, t_state *state);
// Thread state & manage
void	*phstate(void *arg);
void	died(t_philo *philo);
// Utils
int		gettime(void);
int		minthread(int num1, int num2);
int		maxthread(int num1, int num2);
void	*set_dead(void *arg);
int		check_dead(t_state *state, t_philo *philo);
void	lock_mutex(pthread_mutex_t *mutex, t_philo *philo, int i, int id);
void	unlock_mutex(pthread_mutex_t *mutex, t_philo *philo, int i, int id);
void	manage_fork(t_philo *philo, t_state *table);
void	print_msg(t_philo *philo, int flag, int id);
void	t_sleep(t_philo *philo, int t_sleep);
void	add_timer(t_philo *philo, int time);
void	onephilo(t_philo *philo);
// Error
void	errorcontrol(int argc, char **argv);
void	errormsg(int flag);
void	leak(void);
#endif