/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi < abadidi@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:04:48 by abadidi           #+#    #+#             */
/*   Updated: 2021/12/11 17:04:48 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	help_main(int argc, t_main_vars c)
{
	help_help_main(argc, c);
	if (argc == 3)
	{
		sort_tow();
		free_tabs(c.tab, c.copy);
		exit (0);
	}
	if (argc == 6)
	{
		sort_five(&(c.a), &(c.b));
		free_tabs(c.tab, c.copy);
		free_stack((c.a));
		exit (0);
	}
	if (argc == 5)
	{
		sort_four(&(c.a), &(c.b));
		free_tabs(c.tab, c.copy);
		free_stack(c.a);
		exit (0);
	}
}

void	help_main_bis(int argc, t_main_vars c)
{
	while (c.v.i < argc)
	{
		c.v.j = 0;
		while (c.v.j < argc)
		{
			if (c.tab[c.v.i] == c.copy[c.v.j])
			{
				c.tab[c.v.i] = c.v.j;
				break ;
			}
			c.v.j++;
		}
		c.v.i++;
	}
}

void	help_main_tiers(int argc, char **argv, t_main_vars c)
{
	while (c.v.i < argc)
	{
		c.tab[c.v.i - 1] = ft_atoi(argv[c.v.i]);
		c.v.i++;
	}
	if (checkduplicated(c.tab, argc - 1) == 1)
	{
		print("Error\n");
		free_tabs(c.tab, c.copy);
		exit (1);
	}
	if (checkisnotsorted(c.tab, argc - 1) == 0)
	{
		free_tabs(c.tab, c.copy);
		exit (1);
	}
}

void	help_main_quater(int argc, t_main_vars	c)
{
	if (argc <= 6)
	{
		c.v.i = argc - 2;
		while (c.v.i >= 0)
		{
			push(&(c.a), c.tab[c.v.i]);
			c.v.i--;
		}
		help_main(argc, c);
	}
}

int	main(int argc, char **argv)
{
	t_main_vars	c;

	c.a = NULL;
	c.b = NULL;
	c.v.i = 1;
	gobal_check(argc, argv);
	if (argc > 2)
	{
		c.tab = malloc(sizeof(int) * argc);
		c.copy = malloc(sizeof(int) * argc);
		help_main_tiers(argc, argv, c);
		help_main_quater(argc, c);
		ft_memcpy(c.copy, c.tab, (argc - 1) * sizeof(int));
		bubblesort(c.copy, argc - 1);
		c.v.i = 0;
		help_main_bis(argc, c);
		c.v.i = argc - 2;
		help_main_quinquies(argc, c);
	}
}
