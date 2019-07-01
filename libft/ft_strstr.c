/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 18:45:56 by rkhokhlo          #+#    #+#             */
/*   Updated: 2018/10/25 11:50:54 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	temp;
	size_t	len;

	i = 0;
	temp = 0;
	len = 0;
	while (s2[len] != '\0')
		len++;
	if (len == 0)
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		while (s2[temp] == s1[i + temp])
		{
			if (temp == len - 1)
				return ((char *)s1 + i);
			temp++;
		}
		temp = 0;
		i++;
	}
	return (0);
}
