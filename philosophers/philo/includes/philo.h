/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunwlee <hyunwlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 22:24:51 by hyunwlee          #+#    #+#             */
/*   Updated: 2021/11/26 23:22:22 by hyunwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef enum e_state
{
	PICKUP,
	EAT,
	SLEEP,
	THINK,
	DEAD
}	t_state;

typedef struct s_args
{
	int				number_philos;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int				number_philo_must_eat;
}	t_args;

typedef struct s_info
{
	struct s_args	args;
	int				is_all_live;
	unsigned long	start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	scrambled_view_mutex;
	pthread_mutex_t	die_mutex;
}	t_info;

typedef struct s_philos
{
	struct s_info	*info;
	int				idx;
	int				l_fork;
	int				r_fork;
	int				eat_cnt;
	unsigned long	last_eaten_time;
	pthread_t		tid;
}	t_philos;

int				init_total(int argc, char *argv[]);
int				init_infos(int argc, char *argv[], t_info *infos);
int				init_args(int argc, char *argv[], t_args *args);
int				init_one_thread(t_info *infos, t_philos **philos);
int				init_thread(t_info *infos, t_philos **philos);
void			*thread_one_routine(void *arg);
void			*thread_routine(void *arg);
void			pickup_eat_routine(t_philos *philos);
void			sleep_think_routine(t_philos *philos);
void			print_state(t_philos *philos, t_state thread_state);
void			*monitor_die_state(void *arg);
void			smart_sleep(unsigned long time);
void			free_total(t_philos **philos);
void			free_info(t_info *infos);
unsigned long	get_time(void);
int				ft_isdigit(int c);
int				ft_atoi(const char *nptr);
int				check_validation_input(int argc, char *argv[]);

#endif
