/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:47:43 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/11/26 23:21:51 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(t_philos *philos, t_state thread_state)
{
	pthread_mutex_lock(&philos->info->scrambled_view_mutex);
	if (philos->info->is_all_live && thread_state == DEAD)
		printf("%ldms %d died\n", \
				get_time() - philos->info->start_time, philos->idx);
	if (philos->info->is_all_live && thread_state == PICKUP)
		printf("%ldms %d has taken a fork\n", \
				get_time() - philos->info->start_time, philos->idx);
	else if (philos->info->is_all_live && thread_state == EAT)
		printf("%ldms %d is eating\n", \
				get_time() - philos->info->start_time, philos->idx);
	else if (philos->info->is_all_live && thread_state == SLEEP)
		printf("%ldms %d is sleeping\n", \
				get_time() - philos->info->start_time, philos->idx);
	else if (philos->info->is_all_live && thread_state == THINK)
		printf("%ldms %d is thinking\n", \
				get_time() - philos->info->start_time, philos->idx);
	pthread_mutex_unlock(&philos->info->scrambled_view_mutex);
}

void	*monitor_die_state(void *arg)
{
	t_philos	*philos;

	philos = (t_philos *)arg;
	while (1)
	{
		if (!philos->info->is_all_live)
			break ;
		if (philos->eat_cnt == philos->info->args.number_philo_must_eat)
			break ;
		pthread_mutex_lock(&philos->info->die_mutex);
		if (get_time() > philos->info->args.time_to_die + \
				philos->last_eaten_time)
		{
			print_state(philos, DEAD);
			philos->info->is_all_live = 0;
			pthread_mutex_unlock(&philos->info->fork[philos->r_fork]);
			pthread_mutex_unlock(&philos->info->fork[philos->l_fork]);
			pthread_mutex_unlock(&philos->info->die_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&philos->info->die_mutex);
	}
	return (NULL);
}

void	smart_sleep(unsigned long time)
{
	unsigned long	timeval;

	timeval = get_time() + time;
	while (timeval > get_time())
		usleep(100);
}

void	free_total(t_philos **philos)
{
	free_info((*philos)->info);
	free(*philos);
}

void	free_info(t_info *infos)
{
	int	i;

	i = -1;
	while (++i < infos->args.number_philos)
		pthread_mutex_destroy(&infos->fork[i]);
	pthread_mutex_destroy(&infos->die_mutex);
	pthread_mutex_destroy(&infos->scrambled_view_mutex);
	free(infos->fork);
}
