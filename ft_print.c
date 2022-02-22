/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi < abadidi@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:13:58 by abadidi           #+#    #+#             */
/*   Updated: 2021/12/12 00:57:01 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	return (1);
}

void	help_main_quinquies(int argc, t_main_vars	c)
{
	while (c.v.i >= 0)
	{
		push(&(c.a), c.tab[c.v.i]);
		c.v.i--;
	}
	sort(&(c.a), &(c.b), argc -1);
	free_tabs(c.tab, c.copy);
	free_stack(c.a);
}

void	help_help_main(int argc, t_main_vars c)
{
	if (argc == 4)
	{
		sort_three(&(c.a));
		free_tabs(c.tab, c.copy);
		free_stack(c.a);
		exit (0);
	}
}
