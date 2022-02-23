/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi < abadidi@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:20:32 by abadidi           #+#    #+#             */
/*   Updated: 2021/12/11 18:20:32 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	swaper(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void	bubblesort(int *arr, int n)
{
	int	i;
	int	j;
	int	swapped;

	i = 0;
	while (i < n - 1)
	{
		swapped = 0;
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				swaper(&arr[j], &arr[j + 1]);
				swapped = 1;
			}
			j++;
		}
		if (swapped == 0)
			break ;
		i++;
	}
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static int	ft_iswhitespace(int c)
{
	if (c == '\t' || c == '\r' || c == '\n'
		|| c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

long long	ft_atoi(char const *s)
{
	long long			nbr;
	long				sign;
	int					i;

	i = 0;
	sign = 1;
	nbr = 0;
	while (ft_iswhitespace((int)s[i]) && s[i])
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
		{
			sign = -1;
			nbr = -nbr;
		}
		i++;
	}
	while (ft_isdigit(s[i]) && s[i])
		nbr = nbr * 10 + (s[i++] - 48);
	return (nbr * sign);
}
