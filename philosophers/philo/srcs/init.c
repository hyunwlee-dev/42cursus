/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 01:31:24 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/11/26 23:18:23 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_total(int argc, char *argv[])
{
	t_info		info;
	t_philos	*philos;

	philos = NULL;
	if (init_infos(argc, argv, &info))
		return (-1);
	if (info.args.number_philos == 1)
	{
		if (init_one_thread(&info, &philos))
			return (-1);
	}
	else
	{
		if (init_thread(&info, &philos))
			return (-1);
	}
	free_total(&philos);
	return (0);
}

int	init_infos(int argc, char *argv[], t_info *infos)
{
	int	i;

	if (init_args(argc, argv, &infos->args))
		return (-1);
	infos->is_all_live = 1;
	infos->start_time = get_time();
	infos->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
			* infos->args.number_philos);
	if (!infos->fork)
		return (-1);
	i = -1;
	while (++i < infos->args.number_philos)
		pthread_mutex_init(&infos->fork[i], NULL);
	pthread_mutex_init(&infos->scrambled_view_mutex, NULL);
	pthread_mutex_init(&infos->die_mutex, NULL);
	return (0);
}

int	init_args(int argc, char *argv[], t_args *args)
{
	if (check_validation_input(argc, argv))
		return (-1);
	args->number_philos = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	args->number_philo_must_eat = -1;
	if (argc == 6)
		args->number_philo_must_eat = ft_atoi(argv[5]);
	return (0);
}

int	init_one_thread(t_info *infos, t_philos **philos)
{
	(*philos) = (t_philos *)malloc(sizeof(t_philos));
	if (!philos)
		return (-1);
	(*philos)->info = infos;
	(*philos)->idx = 0;
	(*philos)->l_fork = 0;
	(*philos)->r_fork = 0;
	(*philos)->eat_cnt = 0;
	(*philos)->last_eaten_time = (*philos)->info->start_time;
	if (pthread_create(&(*philos)->tid, NULL, \
				thread_one_routine, (void *)(*philos)))
		return (-1);
	pthread_join((*philos)->tid, NULL);
	return (0);
}

int	init_thread(t_info *infos, t_philos **philos)
{
	int	i;

	(*philos) = (t_philos *)malloc(sizeof(t_philos) \
			* infos->args.number_philos);
	if (!philos)
		return (-1);
	i = -1;
	while (++i < infos->args.number_philos)
	{
		(*philos)[i].info = infos;
		(*philos)[i].idx = i;
		(*philos)[i].l_fork = i;
		(*philos)[i].r_fork = (i + 1) % (*philos)->info->args.number_philos;
		(*philos)[i].eat_cnt = 0;
		(*philos)[i].last_eaten_time = (*philos)->info->start_time;
		if (pthread_create(&(*philos)[i].tid, NULL, thread_routine, \
				(void *)&(*philos)[i]))
			return (-1);
	}
	i = -1;
	while (++i < infos->args.number_philos)
		pthread_join((*philos)[i].tid, NULL);
	return (0);
}
