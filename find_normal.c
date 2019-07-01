/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 02:44:48 by rkhokhlo          #+#    #+#             */
/*   Updated: 2019/06/16 02:44:49 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	sphere_normal(t_sphere *sp)
{
	return (normal(sp->p - sp->center));
}

t_vector	cone_normal(t_conus *cone, t_ray *ray, t_vector p, double t)
{
	t_vector	m;
	t_vector	p_c;

	p_c = p - cone->c;
	m = increment_vector(cone->dir, (dot(ray->dir, cone->dir) * t +
		dot((ray->pos - cone->c), cone->dir)));
	return (normal(p_c -
		increment_vector(m, (1 + cone->angle * cone->angle))));
}

t_vector	cylinder_normal(t_cyl *cyl, t_ray *ray, t_vector p, double t)
{
	double		m;

	m = dot(ray->dir, cyl->normal) * t +
		dot(ray->pos - cyl->start, cyl->normal);
	return (normal(p - cyl->start - increment_vector(cyl->normal, m)));
}

t_vector	compute_normal(t_obj *obj, t_ray *ray, t_root *root)
{
	t_vector	n;

	n = (t_vector){0, 0, 0};
	if (obj->type == SPHERE)
		n = sphere_normal(&obj->sphere);
	else if (obj->type == CYLINDER)
		n = cylinder_normal(&obj->cylinder, ray,
		get_point(ray, find_closest(root)), find_closest(root));
	else if (obj->type == CONE)
		n = cone_normal(&obj->cone, ray,
		get_point(ray, find_closest(root)), find_closest(root));
	else if (obj->type == PLANE)
		n = obj->plane.surf_norm;
	return (n);
}
