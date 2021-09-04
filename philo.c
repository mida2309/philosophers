/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida <mida@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:00:41 by mida              #+#    #+#             */
/*   Updated: 2021/09/03 15:00:45 by mida             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_write(char *str, t_philo *philo)
{
	long int		time;

	time = -1;
	time = current_time() - philo->philo_a->start_t;
	if (time >= 0 && time <= 2147483647 && !check_death(philo, 0))
	{
		printf("%ldms ", time);
		printf("Philo %d %s", philo->ident, str);
	}
}

void	sleep_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_a->write_mutex);
	ft_write("is sleeping\n", philo);
	pthread_mutex_unlock(&philo->philo_a->write_mutex);
	ft_usleep(philo->philo_a->time_to_sleep);
	pthread_mutex_lock(&philo->philo_a->write_mutex);
	ft_write("is thinking\n", philo);
	pthread_mutex_unlock(&philo->philo_a->write_mutex);
}

void	ft_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_left);
	pthread_mutex_lock(&philo->philo_a->write_mutex);
	ft_write("has taken a fork\n", philo);
	pthread_mutex_unlock(&philo->philo_a->write_mutex);
	if (!philo->fork_right)
	{
		ft_usleep(philo->philo_a->time_to_die * 2);
		return ;
	}
	pthread_mutex_lock(philo->fork_right);
	pthread_mutex_lock(&philo->philo_a->write_mutex);
	ft_write("has taken a fork\n", philo);
	pthread_mutex_unlock(&philo->philo_a->write_mutex);
	pthread_mutex_lock(&philo->philo_a->write_mutex);
	ft_write("is eating\n", philo);
	pthread_mutex_lock(&philo->philo_a->time_eat);
	philo->must_eat = current_time();
	pthread_mutex_unlock(&philo->philo_a->time_eat);
	pthread_mutex_unlock(&philo->philo_a->write_mutex);
	ft_usleep(philo->philo_a->time_to_eat);
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(&philo->fork_left);
	sleep_think(philo);
}
