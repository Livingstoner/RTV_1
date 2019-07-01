/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_founctions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:18:39 by rkhokhlo          #+#    #+#             */
/*   Updated: 2019/05/24 13:18:40 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_col		find_color_value(char *str, int i)
{
	t_col	col;

	col.r = 0;
	col.g = 0;
	col.b = 0;
	if (ft_isdigit(str[i]) || str[i] == ' ')
	{
		col.r = ft_atoi(str + i);
		while (str[i] != ',')
			i++;
		i++;
		if (ft_isdigit(str[i]) || str[i] == ' ')
		{
			col.g = ft_atoi(str + i);
			while (str[i] != ',')
				i++;
			i++;
			if (ft_isdigit(str[i]) || str[i] == ' ')
			{
				col.b = ft_atoi(str + i);
				return (col);
			}
		}
	}
	return (col);
}

double		find_angle(char *str)
{
	double	out;
	int		i;

	i = 0;
	out = 0.4;
	while (str[i])
	{
		if ((ft_strncmp(str + i, "angle", 5)) == 0)
		{
			while (str[i] != '=')
				i++;
			if (str[i] == '=')
			{
				out = ft_atof(str + i);
				return (out);
			}
		}
		i++;
	}
	return (out);
}

t_vector	find_position(char *str)
{
	t_vector	pos;

	pos = (t_vector){0, 0, 0};
	if ((str = ft_strstr(str, "pos")))
		pos = skip_spaces(str + 4, 0);
	return (pos);
}

t_vector	find_to(char *str)
{
	t_vector	to;

	to = (t_vector){0, 0, 0};
	if ((str = ft_strstr(str, "to")))
		to = skip_spaces(str + 3, 0);
	return (to);
}

t_col		find_color(char *str)
{
	t_col	col;
	int		i;

	i = 0;
	while (str[i])
	{
		if ((ft_strncmp(str + i, "color", 5)) == 0)
		{
			i += 6;
			col = find_color_value(str, i);
			return (col);
		}
		i++;
	}
	col.b = 255;
	col.g = 255;
	col.r = 255;
	return (col);
}
