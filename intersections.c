/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 02:45:48 by rkhokhlo          #+#    #+#             */
/*   Updated: 2019/06/16 02:45:49 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	intersect(t_obj *obj, t_ray *ray)
{
	t_root			root;

	if (obj->type == SPHERE)
	{
		root = intersect_sphere(&obj->sphere, ray);
		obj->sphere.p = get_point(ray, find_closest(&root));
	}
	else if (obj->type == CYLINDER)
		root = intersect_cylinder(&obj->cylinder, ray);
	else if (obj->type == CONE)
		root = intersect_cone(&obj->cone, ray);
	else if (obj->type == PLANE)
	{
		obj->n = obj->plane.surf_norm;
		return (intersect_plane(&obj->plane, ray));
	}
	obj->n = compute_normal(obj, ray, &root);
	return (find_closest(&root));
}

double	intersect_plane(t_plane *pl, t_ray *ray)
{
	t_vector	ray_to_point;
	float		ray_norm_to_plane_norm;
	float		x_v;
	double		dist;

	ray_norm_to_plane_norm = dot(ray->dir, pl->normal);
	if (ray_norm_to_plane_norm != 0)
	{
		ray_to_point = ray->pos - pl->point;
		x_v = dot(ray_to_point, pl->normal);
		dist = -x_v / ray_norm_to_plane_norm;
		if (ray_norm_to_plane_norm > 0.00001)
			pl->surf_norm = pl->normal;
		else
			pl->surf_norm = -pl->normal;
		if (dist >= 0)
			return (dist);
	}
	return (MAXFLOAT);
}

t_root	intersect_cylinder(t_cyl *cyl, t_ray *ray)
{
	double		a;
	double		b;
	double		c;
	t_vector	x;

	x = ray->pos - cyl->start;
	a = dot(ray->dir, ray->dir) - pow(dot(ray->dir, cyl->normal), 2);
	b = 2.0 * (dot(ray->dir, x) -
		dot(ray->dir, cyl->normal) * dot(x, cyl->normal));
	c = dot(x, x) - pow(dot(x, cyl->normal), 2) - cyl->rad * cyl->rad;
	return (find_roots(a, b, c));
}

t_root	intersect_cone(t_conus *cone, t_ray *ray)
{
	double		a;
	double		b;
	double		c;
	t_vector	x;

	x = ray->pos - cone->c;
	a = dot(ray->dir, ray->dir) - (1 + pow(tan(cone->angle), 2))
		* pow(dot(ray->dir, cone->dir), 2);
	b = 2.0 * (dot(ray->dir, x) - (1 + pow(tan(cone->angle), 2))
		* dot(ray->dir, cone->dir) * dot(x, cone->dir));
	c = dot(x, x) - (1 + pow(tan(cone->angle), 2)) * pow(dot(x, cone->dir), 2);
	return (find_roots(a, b, c));
}

t_root	intersect_sphere(t_sphere *sph, t_ray *ray)
{
	double		a;
	double		b;
	double		c;
	t_vector	x;

	x = ray->pos - sph->center;
	a = dot(ray->dir, ray->dir);
	b = 2.0 * dot(ray->dir, x);
	c = dot(x, x) - sph->rad * sph->rad;
	return (find_roots(a, b, c));
}
