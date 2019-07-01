/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:16:01 by rkhokhlo          #+#    #+#             */
/*   Updated: 2019/05/21 16:16:02 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_obj		*create_sphere(char *beggin)
{
	t_obj		*obj;
	char		*pars;
	t_sphere	*sr;
	t_col		color;

	obj = NULL;
	sr = (t_sphere*)malloc(sizeof(t_sphere));
	pars = ft_strnew(300);
	pars = ft_strncpy(pars, beggin, 300);
	sr->center = find_position(pars);
	sr->rad = find_rad(pars);
	color = find_color(pars);
	obj = add_object_sphere(color, sr->center, sr->rad);
	free(pars);
	free(sr);
	return (obj);
}

t_cam		*create_camera(char *beggin)
{
	t_cam	*cam;
	char	*pars;
	int		i;

	i = 0;
	pars = ft_strnew(300);
	pars = ft_strncpy(pars, beggin, 300);
	cam = (t_cam*)malloc(sizeof(t_cam));
	cam->dir = find_to(pars);
	cam->pos = find_position(pars);
	free(pars);
	return (cam);
}

t_obj		*create_plane(char *beggin)
{
	char		*pars;
	t_obj		*obj;
	t_plane		*pl;
	t_col		col;

	obj = NULL;
	pl = (t_plane*)malloc(sizeof(t_plane));
	pars = ft_strnew(300);
	pars = ft_strncpy(pars, beggin, 300);
	col = find_color(pars);
	pl->point = find_position(pars);
	pl->normal = find_direction(pars);
	free(pars);
	obj = add_object_plane(col, pl->normal, pl->point);
	free(pl);
	return (obj);
}

t_obj		*create_cylindr(char *beggin)
{
	t_cyl	*cyl;
	t_col	col;
	char	*pars;
	t_obj	*obj;

	obj = NULL;
	cyl = (t_cyl*)malloc(sizeof(t_cyl));
	pars = ft_strnew(10000);
	pars = ft_strncpy(pars, beggin, 100);
	cyl->rad = find_rad(pars);
	cyl->normal = find_direction(pars);
	cyl->start = find_position(pars);
	col = find_color(pars);
	obj = add_object_cylind(col, cyl->start, cyl->normal, cyl->rad);
	free(pars);
	free(cyl);
	return (obj);
}

t_obj		*create_cone(char *beggin)
{
	char	*pars;
	t_obj	*obj;
	t_conus	*cone;
	t_col	col;

	obj = NULL;
	pars = ft_strnew(100);
	pars = ft_strncpy(pars, beggin, 100);
	cone = (t_conus*)malloc(sizeof(t_conus));
	cone->angle = find_angle(pars);
	cone->c = find_position(pars);
	cone->dir = find_direction(pars);
	col = find_color(pars);
	obj = add_object_conus(col, cone->c, cone->dir, cone->angle);
	free(pars);
	free(cone);
	return (obj);
}
