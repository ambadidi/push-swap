/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi <abadidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:06:13 by abadidi           #+#    #+#             */
/*   Updated: 2022/02/22 21:06:13 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkisnotsorted(int *t, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (t[i] > t[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_stackissorted(t_stack *s)
{
	t_stack	*temp;
	t_stack	*temp1;

	temp = s;
	temp1 = s->next;
	while (temp)
	{
		if (temp1 == NULL)
			break ;
		if (temp->val > temp1->val)
		{
			return (0);
		}
		temp = temp->next;
		temp1 = temp1->next;
	}
	return (1);
}

int	main_help_checker1(char *str, t_stack **a, t_stack **b)
{
	if (ft_strcmp(str, "rra") == 0)
		revers_rotate(a);
	else if (ft_strcmp(str, "rrb") == 0)
		revers_rotate(b);
	else if (ft_strcmp(str, "rrr") == 0)
	{
		revers_rotate(a);
		revers_rotate(b);
	}
	else if (ft_strcmp(str, "rr") == 0)
	{
		rotate_stack(a);
		rotate_stack(b);
	}
	else if (ft_strcmp(str, "ss") == 0)
	{
		swap(*a);
		swap(*b);
	}
	else
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	return (0);
}

int	main_help_checker(char *str, t_stack **a, t_stack **b)
{
	if (ft_strcmp(str, "pa") == 0)
		return (push_from(a, b));
	else if (ft_strcmp(str, "pb") == 0)
		return (push_from(b, a));
	else if (ft_strcmp(str, "sa") == 0)
	{
		swap(*a);
		return (1);
	}
	else if (ft_strcmp(str, "sb") == 0)
	{
		swap(*b);
		return (1);
	}
	else if (ft_strcmp(str, "ra") == 0)
	{
		rotate_stack(a);
		return (1);
	}
	else if (ft_strcmp(str, "rb") == 0)
	{
		rotate_stack(b);
		return (1);
	}
	return (main_help_checker1(str, a, b));
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	char		*str;
	int			*tab;

	b = NULL;
	tab = (int *)malloc(sizeof(int) * argc);
	fill_tab(tab, &a, argc, argv);
	if (checkisnotsorted(tab, argc - 1) == 0)
		return (write(1, "Error\n", 6));
	if (checkduplicated(tab, argc - 1) == 1)
		return (write(1, "Error\n", 6));
	str = get_next_line(0);
	while (str != NULL)
	{		
		main_help_checker(str, &a, &b);
		free(str);
		str = get_next_line(0);
	}
	if (stack_size(b) != 0 || check_stackissorted(a) == 0)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free_stack(a);
	free_stack(b);
}
