/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi < abadidi@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:28:09 by abadidi           #+#    #+#             */
/*   Updated: 2021/12/11 18:28:09 by abadidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*dest;

	dest = str;
	while (n--)
	{
		*dest = (unsigned char)c;
		dest++;
	}
	return (str);
}

void	ft_bzero(void *str, size_t n)
{
	ft_memset(str, 0, n);
}

static int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	while (n--)
	{
		if (*tmp1 != *tmp2)
			return (*tmp1 - *tmp2);
		tmp1++;
		tmp2++;
	}
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*s;
	char		*d;
	size_t		i;

	if (dest == NULL && src == NULL)
		return (dest);
	if (dest == src)
		return (dest);
	if (!ft_memcmp(dest, src, n))
		return (dest);
	s = (char *)src;
	d = (char *)dest;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return ((void *)d);
}
