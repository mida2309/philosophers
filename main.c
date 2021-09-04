/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida <mida@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 15:00:22 by mida              #+#    #+#             */
/*   Updated: 2021/09/03 15:03:36 by mida             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	return (0);
}

int	check_death2(t_e *e)
{
	pthread_mutex_lock(&e->arg.dead);
	if (e->arg.stop)
	{
		pthread_mutex_unlock(&e->arg.dead);
		return (1);
	}
	pthread_mutex_unlock(&e->arg.dead);
	return (0);
}

void	ft_stop(t_e *e)
{
	int	i;

	i = -1;
	while (!check_death2(e))
		ft_usleep(1);
	while (++i < e->arg.nb_of_philo)
		pthread_join(e->philo[i].thread_ident, NULL);
	pthread_mutex_destroy(&e->arg.write_mutex);
	i = -1;
	while (++i < e->arg.nb_of_philo)
		pthread_mutex_destroy(&e->philo[i].fork_left);
	if (e->arg.stop == 2)
		printf("Each philosopher ate %d time(s)\n", e->arg.philo_must_eat);
	free(e->philo);
}

int	main(int ac, char **av)
{
	t_e		e;

	if (!(check_arg(ac, av, &e)))
		return (ft_error("Error: Wrong arguments\n"));
	e.philo = malloc(sizeof(t_philo) * e.arg.nb_of_philo);
	if (!e.philo)
		return (ft_error("Error: Malloc\n"));
	if (!init(&e) || !thread_init(&e))
	{
		free(e.philo);
		return (0);
	}
	ft_stop(&e);
}
