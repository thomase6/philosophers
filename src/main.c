/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 15:20:39 by texenber          #+#    #+#             */
/*   Updated: 2026/05/06 09:17:36 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philos.h"

int	main(int ac, char **av)
{
	t_data		data;
	pthread_t	monitor;
	int64_t		i;
	
	if (parse_args(ac, av) == 1)
		return (ERR_PARSING);
	if (init_data(&data, av) == 1)
		return (ERR_INIT_MUTEX);
	if (init_philos(&data) == 1)
		return (ERR_INIT_PHILO);
	i = 0;
	data.start = get_time();
	while (i < data.p_num)
	{
		data.philos[i].last_meal = data.start;
		i++;
	}
	i = 0;
	if(pthread_create(&monitor, NULL, monitor_r, &data))
		return (1);
	while (i < data.p_num)
	{
		if (pthread_create(&data.philos[i].thread, NULL, routine, &data.philos[i]))
			return (cleanup(&data), 1);
		i++;
	}
	pthread_join(monitor, NULL);
	i = 0;
	while (i < data.p_num)
	{
		pthread_join(data.philos[i].thread, NULL);
		i++;
	}
	cleanup(&data);
	return (SUCCESS);
}

//haven't handled single philos

