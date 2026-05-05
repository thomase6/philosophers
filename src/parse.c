/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 09:34:13 by texenber          #+#    #+#             */
/*   Updated: 2026/05/04 14:28:20 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philos.h"

int	is_overflow(char *str)
{
	size_t	len;
	char	*tmp;

	tmp = str;
	while (*tmp == '0')
		tmp++;
	if (*tmp == '\0')
		return (0);
	len = ft_strlen(tmp);
	if (len > 10)
		return (1);
	if (len == 10 && ft_strcmp(tmp, "2147483647") > 0)
		return (1);
	return (0);
}

int	overflow_check(char **av)
{
	size_t	i;

	i = 1;
	while (av[i] != NULL)
	{
		if (is_overflow(av[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	digit_check(char **av)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (av[i] != NULL)
	{
		j = 0;
		if (av[i][j] == '\0')
			return (1);
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	valid_args(char **av)
{
	if (digit_check(av) == 1)
		return (1);
	if (overflow_check(av) == 1)
		return (1);
	return (0);
}

int	parse_args(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (ft_putstr_fd(TOO_MANY_ARGS, 2), 1);
	if (valid_args(av) == 1)
		return (ft_putstr_fd(INVALID_ARGS, 2), 1);
	return (0);
}