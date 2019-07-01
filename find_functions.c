/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 06:57:28 by rkhokhlo          #+#    #+#             */
/*   Updated: 2019/06/20 06:57:29 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	find_direction(char *str)
{
	t_vector	dir;
	int			i;

	i = 0;
	while (str[i])
	{
		if ((ft_strncmp(str + i, "dir", 3)) == 0)
		{
			i += 4;
			dir = skip_spaces(str, i);
			if (len(dir) == 0)
				dir[2] = 1;
			return (normal(dir));
		}
		i++;
	}
	return ((t_vector){0, 0, 1});
}

t_vector	skip_spaces(char *str, int i)
{
	t_vector	out;

	if (ft_isdigit(str[i]) || str[i] == '-' || str[i] == ' ')
	{
		out[0] = ft_atof(str + i);
		while (str[i] != ',')
			i++;
		i++;
		if (ft_isdigit(str[i]) || str[i] == '-' || str[i] == ' ')
		{
			out[1] = ft_atof(str + i);
			while (str[i] != ',')
				i++;
			i++;
			if (ft_isdigit(str[i]) || str[i] == '-' || str[i] == ' ')
			{
				out[2] = ft_atof(str + i);
				return (out);
			}
		}
	}
	return ((t_vector){0, 0, 0});
}

double		find_rad(char *str)
{
	double	r;
	int		i;

	i = 0;
	r = 1.0;
	if ((str = ft_strstr(str, "rad")))
	{
		while (str[i] && (str[i] != '='))
			i++;
		r = fabs(ft_atof(str + i + 1));
	}
	return (r);
}

t_root		find_roots(double a, double b, double c)
{
	double	dis;
	t_root	root;

	root.x1 = -1;
	root.x2 = -1;
	dis = b * b - 4 * a * c;
	if (dis < 0)
		return (root);
	root.x1 = (-b + sqrt(dis)) / (2 * a);
	root.x2 = (-b - sqrt(dis)) / (2 * a);
	return (root);
}

double		find_closest(t_root *root)
{
	if ((root->x1 <= root->x2 && root->x1 >= 0)
		|| (root->x1 >= 0 && root->x2 < 0))
		return (root->x1);
	if ((root->x2 <= root->x1 && root->x2 >= 0)
		|| (root->x2 >= 0 && root->x1 < 0))
		return (root->x2);
	return (-1);
}
