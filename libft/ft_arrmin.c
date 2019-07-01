/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:03:02 by rkhokhlo          #+#    #+#             */
/*   Updated: 2018/11/02 16:03:03 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrmin(int *arr, int size)
{
	int i;
	int min;

	i = 0;
	if (arr && size)
	{
		min = arr[0];
		i = -1;
		while (++i < size - 1)
			if (arr[i] > arr[i + 1])
				min = arr[i + 1];
		ft_putnbr(min);
		ft_putchar('\n');
	}
}
