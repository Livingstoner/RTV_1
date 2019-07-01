/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:22:07 by rkhokhlo          #+#    #+#             */
/*   Updated: 2019/05/24 13:22:40 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	help_atof(char *s, double div, int mult, double res)
{
	int		i;

	i = 0;
	while (s[i] && (s[i] != '.'))
		i++;
	i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (res * mult);
		div *= 10.0;
		res += (double)(s[i] - '0') / div;
		s++;
	}
	return (res * mult);
}

double	ft_atof(char *s)
{
	double	res;
	int		mult;
	double	div;
	int		full_int;

	res = 0.0;
	mult = 1;
	div = 1.0;
	full_int = 0;
	if (!s)
		return (res);
	full_int = abs(ft_atoi(s));
	res = (double)full_int;
	if (ft_strnstr(s, "-", 5))
		mult = -1;
	return (help_atof(s, div, mult, res));
}
