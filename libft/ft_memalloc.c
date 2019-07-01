/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 16:42:40 by rkhokhlo          #+#    #+#             */
/*   Updated: 2018/10/28 16:42:43 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *out;

	if ((out = malloc(size)) == NULL)
		return (NULL);
	ft_bzero(out, size);
	return (out);
}
