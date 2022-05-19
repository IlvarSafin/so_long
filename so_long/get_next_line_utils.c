/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarnacl <mbarnacl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:18:17 by mbarnacl          #+#    #+#             */
/*   Updated: 2021/11/11 19:44:05 by mbarnacl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*search_n(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\n')
	{
		if (!s[i])
			return (0);
		++i;
	}
	return ((char *)&s[i]);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*t;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	t = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!t)
		return (0);
	j = 0;
	i = 0;
	while (s1[j])
		t[i++] = s1[j++];
	j = 0;
	while (s2[j])
		t[i++] = s2[j++];
	t[i] = '\0';
	free(s1);
	return (t);
}
