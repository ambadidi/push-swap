/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi < abadidi@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:35:55 by abadidi           #+#    #+#             */
/*   Updated: 2022/02/23 09:42:36 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check(char *str)
{
	int			i;
	int			size;
	long long	atoi;

	i = 0;
	while (str[i])
	{
		if ((str[i] != '-' && str[i] != '+') && ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	size = ft_strlen(str);
	if (size > 11)
		return (0);
	atoi = ft_atoi(str);
	if (atoi > 2147483647 || atoi < -2147483648)
		return (0);
	return (1);
}

void	gobal_check(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	while (i < argc)
	{
		if (check(argv[i]) == 0)
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}
