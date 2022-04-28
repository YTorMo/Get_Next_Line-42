/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 09:53:16 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/04/28 09:23:32 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	char	*occur;

	if (s)
	{
		while (*s != '\0')
		{
			if ((char)*s == (char)c)
			{
				occur = (char *)s;
				return (occur);
			}
			s++;
		}
		if (c == 0)
			return (occur = (char *)s);
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	char	*memo;
	size_t	len;
	size_t	len_memo;

	if (!s1)
	{
		s1 = malloc(1);
		*s1 = 0;
	}
	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join || !s1 || !s2)
		return (NULL);
	memo = join;
	len = ft_strlen(s1);
	len_memo = len;
	while (len--)
		*memo++ = *s1++;
	s1 -= len_memo;
	len = ft_strlen(s2);
	while (len--)
		*memo++ = *s2++;
	*memo = 0;
	free(s1);
	return (join);
}
