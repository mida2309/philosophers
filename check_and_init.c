/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida <mida@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 14:59:44 by mida              #+#    #+#             */
/*   Updated: 2021/09/04 14:33:48 by mida             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	nome;
	int	sinal;

	nome = 0;
	sinal = 1;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
	{
		str++;
	}
	if (*str == '-')
	{
		sinal = sinal * -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nome = (nome * 10) + (*str++ - '0');
	}
	return (nome * sinal);
}

int	numeric(char **argv, int i, int j)
{
	while (argv[j])
	{
		while (argv[j][i])
		{
			if (argv[j][i] < '0' || argv[j][i] > '9' || ft_strlen(argv[j]) > 10)
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	check_arg(int ac, char **av, t_e *e)
{
	if ((ac == 5 || ac == 6) && numeric(av, 0, 1))
	{
		e->arg.nb_of_philo = ft_atoi(av[1]);
		e->arg.time_to_die = ft_atoi(av[2]);
		e->arg.time_to_eat = ft_atoi(av[3]);
		e->arg.time_to_sleep = ft_atoi(av[4]);
		e->arg.philo_must_eat = -1;
		if (ac == 6)
			e->arg.philo_must_eat = ft_atoi(av[5]);
		if (e->arg.nb_of_philo <= 0 || e->arg.time_to_die <= 0 \
				|| e->arg.time_to_eat <= 0 \
				|| e->arg.time_to_sleep <= 0)
			return (0);
		return (1);
	}
	return (0);
}

void	init_mutex(t_e *e)
{
	pthread_mutex_init(&e->arg.write_mutex, NULL);
	pthread_mutex_init(&e->arg.dead, NULL);
	pthread_mutex_init(&e->arg.time_eat, NULL);
	pthread_mutex_init(&e->arg.finish, NULL);
}

int	init(t_e *e)
{
	int	i;

	i = 0;
	e->arg.start_t = current_time();
	e->arg.stop = 0;
	e->arg.nb_philo_finish = 0;
	init_mutex(e);
	while (i < e->arg.nb_of_philo)
	{
		e->philo[i].ident = i + 1;
		e->philo[i].must_eat = e->arg.start_t;
		e->philo[i].nb_eat = 0;
		e->philo[i].finish = 0;
		e->philo[i].fork_right = NULL;
		pthread_mutex_init(&e->philo[i].fork_left, NULL);
		if (e->arg.nb_of_philo == 1)
			return (1);
		if (i == e->arg.nb_of_philo - 1)
			e->philo[i].fork_right = &e->philo[0].fork_left;
		else
			e->philo[i].fork_right = &e->philo[i + 1].fork_left;
		i++;
	}
	return (1);
}
