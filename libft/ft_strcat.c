/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:08:03 by rkhokhlo          #+#    #+#             */
/*   Updated: 2018/10/24 17:08:05 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *destptr, const char *srcptr)
{
	size_t len;
	size_t i;

	i = 0;
	len = ft_strlen(destptr);
	while (srcptr[i] != '\0')
	{
		destptr[len + i] = srcptr[i];
		i++;
	}
	destptr[len + i] = '\0';
	return (destptr);
}
