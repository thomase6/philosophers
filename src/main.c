/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 15:20:39 by texenber          #+#    #+#             */
/*   Updated: 2026/05/02 14:57:38 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philos.h"

void	init_data(t_data data)
{
	data.p_num = 0;
	data.time_to_d = 0;
	data.time_to_e = 0;
	data.time_to_s = 0;
	data.num_of_meals = 0;
	data.start = 0;
	data.death_flag = 0;
	// data.forks; // INITIALIZE
	// data.death_mutex; // INITIALIZE
	// data.print_mutex; // INITIALIZE
}

int	main(int ac, char **av)
{
	t_data *data;

	if (ac != 5 && ac != 6)
		return (ft_putstr_fd(TOO_MANY_ARGS, 2), 1);
	
	// init_data(data);
}































// void *routine(void *philo_id)
// {
// 	int64_t	*philoid = (int64_t *) philo_id;
// 	printf("thread of philo number: %ld\n", *philoid);
// 	sleep (3);
// 	printf("ENDING THREAD OF PHILO NUMBER: %ld\n", *philoid);
// 	return NULL;
// }

// int	main(int ac, char **av)
// {
// 	pthread_t t1, t2;
// 	int64_t	philo_id = 0;
// 	int64_t	philo_id1 = 1;

// 	if (pthread_create(&t1, NULL, routine, (void *) &philo_id) != 0)
// 		return (1);
// 	if (pthread_create(&t2, NULL, routine, (void *) &philo_id1) != 0)
// 		return (2);
	
// 	if (pthread_join(t1, NULL) != 0)
// 		return (3);
// 	if (pthread_join(t2, NULL) != 0)
// 		return (4);
// 	return 0;	
// }