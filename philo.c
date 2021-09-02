#include "philo.h"

void	ft_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_left);
	pthread_mutex_lock(&philo->philo_a->write_mutex);
	write_status("has taken a fork\n", philo);
	pthread_mutex_unlock(&philo->philo_a->write_mutex);
	if (!philo->fork_right)
	{
		ft_usleep(philo->philo_a->time_to_die * 2);
		return ;
	}
	pthread_mutex_lock(philo->fork_right);
	pthread_mutex_lock(&philo->philo_a->write_mutex);
	write_status("has taken a fork\n", philo);
	pthread_mutex_unlock(&philo->philo_a->write_mutex);
	pthread_mutex_lock(&philo->philo_a->write_mutex);
	write_status("is eating\n", philo);
	pthread_mutex_lock(&philo->philo_a->time_eat);
	philo->must_eat = actual_time();
	pthread_mutex_unlock(&philo->philo_a->time_eat);
	pthread_mutex_unlock(&philo->philo_a->write_mutex);
	ft_usleep(philo->philo_a->time_to_eat);
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(&philo->fork_left);
	sleep_think(philo);
}
