/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi < abadidi@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:49:07 by abadidi           #+#    #+#             */
/*   Updated: 2021/12/11 18:49:07 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_stack
{
	int				val;
	struct s_stack	*next;
}				t_stack;

typedef struct s_sort_vars
{
	int		maxnum;
	int		maxbit;
	int		i;
	int		j;
	int		k;
}				t_sort_vars;

typedef struct s_sort_five_vars
{
	int	index;
	int	size;
	int	small;
}				t_sort_five_vars;

typedef struct s_sort_three_vars
{
	int	val0;
	int	val1;
	int	val2;
}				t_sort_three_vars;

typedef struct s_vars
{
	int		i;
	int		j;
}				t_vars;

typedef struct s_main_vars
{
	int		*tab;
	int		*copy;
	t_stack	*b;
	t_stack	*a;
	t_vars	v;
}				t_main_vars;

int			check1(char *str);
void		bubblesort(int *arr, int n);
long long	ft_atoi(char const *s);
int			ft_isdigit(int c);
void		ft_bzero(void *str, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		push(t_stack **s, int val);
int			pop(t_stack **s);
int			peak(t_stack *s);
void		swap(t_stack *s);
void		print_stack_a(t_stack *s);
int			print(char *str);
void		help_main(int argc, t_main_vars c);
void		help_help_main(int argc, t_main_vars c);
void		help_main_bis(int argc, t_main_vars c);
void		help_main_tiers(int argc, char **argv, t_main_vars c);
void		help_main_quater(int argc, t_main_vars	c);
void		help_main_quinquies(int argc, t_main_vars	c);
int			check(char *str);
void		gobal_check(int argc, char **argv);
void		free_tabs(int *a, int *b);
void		free_stack(t_stack *s);
void		push(t_stack **s, int val);
int			pop(t_stack **s);
int			peak(t_stack *s);
void		swap(t_stack *s);
int			push_from(t_stack **a, t_stack **b);
int			checkisnotsorted(int *t, int size);
int			checkduplicated(int *t, int size);
void		sort_five(t_stack **a, t_stack **b);
void		sort_four_help(int index, t_stack **a, t_stack **b);
void		sort_four(t_stack **a, t_stack **b);
void		sort_three_help(t_sort_three_vars	v, t_stack **a);
void		sort_three(t_stack **a);
void		sort_tow(void);
void		sort(t_stack **a, t_stack **b, int size);
void		rotate_stack(t_stack **s);
void		revers_rotate(t_stack **s);
int			findsmall(t_stack *a, int *index);
int			stack_size(t_stack *s);
#endif