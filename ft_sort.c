/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi <abadidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:17:51 by abadidi           #+#    #+#             */
/*   Updated: 2021/12/12 03:32:06 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_help(t_stack **a, t_stack **b, int i)
{
	int	num;

	num = peak(*a);
	if (((num >> i) & 1) == 1)
	{
		print("ra\n");
		rotate_stack(a);
	}
	else
	{
		print("pb\n");
		push_from(b, a);
	}
}

void	sort(t_stack **a, t_stack **b, int size)
{
	t_sort_vars	v;

	v.maxnum = size;
	v.maxbit = 0;
	while ((v.maxnum >> v.maxbit) != 0)
		++v.maxbit;
	v.i = 0;
	while (v.i < v.maxbit)
	{
		v.j = 0;
		while (v.j < size)
		{
			sort_help(a, b, v.i);
			v.j++;
		}
		v.k = stack_size(*b);
		while (v.k)
		{
			push_from(a, b);
			print("pa\n");
			v.k--;
		}
		v.i++;
	}
}

void	sort_five_help(t_stack **a, t_stack **b, t_sort_five_vars	v, int i)
{
	v.small = findsmall(*a, &v.index);
	if (v.index == 0)
	{
		print("pb\n");
		push_from(b, a);
	}
	else if (v.index > (v.size - i) / 2)
	{
		while (peak(*a) != v.small && print("rra\n"))
			revers_rotate(a);
		print("pb\n");
		push_from(b, a);
	}
	else
	{
		while (peak(*a) != v.small && print("ra\n"))
			rotate_stack(a);
		print("pb\n");
		push_from(b, a);
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	int					i;
	t_sort_five_vars	v;

	i = 0;
	v.size = 5;
	v.index = 0;
	while (i < 2)
	{
		sort_five_help(a, b, v, i);
		i++;
	}
	sort_three(a);
	push_from(a, b);
	push_from(a, b);
	print("pa\npa\n");
}
