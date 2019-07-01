/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:28:15 by rkhokhlo          #+#    #+#             */
/*   Updated: 2018/10/30 17:28:25 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*out;
	int		len;
	int		i;

	i = 0;
	out = NULL;
	if (s)
	{
		len = ft_strlen(s);
		out = malloc(len + 1);
		if (out)
		{
			while (i < len)
			{
				out[i] = f(s[i]);
				i++;
			}
			out[i] = '\0';
		}
	}
	return (out);
}
