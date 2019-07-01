/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 19:25:54 by rkhokhlo          #+#    #+#             */
/*   Updated: 2018/10/28 19:25:55 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	int		len;
	int		i;
	char	*out;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while (ft_is_space(s[len - 1]))
		len--;
	i = -1;
	while (ft_is_space(s[++i]))
		len--;
	if (len <= 0)
		len = 0;
	out = malloc(len + 1);
	if (out == NULL)
		return (NULL);
	s += i;
	i = -1;
	while (++i < len)
		out[i] = *s++;
	out[i] = '\0';
	return (out);
}
