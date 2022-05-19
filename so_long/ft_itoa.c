/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarnacl <mbarnacl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:51:18 by mbarnacl          #+#    #+#             */
/*   Updated: 2022/02/24 17:46:51 by mbarnacl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*zero(void)
{
	char	*res;

	res = malloc(sizeof(char) * (2));
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

int	mas(int n, char *c, char *r)
{
	int			i;
	long long	k;

	k = n;
	i = 0;
	if (n < 0)
	{
		*r = '-';
		k *= -1;
	}
	while (k > 0)
	{
		c[i] = k % 10 + 48;
		k /= 10;
		i++;
	}
	i -= 1;
	return (i);
}

void	roo(int *j, char *r, char *res)
{
	if (*r == '-')
	{
		res[*j] = '-';
		*j += 1;
	}
}

char	*ft_itoa(int n)
{
	char		c[11];
	char		*res;
	int			i;
	int			j;
	char		r;

	j = 0;
	r = '\0';
	if (n == 0)
		return (zero());
	i = mas(n, c, &r);
	res = malloc(sizeof(char) * (i + 3));
	if (!res)
		return (NULL);
	roo(&j, &r, res);
	while (i >= 0)
	{
		res[j] = c[i];
		i--;
		j++;
	}
	res[j] = '\0';
	return (res);
}
