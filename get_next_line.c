/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytoro-mo <ytoro-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 09:51:47 by ytoro-mo          #+#    #+#             */
/*   Updated: 2022/04/28 09:25:50 by ytoro-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_all_lines(int fd, char *all_txt);
char	*ft_get_line(char *all_txt);
char	*ft_new_previous_line(char	*all_txt);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*all_txt;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	all_txt = ft_get_all_lines(fd, all_txt);
	if (!all_txt)
		return (NULL);
	line = ft_get_line(all_txt);
	all_txt = ft_new_previous_line(all_txt);
	return (line);
}

char	*ft_get_all_lines(int fd, char *all_txt)
{
	char	*nxt_line;
	int		rd;

	nxt_line = malloc(BUFFER_SIZE + 1);
	if (!nxt_line)
		return (NULL);
	rd = 1;
	while (!ft_strchr(all_txt, '\n') && rd)
	{
		rd = read(fd, nxt_line, BUFFER_SIZE);
		if (rd == -1)
		{
			free(nxt_line);
			return (NULL);
		}
		nxt_line[rd] = 0;
		all_txt = ft_strjoin(all_txt, nxt_line);
	}
	free(nxt_line);
	return (all_txt);
}

char	*ft_get_line(char *all_txt)
{
	char	*memo_line;
	int		i;

	i = 0;
	if (!all_txt[i])
		return (NULL);
	while (all_txt[i] && all_txt[i] != '\n')
		i++;
	memo_line = malloc(i + 1 + 1);
	if (!memo_line)
		return (NULL);
	while (all_txt[i] && all_txt[i] != '\n')
	{
		memo_line[i] = all_txt[i];
		i++;
	}
	if (all_txt[i] == '\n')
		memo_line[i++] = '\n';
	memo_line[i] = 0;
	return (memo_line);
}
//malloc(i + 1 + 1) == malloc(i + '\n' + '\0')

char	*ft_new_previous_line(char	*all_txt)
{
	char	*previous;
	int		i;
	int		j;

	i = 0;
	while (all_txt[i] && all_txt[i] != '\n')
		i++;
	if (!all_txt[i])
	{
		free(all_txt);
		return (NULL);
	}
	previous = malloc(ft_strlen(all_txt) - i + 1);
	if (!previous)
		return (NULL);
	i++;
	j = 0;
	while (all_txt[i])
		previous[j++] = all_txt[i++];
	previous[j] = 0;
	free(all_txt);
	return (previous);
}

/*char	*ft_get_line(char *save)
{
	int		i;
	char	*s;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		s[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		s[i] = save[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_save(char *save)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (save[i])
		s[c++] = save[i++];
	s[c] = '\0';
	free(save);
	return (s);
}

char	*ft_read_and_save(int fd, char *save)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(save, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);
}
*/