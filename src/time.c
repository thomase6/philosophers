/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 09:13:32 by texenber          #+#    #+#             */
/*   Updated: 2026/05/06 09:25:27 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philos.h"

int64_t	get_time(void)
{
	struct	timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		ft_putstr_fd(GET_TIME_ERR, 2);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_sleep(int64_t ms, t_data *data)
{
	int64_t start;

	start = get_time();
	while ((get_time() - start) < ms)
	{
		if(is_dead(data))
			break;
		usleep(100);
	}
}
