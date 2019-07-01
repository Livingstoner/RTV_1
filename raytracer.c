/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 22:59:46 by rkhokhlo          #+#    #+#             */
/*   Updated: 2019/06/15 22:59:47 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		find_close(t_obj *obj, t_ray *ray)
{
	double	min;
	double	t;

	t = 0;
	min = MAXFLOAT;
	while (obj)
	{
		t = intersect(obj, ray);
		if (t > 0.0001 && t < min)
			min = t;
		obj = obj->next;
	}
	return (min);
}

int			castray(t_obj *obj, t_ray *ray, t_light *light)
{
	double		t;
	t_env		env;
	t_vector	n;

	env.obj = obj;
	env.dist = MAXFLOAT;
	while (obj)
	{
		t = intersect(obj, ray);
		if (t > 0.001 && t < env.dist)
		{
			env.dist = t;
			env.color = obj->color;
			n = obj->n;
		}
		obj = obj->next;
	}
	if (env.dist == MAXFLOAT || env.dist < 0)
		return (rgb_to_color(BACKGROUND));
	env.light = light;
	return (calcul_lights(ray, n, &env));
}

t_vector	look_at(double u, double v, t_env *env)
{
	t_vector k;
	t_vector i;
	t_vector j;

	k = normal(env->cam->dir - env->cam->pos);
	i = cross_product(k, (t_vector){0.0, 1.0, 0.0});
	i = normal(i);
	j = cross_product(i, k);
	return (normal((t_vector){u * i[0] + v * j[0] + 2.0 * k[0],
							u * i[1] + v * j[1] + 2.0 * k[1],
							u * i[2] + v * j[2] + 2.0 * k[2]}));
}

void		raycast(int x, int y, t_env *env, t_ray *ray)
{
	double	u;
	double	v;
	int		color;

	u = (2 * (x + 0.5) / (double)WIDTH - 1) * SCALE;
	v = (1 - 2 * (y + 0.5) / (double)HEIGHT) * SCALE * 1
		/ (WIDTH / (double)HEIGHT);
	ray->dir = look_at(u, v, env);
	color = castray(env->obj, ray, env->light);
	put_img_pix(env->con->img_ptr, color, x, y);
}

void		raytrace(t_env *env)
{
	t_ray		ray;
	uint32_t	x;
	uint32_t	y;

	y = -1;
	ray.pos = env->cam->pos;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			raycast(x, y, env, &ray);
	}
	mlx_put_image_to_window(env->con->mlx_ptr, env->con->win_ptr,
		env->con->img_ptr, 0, 0);
}
