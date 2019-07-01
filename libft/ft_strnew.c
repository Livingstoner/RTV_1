/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 16:48:06 by rkhokhlo          #+#    #+#             */
/*   Updated: 2018/10/28 16:48:07 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *out;

	out = ft_memalloc(size + 1);
	if (out == NULL)
		return (NULL);
	out = ft_memset(out, '\0', size + 1);
	return (out);
}
