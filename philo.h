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
