#include "philo.h"

void	*ft_is_dead(void	*data)
{
	t_philo					*philo;

	philo = (t_philo *)data;
	ft_usleep(philo->philo_a->time_to_die + 1);
	pthread_mutex_lock(&philo->philo_a->time_eat);
	pthread_mutex_lock(&philo->philo_a->finish);
	if (!check_death(philo, 0) && !philo->finish && ((current_time() - philo->must_eat) \
		>= (long)(philo->philo_a->time_to_die)))
	{
		pthread_mutex_unlock(&philo->philo_a->time_eat);
		pthread_mutex_unlock(&philo->philo_a->finish);
		pthread_mutex_lock(&philo->philo_a->write_mutex);
		write_status("died\n", philo);
		pthread_mutex_unlock(&philo->philo_a->write_mutex);
		check_death(philo, 1);
	}
	pthread_mutex_unlock(&philo->philo_a->time_eat);
	pthread_mutex_unlock(&philo->philo_a->finish);
	return (NULL);
}

void	*ft_thread(void *data)
{
	t_philo					*philo;

	philo = (t_philo *)data;
	if (philo->ident % 2 == 0)
		ft_usleep(philo->philo_a->time_to_eat / 10);
	while (!check_death(philo, 0))
	{
		pthread_create(&philo->thread_death_ident, NULL, ft_is_dead, data);
		routine(philo);
		pthread_detach(philo->thread_death_ident);
		if ((int)++philo->nb_eat == philo->philo_a->philo_must_eat)
		{
			pthread_mutex_lock(&philo->philo_a->finish);
			philo->finish = 1;
			philo->philo_a->nb_philo_finish++;
			if (philo->philo_a->nb_philo_finish == philo->philo_a->nb_of_philo)
			{
				pthread_mutex_unlock(&philo->philo_a->finish);
				check_death(philo, 2);
			}
			pthread_mutex_unlock(&philo->philo_a->finish);
			return (NULL);
		}
	}
	return (NULL);
}

int	thread_init(t_e *e)
{
	int	i;

	i = 0;
	while (i < e->arg.nb_of_philo)
	{
		e->philo[i].philo_a = &e->arg;
		if (pthread_create(&e->philo[i].thread_ident, NULL, ft_thread, &e->philo[i]) != 0)
			return (ft_error("Error: Pthread did not return 0\n"));
		i++;
	}
	return (1);
}
