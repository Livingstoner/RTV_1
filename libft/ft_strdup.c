/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:34:22 by rkhokhlo          #+#    #+#             */
/*   Updated: 2018/10/24 16:34:23 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*out;
	int		i;

	i = 0;
	out = NULL;
	out = (char *)malloc(ft_strlen(str) + 1);
	if (out)
	{
		while (str[i] != '\0')
		{
			out[i] = str[i];
			i++;
		}
		out[i] = '\0';
		return (out);
	}
	else
		return (0);
}
