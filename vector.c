/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 01:23:22 by rkhokhlo          #+#    #+#             */
/*   Updated: 2019/06/16 01:23:23 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		len(t_vector a)
{
	return (sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]));
}

t_vector	increment_vector(t_vector a, double x)
{
	return ((t_vector){a[0] * x, a[1] * x, a[2] * x});
}

double		dot(t_vector a, t_vector b)
{
	return (a[0] * b[0] + a[1] * b[1] + a[2] * b[2]);
}

t_vector	get_point(t_ray *ray, double t)
{
	return (ray->pos + increment_vector(ray->dir, t));
}

t_vector	cross_product(t_vector a, t_vector b)
{
	t_vector out;

	out[0] = a[1] * b[2] - a[2] * b[1];
	out[1] = a[2] * b[0] - a[0] * b[2];
	out[2] = a[0] * b[1] - a[1] * b[0];
	return (out);
}
