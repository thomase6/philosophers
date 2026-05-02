/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 14:31:29 by texenber          #+#    #+#             */
/*   Updated: 2026/05/02 14:45:14 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philos.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_isdigit(int i)
{
	if (i >= 48 && i <= 57)
		return (1);
	return (0);
}

// TODO: long long protection for this atoi
int	ft_atoi(const char *str)
{
	int	i;
	int	sum;
	int	sign;

	i = 0;
	sum = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 43)
		i++;
	else if (str[i] == 45)
	{
		sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		sum = ((sum * 10) + (str[i] - 48));
		i++;
	}
	return (sum * sign);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write (fd, s, ft_strlen(s));
}