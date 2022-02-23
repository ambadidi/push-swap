/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi < abadidi@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:57:36 by abadidi           #+#    #+#             */
/*   Updated: 2022/02/23 09:42:36 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check1(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

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
		exit(0);
	}
	while (i < argc)
	{
		if (check(argv[i]) == 0 || check1(argv[i]) == 0)
		{
			print("Error\n");
			exit(1);
		}
		i++;
	}
}

void	free_tabs(int *a, int *b)
{
	free(a);
	free(b);
}

void	free_stack(t_stack *s)
{
	t_stack	*temp;
	t_stack	*tofree;

	temp = s;
	while (temp)
	{
		tofree = temp;
		temp = temp->next;
		free(tofree);
	}
}
