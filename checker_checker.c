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

char	*ft_strdup(char *str)
{
	char	*dest;
	int		i;

	i = 0;
	if (!str || !str[0])
		return (NULL);
	while (str[i])
		i++;
	dest = (char *)malloc(i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	char	buff;
	int		n;
	char	h[600000];
	int		i;

	i = 0;
	if (fd < 0)
		return (NULL);
	n = read(fd, &buff, 1);
	while (n && n > 0)
	{
		if (buff == '\n' || !buff)
			break ;
		h[i++] = buff;
		n = read(fd, &buff, 1);
	}
	h[i] = '\0';
	if (n <= 0 && i == 0)
		return (NULL);
	return (ft_strdup(h));
}

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

void	main_help_checker1(char *str, t_stack **a, t_stack **b)
{
	 if (strcmp(str, "rra") == 0)
		revers_rotate(a);
	else if (strcmp(str, "rrb") == 0)
		revers_rotate(b);
	else if (strcmp(str, "rrr") == 0)
	{
		revers_rotate(a);
		revers_rotate(b);
	}
	else if (strcmp(str, "rr") == 0)
	{
		rotate_stack(a);
		rotate_stack(b);
	}
	else if (strcmp(str, "ss") == 0)
	{
		swap(*a);
		swap(*b);
	}
	else
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}


int	main_help_checker(char *str, t_stack **a, t_stack **b)
{
	if (strcmp(str, "pa") == 0)
		return push_from(a, b);
	else if (strcmp(str, "pb") == 0)
		return	push_from(b, a);
	else if (strcmp(str, "sa") == 0)
	{
		 swap(*a);
		return 1;
	}
	else if (strcmp(str, "sb") == 0)
	{
		swap(*b);
		return 1;
	}
	else if (strcmp(str, "ra") == 0)
	{
		rotate_stack(a);
		return 1;
	}
	else if (strcmp(str, "rb") == 0)
	{
		rotate_stack(b);
		return 1;
	}
	main_help_checker1(str, a, b);
	return 1;
}

void fill_tab(int *tab, t_stack **a , int argc, char **argv)
{
	int i = 0;

	*a = NULL;
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


int	main(int argc, char **argv)
{
	int			i;
	t_stack		*a;
	t_stack		*b;
	char		*str;
	int			*tab;

	i = 0;
	b = NULL;
	tab = (int *)malloc(sizeof(int) * argc);
	gobal_check(argc, argv);
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
	{
		 write(1, "KO\n", 3);
	}else
	write(1, "OK\n", 3);
	free_stack(a);
	free_stack(b);
}
