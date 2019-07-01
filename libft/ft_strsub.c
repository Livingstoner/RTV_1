/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 18:42:58 by rkhokhlo          #+#    #+#             */
/*   Updated: 2018/10/28 18:43:01 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;

	i = 0;
	out = NULL;
	if (s)
	{
		out = malloc(len + 1);
		if (out)
		{
			while (i < len && s[start])
			{
				out[i] = s[start];
				i++;
				start++;
			}
			out[i] = '\0';
		}
	}
	return (out);
}
