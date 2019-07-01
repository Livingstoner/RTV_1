/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:29:03 by rkhokhlo          #+#    #+#             */
/*   Updated: 2018/10/24 13:29:04 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	const char		*str;
	char			*ds;

	i = 0;
	str = src;
	ds = dest;
	while (i < n)
	{
		ds[i] = str[i];
		i++;
	}
	return (ds);
}
