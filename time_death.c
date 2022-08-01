/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_death.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida <mida@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:01:09 by mida              #+#    #+#             */
/*   Updated: 2021/09/03 15:05:47 by mida             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->philo_a->dead);
	if (i)
		philo->philo_a->stop = i;
	if (philo->philo_a->stop)
	{
		pthread_mutex_unlock(&philo->philo_a->dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->philo_a->dead);
	return (0);
}

void	ft_usleep(long int time_in_ms)
{
	long int	start_time;

	start_time = 0;
	start_time = current_time();
	while ((current_time() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}

long int	current_time(void)
{
	long int			time;
	struct timeval		current_time;

	time = 0;
	if (gettimeofday(&current_time, NULL) == -1)
		ft_error("Error: Gettimeofday returned -1\n");
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}
