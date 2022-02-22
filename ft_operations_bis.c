/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi < abadidi@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:38:03 by abadidi           #+#    #+#             */
/*   Updated: 2021/12/12 01:04:35 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **s, int val)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new)
	{
		ft_bzero(new, sizeof(t_stack));
		new->val = val;
		new->next = *s;
		*s = new;
	}
}

int	pop(t_stack **s)
{
	t_stack	*tmp;
	int		val;

	if (s && *s)
	{
		tmp = *s;
		*s = (*s)->next;
		val = tmp->val;
		free(tmp);
		tmp = NULL;
		return (val);
	}
	return (0);
}

int	peak(t_stack *s)
{
	if (s)
		return (s->val);
	return (0);
}

void	swap(t_stack *s)
{
	t_stack	*second;
	int		tmp;

	if (s == NULL)
		return ;
	second = s->next;
	if (second == NULL)
		return ;
	tmp = s->val;
	s->val = second->val;
	second->val = tmp;
}

int	push_from(t_stack **a, t_stack **b)
{
	push(a, pop(b));
	return (1);
}
