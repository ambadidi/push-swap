/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_quater.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi < abadidi@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:05:54 by abadidi           #+#    #+#             */
/*   Updated: 2021/12/12 01:03:43 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_four_help(int index, t_stack **a, t_stack **b)
{
	if (index == 2)
	{
		print("rra\nrra\npb\n");
		revers_rotate(a);
		revers_rotate(a);
		push_from(b, a);
	}
	else
	{
		print("rra\npb\n");
		revers_rotate(a);
		push_from(b, a);
	}
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	index;
	int	small;

	small = findsmall(*a, &index);
	if (peak(*a) == small && push_from(b, a))
		print("pb\n");
	else
	{
		if (index == 1)
		{
			swap(*a);
			push_from(b, a);
			print("sa\npb\n");
		}
		else
			sort_four_help(index, a, b);
	}
	sort_three(a);
	push_from(a, b);
	print("pa\n");
}
