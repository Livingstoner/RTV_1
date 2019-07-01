/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 03:40:01 by rkhokhlo          #+#    #+#             */
/*   Updated: 2019/06/17 03:40:02 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		lambert(t_light *light, t_ray *ray, double t, t_vector n)
{
	t_vector	p;
	t_vector	l;

	if (!light)
		return (1);
	p = get_point(ray, t);
	l = normal(light->pos - p);
	return (fmax(0, dot(n, l)));
}

double		phong(t_light *light, t_ray *ray, double t, t_vector n)
{
	t_vector	p;
	t_vector	l;
	t_vector	h;

	if (!light)
		return (1);
	p = get_point(ray, t);
	l = normal(light->pos - p);
	h = ((l + normal(ray->pos - p)) / (t_vector){len(l + normal(ray->pos - p)),
		len(l + normal(ray->pos - p)), len(l + normal(ray->pos - p))});
	return (pow(fmax(0, dot(n, h)), 1000));
}

t_light		*add_light(t_light **list, t_light *light)
{
	t_light		*head;

	head = *list;
	light->next = NULL;
	if (*list == NULL)
	{
		*list = light;
		head = *list;
	}
	else
	{
		while ((*list)->next)
			*list = (*list)->next;
		light->next = NULL;
		(*list)->next = light;
	}
	*list = head;
	return (head);
}

double		is_shadow(t_env *env, t_ray *shadow, t_vector n)
{
	double	dist_to_obj;
	double	dist_lo_light;
	double	range;
	double	k;

	dist_to_obj = find_close(env->obj, shadow);
	dist_lo_light = len(env->light->pos - shadow->pos);
	range = dist_to_obj - dist_lo_light;
	if (dist_lo_light > dist_to_obj)
		k = 0;
	else if (range < 1e-5 && range > -1e-5)
		k = 0;
	else
		k = fmax(0, dot(shadow->dir, n)) * env->light->intensity;
	return (k);
}

int			calcul_lights(t_ray *ray, t_vector n, t_env *env)
{
	t_col		out;
	t_col		tmp;
	t_ray		shadow;
	double		k;

	out = set_color(0, 0, 0);
	shadow.pos = get_point(ray, env->dist);
	while (env->light != NULL)
	{
		shadow.dir = normal(env->light->pos - shadow.pos);
		n = dot(shadow.dir, n) > 0 ? n : -n;
		shadow.pos = get_point(&shadow, 1e-8);
		k = is_shadow(env, &shadow, n);
		tmp = add_color(multiply_color(env->color, k *
			env->light->intensity * lambert(env->light, ray, env->dist, n)),
			multiply_color(set_color(255, 255, 255), k *
			env->light->intensity * phong(env->light, ray, env->dist, n)));
		out = add_color(out, tmp);
		env->light = env->light->next;
	}
	return (rgb_to_color(out));
}
