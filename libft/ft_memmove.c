/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:25:06 by rkhokhlo          #+#    #+#             */
/*   Updated: 2018/10/24 15:25:07 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*out;

	i = 0;
	out = dest;
	str = (unsigned char *)src;
	if (src < dest)
		while (n-- > 0)
			out[n] = str[n];
	else
		while (i < n)
		{
			out[i] = str[i];
			i++;
		}
	return (dest);
}
