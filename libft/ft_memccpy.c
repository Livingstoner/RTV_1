/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:12:57 by rkhokhlo          #+#    #+#             */
/*   Updated: 2018/10/24 15:12:58 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	char			*ds;

	i = 0;
	str = (unsigned char *)src;
	ds = dest;
	while (i < n)
	{
		ds[i] = str[i];
		if (str[i] == (unsigned char)c)
			return (&ds[i + 1]);
		i++;
	}
	return (NULL);
}
