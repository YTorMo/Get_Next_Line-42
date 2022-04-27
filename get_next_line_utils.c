/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 09:53:16 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/04/27 17:50:13 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*char	*ft_strchr(const char *s, int c)
{
	char	*occur;

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
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	char	*memo;
	size_t	len;

	join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2));
	if (!join || !s1 || !s2)
		return (NULL);
	memo = join;
	len = ft_strlen(s1);
	while (len--)
	{
		*memo = *s1;
		memo++;
		s1++;
	}
	len = ft_strlen(s2);
	while (len--)
	{
		*memo = *s2;
		memo++;
		s2++;
	}
	*memo = 0;
	return (join);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}*/


size_t	ft_strlen(char *s)
{
	/*size_t	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\0')
		c++;
	return (c);*/
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
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
	/*char	*occur;

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
	return (NULL);*/
}

char	*ft_strjoin(char *s1, char *s2)
{
	/*size_t	i;
	size_t	c;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[c] != '\0')
		str[i++] = s2[c++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);*/
	char	*join;
	char	*memo;
	size_t	len;

	join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2));
	if (!join || !s1 || !s2)
		return (NULL);
	memo = join;
	len = ft_strlen(s1);
	while (len--)
	{
		*memo = *s1;
		memo++;
		s1++;
	}
	len = ft_strlen(s2);
	while (len--)
	{
		*memo = *s2;
		memo++;
		s2++;
	}
	*memo = 0;
	free(s1);
	return (join);
}
