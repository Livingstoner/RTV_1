/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:22:51 by rkhokhlo          #+#    #+#             */
/*   Updated: 2018/10/24 17:22:53 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *destptr, const char *srcptr, size_t num)
{
	size_t len;
	size_t i;

	i = 0;
	len = ft_strlen(destptr);
	while (srcptr[i] != '\0' && i < num)
	{
		destptr[len + i] = srcptr[i];
		i++;
	}
	destptr[len + i] = '\0';
	return (destptr);
}
