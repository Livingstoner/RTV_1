/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:01:50 by rkhokhlo          #+#    #+#             */
/*   Updated: 2018/10/24 16:01:51 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *memptr1, const void *memptr2, size_t num)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	int				res;

	ptr1 = (unsigned char *)memptr1;
	ptr2 = (unsigned char *)memptr2;
	i = 0;
	res = 0;
	while (i < num)
	{
		if (ptr1[i] == ptr2[i])
			i++;
		else
		{
			res = ptr1[i] - ptr2[i];
			break ;
		}
	}
	return (res);
}
