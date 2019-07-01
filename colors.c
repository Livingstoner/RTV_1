/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:26:44 by rkhokhlo          #+#    #+#             */
/*   Updated: 2019/04/06 14:26:45 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		rgb_to_color(t_col col)
{
	if (col.b > 255)
		col.b = 255;
	if (col.g > 255)
		col.g = 255;
	if (col.r > 255)
		col.r = 255;
	return (((int)col.r << 16) + ((int)col.g << 8) + (int)col.b);
}

t_col	set_color(int r, int g, int b)
{
	t_col col;

	col.r = r;
	col.g = g;
	col.b = b;
	return (col);
}

t_col	multiply_color(t_col col, float k)
{
	col.b = col.b * k;
	col.r = col.r * k;
	col.g = col.g * k;
	return (col);
}

t_col	add_color(t_col col, t_col col1)
{
	col.b = fmin((col.b + col1.b), 255);
	col.r = fmin((col.r + col1.r), 255);
	col.g = fmin((col.g + col1.g), 255);
	return (col);
}
