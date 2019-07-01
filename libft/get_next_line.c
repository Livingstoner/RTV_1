/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:12:08 by rkhokhlo          #+#    #+#             */
/*   Updated: 2018/11/16 15:09:23 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strucpy(char **dst, char *src, char c)
{
	int			i;
	int			j;
	char		*tmp;

	tmp = ft_strnew(ft_strlen(src) + 1);
	i = 0;
	while (tmp[i] && *dst[i])
	{
		tmp[i] = *dst[i];
		i++;
	}
	j = 0;
	while (src[j] && src[j] != c)
	{
		tmp[i] = src[j];
		i++;
		j++;
	}
	*dst = tmp;
	return (i);
}

int			write_line(char **tmp, int fd, char **line)
{
	size_t	len;
	char	*temp;

	len = ft_strucpy(line, tmp[fd], '\n');
	if (len < ft_strlen(tmp[fd]))
	{
		temp = ft_strdup(tmp[fd] + len + 1);
		free(tmp[fd]);
		tmp[fd] = temp;
	}
	else
		ft_strdel(&tmp[fd]);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	static char	*tmp[OPEN_MAX];
	char		*sd;

	ret = 0;
	if (read(fd, buf, 0) < 0 || fd < 0 || line == NULL)
		return (-1);
	if (!tmp[fd])
		tmp[fd] = ft_strnew(1);
	if (!ft_strchr(tmp[fd], '\n'))
	{
		while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		{
			buf[ret] = '\0';
			sd = ft_strjoin(tmp[fd], buf);
			free(tmp[fd]);
			tmp[fd] = sd;
			if (ft_strchr(buf, '\n'))
				break ;
		}
	}
	if (ret == 0 && (tmp[fd] == NULL || tmp[fd][0] == '\0'))
		return (0);
	return (write_line(tmp, fd, line));
}
