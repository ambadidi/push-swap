/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi < abadidi@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:47:54 by abadidi           #+#    #+#             */
/*   Updated: 2021/12/11 21:48:04 by abadidi          ###   ########.fr       */
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

int	findsmall(t_stack *a, int *index)
{
	int		min;
	int		i;
	t_stack	*s;

	min = 0XFFFFFFF;
	s = a;
	*index = 0;
	i = 0;
	while (s)
	{
		if (min > s->val)
		{
			min = s->val;
			*index = i;
		}
		s = s->next;
		i++;
	}
	return (min);
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
