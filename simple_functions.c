/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_founctions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 01:45:56 by rkhokhlo          #+#    #+#             */
/*   Updated: 2019/06/16 01:45:57 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		deg2rad(double deg)
{
	return (deg * PI / 180);
}

t_vector	normal(t_vector a)
{
	double length;

	length = len(a);
	length = 1 / length;
	a[0] *= length;
	a[1] *= length;
	a[2] *= length;
	return (a);
}
