/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 19:23:40 by rkhokhlo          #+#    #+#             */
/*   Updated: 2018/11/16 14:22:55 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	size_t	len;
	size_t	len1;
	size_t	len2;
	size_t	i;

	out = NULL;
	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		len = len1 + len2 + 1;
		if ((out = malloc(sizeof(char) * len)) == NULL)
			return (NULL);
		i = -1;
		while (++i < len1)
			out[i] = s1[i];
		len = i;
		i = -1;
		while (++i < len2)
			out[len++] = s2[i];
		out[len] = '\0';
	}
	return (out);
}
