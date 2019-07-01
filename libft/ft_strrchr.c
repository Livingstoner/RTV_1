/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 18:39:11 by rkhokhlo          #+#    #+#             */
/*   Updated: 2018/10/24 18:39:12 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;
	int		tmp;
	int		len;

	i = 0;
	tmp = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] != (char)c)
			i++;
		else
		{
			tmp = i;
			i++;
		}
	}
	ptr = (char *)s + tmp;
	if (s[tmp] == (char)c)
		return (ptr);
	else
		return (NULL);
}
