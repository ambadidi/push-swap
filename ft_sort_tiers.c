/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi < abadidi@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:47:30 by abadidi           #+#    #+#             */
/*   Updated: 2021/12/12 01:17:53 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_help(t_sort_three_vars	v, t_stack **a)
{
	if (v.val0 > v.val1 && v.val1 < v.val2 && v.val0 > v.val2)
	{
		rotate_stack(a);
		print("ra\n");
	}
	else if (v.val0 < v.val1 && v.val0 < v.val2 && v.val1 > v.val2)
	{
		swap(*a);
		rotate_stack(a);
		print("sa\nra\n");
	}
	else if (v.val2 < v.val1 && v.val1 > v.val0)
	{
		revers_rotate(a);
		print("rra\n");
	}
}

void	sort_three(t_stack **a)
{
	t_sort_three_vars	v;

	v.val0 = (*a)->val;
	v.val1 = (*a)->next->val;
	v.val2 = (*a)->next->next->val;
	if (v.val0 > v.val1 && v.val1 < v.val2 && v.val0 < v.val2)
	{
		swap(*a);
		print("sa\n");
	}
	else if (v.val0 > v.val1 && v.val1 > v.val2)
	{
		swap(*a);
		revers_rotate(a);
		print("sa\nrra\n");
	}
	else
		sort_three_help(v, a);
}

void	sort_tow(void)
{
	print("sa\n");
}
