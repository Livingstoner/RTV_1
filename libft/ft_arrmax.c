/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 15:45:10 by rkhokhlo          #+#    #+#             */
/*   Updated: 2018/11/02 15:45:11 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrmax(int *arr, int size)
{
	int	i;
	int	max;

	i = 0;
	if (arr && size)
	{
		max = arr[0];
		i = -1;
		while (++i < size - 1)
			if (arr[i] < arr[i + 1])
				max = arr[i + 1];
		ft_putnbr(max);
		ft_putchar('\n');
	}
}
