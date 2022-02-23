/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_help_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadidi < abadidi@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:35:55 by abadidi           #+#    #+#             */
/*   Updated: 2022/02/23 10:10:42 by abadidi          ###   ########.fr       */
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

int	ft_strcmp(const char *s1, const char *s2)
{
	while ((*s1 || *s2) && (s1 && s2))
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
			return ((unsigned char)*s1 - (unsigned char)*s2);
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
