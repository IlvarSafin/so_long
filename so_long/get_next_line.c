/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarnacl <mbarnacl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:50:07 by mbarnacl          #+#    #+#             */
/*   Updated: 2021/11/16 19:11:50 by mbarnacl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cut(char *stat)
{
	int		i;
	int		b;
	char	*new_stat;

	i = 0;
	while (stat[i] && stat[i] != '\n')
		i++;
	if (stat[i] == '\0')
	{
		free (stat);
		return (0);
	}
	new_stat = malloc(sizeof(char) * (ft_strlen(stat) - i + 1));
	if (!new_stat)
		return (0);
	b = 0;
	i++;
	while (stat[i])
		new_stat[b++] = stat[i++];
	new_stat[b] = '\0';
	free(stat);
	return (new_stat);
}

static char	*statchar(int fd, char *stat)
{
	char	*buf;
	int		c;

	c = 1;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	while (!search_n(stat) && c != 0)
	{
		c = read(fd, buf, BUFFER_SIZE);
		if (c == -1 )
		{
			free(buf);
			return (NULL);
		}
		buf[c] = '\0';
		stat = ft_strjoin(stat, buf);
	}
	free(buf);
	return (stat);
}

char	*outstr(char *stat)
{
	int		i;
	char	*line;

	i = 0;
	if (stat[i] == '\0')
		return (0);
	while (stat[i] && stat[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	i = 0;
	while (stat[i] && stat[i] != '\n')
	{
		line[i] = stat[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*stat;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stat = statchar(fd, stat);
	if (!stat)
		return (NULL);
	line = outstr(stat);
	stat = cut(stat);
	return (line);
}
