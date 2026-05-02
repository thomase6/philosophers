/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 09:15:43 by texenber          #+#    #+#             */
/*   Updated: 2026/05/02 14:50:08 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILOS_H
# define PHILOS_H
# define TOO_MANY_ARGS "wrong argument count.\n"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>


typedef struct s_data
{
	int64_t	p_num;
	int64_t	time_to_d;
	int64_t	time_to_e;
	int64_t	time_to_s;
	int64_t	num_of_meals;
	int64_t	start;
	int64_t	death_flag;
	pthread_mutex_t	*forks;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	print_mutex;
	
}	t_data;

typedef struct	s_philos
{
	pthread_t thread;
	int64_t	id;
	int64_t	last_meal;
	int64_t	meals_eaten;
	t_data	*data;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	meal_mutex;
}	t_philos;

///		util functions		///
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
int		ft_isdigit(int i);
size_t	ft_strlen(const char *s);


#endif // PHILOS_H