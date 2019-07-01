/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:53:20 by rkhokhlo          #+#    #+#             */
/*   Updated: 2019/05/21 12:53:22 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_env		*get_mat_file(char *file, t_env *env)
{
	int		fd;
	char	*str;
	char	*out;

	fd = open(file, O_RDONLY);
	out = ft_strnew(10000);
	while (get_next_line(fd, &str) == 1)
	{
		ft_strcat(out, str);
		free(str);
	}
	env = parse(out, env);
	return (env);
}

t_light		*create_light(char *beggin)
{
	char	*pars;
	t_light	*light;
	char	*intensiv;

	pars = ft_strnew(100);
	pars = ft_strncpy(pars, beggin, 100);
	light = (t_light*)malloc(sizeof(t_light));
	light->next = NULL;
	light->pos = find_position(pars);
	if ((intensiv = ft_strstr(pars, "intense")))
		light->intensity = ft_atof(intensiv + 7);
	else
		light->intensity = 1;
	free(pars);
	return (light);
}

int			help_to_pars(char *str, t_env *env, int i)
{
	char	*beggin;

	if ((ft_strncmp(str + i, "Cone", 4)) == 0)
	{
		beggin = str + i;
		add_object_to_list(&env->obj, create_cone(beggin));
	}
	else if ((ft_strncmp(str + i, "Sphere", 6)) == 0)
	{
		beggin = str + i;
		add_object_to_list(&env->obj, create_sphere(beggin));
	}
	else if ((ft_strncmp(str + i, "#", 1)) == 0)
	{
		while (str[i] != '}')
			i++;
	}
	else if ((ft_strncmp(str + i, "Cylindr", 7)) == 0)
	{
		beggin = ft_strstr(str + i, "Cylindr");
		add_object_to_list(&env->obj, create_cylindr(beggin));
	}
	return (i);
}

int			help_to_par(char *str, int i, t_env *env)
{
	char *beggin;

	beggin = NULL;
	if ((ft_strncmp(str + i, "Plane", 5)) == 0)
	{
		beggin = str + i;
		add_object_to_list(&env->obj, create_plane(beggin));
	}
	else if ((ft_strncmp(str + i, "Camera", 6)) == 0)
	{
		beggin = str + i;
		env->cam = create_camera(beggin);
	}
	else if ((ft_strncmp(str + i, "Light", 5)) == 0)
	{
		beggin = str + i;
		add_light(&env->light, create_light(beggin));
	}
	return (i);
}

t_env		*parse(char *str, t_env *env)
{
	int		i;

	i = -1;
	env->obj = NULL;
	env->light = NULL;
	while (str[++i])
	{
		i = help_to_par(str, i, env);
		i = help_to_pars(str, env, i);
	}
	free(str);
	return (env);
}
