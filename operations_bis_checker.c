/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bis_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi <abadidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:36:21 by abadidi           #+#    #+#             */
/*   Updated: 2022/02/22 21:36:22 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stack **s)
{
	t_stack	*tmp;

	tmp = *s;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = *s;
	*s = (*s)->next;
	tmp->next->next = NULL;
}

void	revers_rotate(t_stack **s)
{
	t_stack	*last;
	t_stack	*before_last;

	last = *s;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	last->next = *s;
	*s = last;
	before_last->next = NULL;
}

int	stack_size(t_stack *s)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = s;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	checkduplicated(int *t, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (t[i] == t[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
