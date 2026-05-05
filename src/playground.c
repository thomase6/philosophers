/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playground.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 08:46:46 by texenber          #+#    #+#             */
/*   Updated: 2026/05/04 16:28:15 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philos.h"

void *routine(void *philo_id)
{
	int64_t	*philoid = (int64_t *) philo_id;
	printf("thread of philo number: %ld\n", *philoid);
	sleep (3);
	printf("ENDING THREAD OF PHILO NUMBER: %ld\n", *philoid);
	return NULL;
}

int	main(int ac, char **av)
{
	pthread_t t1, t2;
	int64_t	philo_id = 0;
	int64_t	philo_id1 = 1;

	if (pthread_create(&t1, NULL, routine, (void *) &philo_id) != 0)
		return (1);
	if (pthread_create(&t2, NULL, routine, (void *) &philo_id1) != 0)
		return (2);
	
	if (pthread_join(t1, NULL) != 0)
		return (3);
	if (pthread_join(t2, NULL) != 0)
		return (4);
	return 0;	
}