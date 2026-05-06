/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 09:15:43 by texenber          #+#    #+#             */
/*   Updated: 2026/05/06 18:00:16 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILOS_H
# define PHILOS_H
///		error messages		///
# define TOO_MANY_ARGS	"Wrong argument count.\n"
# define INVALID_ARGS	"Invalid arguments.\n"
# define INVALID_PHILOS	"Invalid number of philos.\n"
# define MUTEX_FAIL		"Mutex failed to create.\n"
# define ALLOC_FAIL		"Failed to malloc.\n"
# define GET_TIME_ERR	"Failed to get time.\n"
///		action messages		///
# define EAT			"is eating"
# define FORK			"has taken a fork"
# define SLEEP			"is sleeping"
# define THINK			"is thinking"
# define DIED			"died"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data	t_data;
typedef struct s_philos	t_philos;

typedef struct s_data
{
	int64_t	p_num;
	int64_t	time_to_d;
	int64_t	time_to_e;
	int64_t	time_to_s;
	int64_t	num_of_meals;
	int64_t	start;
	int64_t	death_flag;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*forks;
	t_philos	*philos;	
}	t_data;

typedef struct	s_philos
{
	pthread_t thread;
	int64_t	id;
	int64_t	last_meal;
	int64_t	meals_eaten;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	meal_mutex;
	t_data	*data;
}	t_philos;

typedef enum e_error
{
	SUCCESS,
	ERR_PARSING,
	ERR_INIT_MUTEX,
	ERR_INIT_PHILO
}	t_error;

///		util functions		///
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
int		ft_isdigit(int i);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);

///		parsing the arguments		///
int		parse_args(int argc, char **argv);
int		valid_args(char **av);
int		digit_check(char **av);
int		overflow_check(char **av);
int		is_overflow(char *str);

///		initialization				///
int		init_data(t_data *data, char **av);
int		init_mutex(t_data *data);
int		init_philos(t_data *data);

///		time functions		///
int64_t	get_time(void);
void	ft_sleep(int64_t ms, t_data *data);

///		routine and actions			///
void	*routine(void *arg);
void	eating(t_philos *philo);
void	single_philo(t_philos *philo);
void	sleeping(t_philos *philo);
void	thinking(t_philos *philo);

///		mutex locks		///
void	print_status(t_philos *philo, char *msg);
int		is_dead(t_data *data);

///		monitor and helper functions		///
void	*monitor_r(void *arg);
int		check_death(t_data *data);
int		check_meals(t_data *data);

///		cleanup		///
void	destroy_fork_mutexes(t_data *data, int count);
void	destroy_meal_mutex(t_data *data, int count);
void	cleanup(t_data *data);
void	destroy_print_and_death_mutex(t_data *data);
void	destroy_multiple_mutexes(t_data *data);

#endif // PHILOS_H