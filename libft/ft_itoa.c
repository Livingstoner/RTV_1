/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 19:44:44 by rkhokhlo          #+#    #+#             */
/*   Updated: 2018/10/29 19:44:45 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbrlen(long n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		i += 1;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int		ft_costil(long n, char *out)
{
	if (n == -0)
	{
		out[0] = '0';
		out[1] = '\0';
		return (1);
	}
	return (0);
}

void			ft_costil2(long n, int *len)
{
	if (n == 0)
		*len = 2;
}

char			*ft_itoa(int n)
{
	char	*out;
	int		len;
	int		i;
	long	k;

	k = (long)n;
	i = 0;
	len = ft_nbrlen(k) + 1;
	ft_costil2(n, &len);
	if (!(out = (char*)malloc(sizeof(char) * (len))))
		return (NULL);
	if (ft_costil(k, out))
		return (out);
	if (k < 0)
	{
		out[0] = '-';
		k *= -1;
	}
	out[--len] = '\0';
	while (k > 0)
	{
		out[--len] = k % 10 + '0';
		k /= 10;
	}
	return (out);
}
