/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 01:49:00 by rkhokhlo          #+#    #+#             */
/*   Updated: 2019/06/21 01:49:01 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			is_enough_objects(char *str)
{
	int	cnt;

	cnt = 0;
	if (ft_strstr(str, "#Camera"))
	{
		ft_putendl("For clear work u need to uncomment the camera.");
		return (1);
	}
	if (ft_strstr(str, "Camera"))
		return (0);
	ft_putendl("There is no camera or bad access.");
	return (1);
}

int			check_helper(int fd, char *out)
{
	char	*str;

	if (get_next_line(fd, &str) < 1)
	{
		ft_putendl("File is empty.");
		free(out);
		return (2);
	}
	free(str);
	while (get_next_line(fd, &str) == 1)
	{
		ft_strcat(out, str);
		free(str);
	}
	if (is_enough_objects(out) == 1)
	{
		free(out);
		return (3);
	}
	free(out);
	return (0);
}

int			check_file(char *file)
{
	int		fd;
	char	*out;

	out = ft_strnew(10000);
	if ((fd = open(file, O_RDONLY)) < 0)
	{
		ft_putendl("Can not read the file.");
		free(out);
		return (1);
	}
	return (check_helper(fd, out));
}
