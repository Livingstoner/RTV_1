/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 14:44:52 by rkhokhlo          #+#    #+#             */
/*   Updated: 2018/11/02 14:44:53 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arsort(int *arr, int size)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (arr && size)
	{
		while (i < size - 1)
		{
			while (j < size - 1 - i)
			{
				if (arr[j] > arr[j + 1])
					ft_swap(&arr[j], &arr[j + 1]);
				j++;
			}
			j = 0;
			i++;
		}
	}
}
