/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:55:55 by rkhokhlo          #+#    #+#             */
/*   Updated: 2018/10/24 16:55:56 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *destptr, const char *srcptr, size_t n)
{
	size_t			i;
	unsigned char	*out;
	unsigned char	*in;

	in = (unsigned char *)srcptr;
	out = (unsigned char *)destptr;
	i = 0;
	while (i < n && in[i])
	{
		out[i] = in[i];
		i++;
	}
	if (ft_strlen(srcptr) < n)
		while (i < n)
		{
			out[i] = '\0';
			i++;
		}
	return (destptr);
}
