/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 15:32:06 by rkhokhlo          #+#    #+#             */
/*   Updated: 2018/11/02 15:32:07 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putarr(int *arr, int size)
{
	int i;

	i = 0;
	if (arr && size)
	{
		while (i < size)
		{
			ft_putnbr(arr[i]);
			ft_putchar(' ');
			i++;
		}
	}
}
