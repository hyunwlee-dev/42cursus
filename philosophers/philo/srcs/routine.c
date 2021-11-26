/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 20:51:19 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/11/26 23:15:40 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_one_routine(void *arg)
{
	t_philos	*philos;

	philos = (t_philos *)arg;
	printf("%ldms %d has taken a fork\n", \
			get_time() - philos->info->start_time, philos->idx);
	smart_sleep(philos->info->args.time_to_die);
	printf("%ldms %d died\n", \
			get_time() - philos->info->start_time, philos->idx);
	return (NULL);
}

void	*thread_routine(void *arg)
{
	t_philos	*philos;
	pthread_t	monitoring_thread;

	philos = (t_philos *)arg;
	pthread_create(&monitoring_thread, NULL, monitor_die_state, philos);
	while (1)
	{
		if (!philos->info->is_all_live)
			break ;
		pickup_eat_routine(philos);
		if (philos->eat_cnt == philos->info->args.number_philo_must_eat)
			break ;
		sleep_think_routine(philos);
		usleep(50);
	}
	pthread_join(monitoring_thread, NULL);
	return (NULL);
}

void	pickup_eat_routine(t_philos *philos)
{
	if (philos->idx % 2 == 1)
	{
		usleep(500);
		pthread_mutex_lock(&philos->info->fork[philos->l_fork]);
		print_state(philos, PICKUP);
		pthread_mutex_lock(&philos->info->fork[philos->r_fork]);
		print_state(philos, PICKUP);
	}
	else if (philos->idx % 2 == 0)
	{
		pthread_mutex_lock(&philos->info->fork[philos->l_fork]);
		print_state(philos, PICKUP);
		pthread_mutex_lock(&philos->info->fork[philos->r_fork]);
		print_state(philos, PICKUP);
	}
	philos->last_eaten_time = get_time();
	print_state(philos, EAT);
	smart_sleep(philos->info->args.time_to_eat);
	pthread_mutex_unlock(&philos->info->fork[philos->r_fork]);
	pthread_mutex_unlock(&philos->info->fork[philos->l_fork]);
	++philos->eat_cnt;
}

void	sleep_think_routine(t_philos *philos)
{
	print_state(philos, SLEEP);
	smart_sleep(philos->info->args.time_to_sleep);
	print_state(philos, THINK);
}
