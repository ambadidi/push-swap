/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_help_bis_checker.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi < abadidi@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:35:55 by abadidi           #+#    #+#             */
/*   Updated: 2022/02/23 10:03:39 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_tab(int *tab, t_stack **a, int argc, char **argv)
{
	int	i;

	i = 0;
	*a = NULL;
	gobal_check(argc, argv);
	while (++i < argc)
		tab[i - 1] = ft_atoi(argv[i]);
	while (--i)
		push(a, tab[i - 1]);
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
