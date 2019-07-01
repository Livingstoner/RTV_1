/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:02:50 by rkhokhlo          #+#    #+#             */
/*   Updated: 2019/05/07 15:02:52 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_obj	*add_object_to_list(t_obj **full, t_obj *part)
{
	t_obj	*head;

	head = *full;
	if (*full == NULL)
	{
		*full = part;
		head = *full;
	}
	else
	{
		while ((*full)->next)
			*full = (*full)->next;
		part->next = NULL;
		(*full)->next = part;
	}
	*full = head;
	return (*full);
}

t_obj	*add_object_cylind(t_col col, t_vector start, t_vector norm, double rad)
{
	t_obj	*obj;
	t_cyl	cyl;

	if ((obj = (t_obj *)malloc(sizeof(t_obj))) != NULL)
	{
		cyl.rad = rad;
		cyl.start = start;
		cyl.normal = norm;
		obj->color = col;
		obj->cylinder = cyl;
		obj->type = 3;
		obj->next = NULL;
	}
	return (obj);
}

t_obj	*add_object_conus(t_col col, t_vector c, t_vector dir, double angle)
{
	t_obj	*obj;
	t_conus	con;

	if ((obj = (t_obj *)malloc(sizeof(t_obj))) != NULL)
	{
		con.c = c;
		con.dir = dir;
		con.surface_normal = (t_vector){0, 0, 0};
		con.angle = angle;
		obj->color = col;
		obj->cone = con;
		obj->type = 2;
		obj->next = NULL;
	}
	return (obj);
}

t_obj	*add_object_sphere(t_col col, t_vector cent, double rad)
{
	t_obj		*obj;
	t_sphere	sphere;

	if ((obj = (t_obj *)malloc(sizeof(t_obj))) != NULL)
	{
		sphere.rad = rad;
		sphere.center = cent;
		sphere.shadow_point = (t_vector){-1000, -1000, -1000};
		obj->color = col;
		obj->sphere = sphere;
		obj->type = 1;
		obj->next = NULL;
	}
	return (obj);
}

t_obj	*add_object_plane(t_col col, t_vector normal, t_vector point)
{
	t_obj	*obj;
	t_plane	plane;

	obj = (t_obj *)malloc(sizeof(t_obj));
	plane.normal = normal;
	plane.point = point;
	obj->color = col;
	obj->type = 4;
	obj->plane = plane;
	obj->next = NULL;
	return (obj);
}
