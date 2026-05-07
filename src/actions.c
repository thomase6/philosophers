/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 11:29:44 by texenber          #+#    #+#             */
/*   Updated: 2026/05/07 15:41:19 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philos.h"

void	thinking(t_philos *philo)
{
	int64_t	tte;
	int64_t	tts;
	int64_t	ttt;

	tte = philo->data->time_to_e;
	tts = philo->data->time_to_s;
	ttt = 0;
	print_status(philo, THINK);
	if (philo->data->p_num % 2 == 0)
	{
		ttt = (tte - tts) * (tte > tts);
		if (ttt == 0)
			ttt = 1;
		ft_sleep(ttt, philo->data);
	}
	if (philo->data->p_num % 2 != 0)
	{
		ttt = (tte * 2) - tts * ((tte + tte) > tts);
		ft_sleep(ttt, philo->data);
	}
}

void	sleeping(t_philos *philo)
{
	print_status(philo, SLEEP);
	ft_sleep(philo->data->time_to_s, philo->data);
}

void	single_philo(t_philos *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, FORK);
	ft_sleep(philo->data->time_to_d + 2, philo->data);
	pthread_mutex_unlock(philo->left_fork);
	return ;
}

void	pick_forks(t_philos *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, FORK);
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, FORK);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, FORK);
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, FORK);
	}
	return ;
}

void	eating(t_philos *philo)
{
	if (philo->data->p_num == 1)
	{
		single_philo(philo);
		return ;
	}
	pick_forks(philo);
	print_status(philo, EAT);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal = get_time();
	philo->meals_eaten += 1;
	pthread_mutex_unlock(&philo->meal_mutex);
	ft_sleep(philo->data->time_to_e, philo->data);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
}
