/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:46:06 by rkhokhlo          #+#    #+#             */
/*   Updated: 2018/10/24 16:46:07 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *destptr, const char *srcptr)
{
	int		i;
	char	*dst;

	i = 0;
	dst = (char *)destptr;
	while (srcptr[i])
	{
		dst[i] = srcptr[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
