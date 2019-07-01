/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:32:29 by rkhokhlo          #+#    #+#             */
/*   Updated: 2018/10/24 17:32:30 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len_dst;
	size_t len_src;

	len_src = 0;
	len_dst = 0;
	while (dst[len_dst] && len_dst < size)
		len_dst++;
	while (src[len_src] && (len_src + len_dst + 1) < size)
	{
		dst[len_dst + len_src] = src[len_src];
		len_src++;
	}
	if (len_dst + len_src < size)
		dst[len_src + len_dst] = '\0';
	return (len_dst + ft_strlen(src));
}
