/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 15:20:39 by texenber          #+#    #+#             */
/*   Updated: 2026/05/07 15:56:34 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philos.h"

int	join_all(t_data *data, pthread_t monitor)
{
	int64_t	i;

	i = 0;
	while (i < data->p_num)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			break ;
		i++;
	}
	if (pthread_join(monitor, NULL) != 0)
		return (1);
	return (0);
}

int	create_philo_threads(t_data *data)
{
	int64_t	i;
	int64_t	j;

	i = 0;
	while (i < data->p_num)
	{
		if (pthread_create(&data->philos[i].thread,
				NULL, routine, &data->philos[i]) != 0)
		{
			j = 0;
			while (j < i)
			{
				if (pthread_join(data->philos[j++].thread, NULL) != 0)
					break ;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data		data;
	pthread_t	monitor;

	if (parse_args(ac, av) == 1)
		return (ERR_PARSING);
	if (init_data(&data, av) == 1)
		return (ERR_INIT_MUTEX);
	data.start = get_time();
	if (init_philos(&data) == 1)
		return (ERR_INIT_PHILO);
	if (pthread_create(&monitor, NULL, monitor_r, &data) != 0)
		return (1);
	if (create_philo_threads(&data) == 1)
		return (1);
	if (join_all(&data, monitor) == 1)
		return (1);
	return (cleanup(&data), SUCCESS);
}
