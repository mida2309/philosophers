/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida <mida@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:58:09 by mida              #+#    #+#             */
/*   Updated: 2021/09/03 14:58:41 by mida             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_arg
{
	int						nb_of_philo;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						philo_must_eat;
	long int				start_t;
	pthread_mutex_t			write_mutex;
	pthread_mutex_t			dead;
	pthread_mutex_t			time_eat;
	pthread_mutex_t			finish;
	int						nb_philo_finish;
	int						stop;
}							t_arg;

typedef struct s_philo
{
	int						ident;
	pthread_t				thread_ident;
	pthread_t				thread_death_ident;
	pthread_mutex_t			*fork_right;
	pthread_mutex_t			fork_left;
	t_arg					*philo_a;
	long int				must_eat;
	unsigned int			nb_eat;
	int						finish;
}							t_philo;
typedef struct s_e
{
	t_philo					*philo;
	t_arg					arg;
}							t_e;

int			check_arg(int ac, char **av, t_e *e);
int			init(t_e *e);
int			ft_error(char *str);
void		ft_write(char *str, t_philo *philo);
long int	current_time(void);
void		ft_putstr_fd(char *s, int fd);
void		ft_usleep(long int time_in_ms);
int			thread_init(t_e *e);
void		ft_routine(t_philo *philo);
int			ft_strlen(char *str);
int			check_death(t_philo *philo, int i);

#endif
