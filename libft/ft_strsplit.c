/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 20:18:58 by rkhokhlo          #+#    #+#             */
/*   Updated: 2018/10/28 20:19:00 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_a_char(char c, char a)
{
	if (c == a)
		return (1);
	return (0);
}

static int	ft_cntwrd(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (is_a_char(s[i], c) && !is_a_char(s[i + 1], c))
			count++;
		i++;
	}
	if (s[0] != '\0')
		count++;
	return (count);
}

static char	*ft_setword(char const *s, char c, int *i)
{
	char	*out;
	int		j;

	out = NULL;
	j = 0;
	if (s)
	{
		if (!(out = (char *)malloc(sizeof(out) * ft_strlen(s))))
			return (NULL);
		while (!is_a_char(s[*i], c) && s[*i])
		{
			out[j] = s[*i];
			(*i)++;
			j++;
		}
		out[j] = '\0';
		while (s[*i] == c && s[*i])
			(*i)++;
	}
	return (out);
}

char		**ft_strsplit(char const *s, char c)
{
	int		count_wrd;
	int		i;
	int		j;
	char	**out;

	i = 0;
	j = 0;
	out = NULL;
	if (!s || !c)
		return (NULL);
	count_wrd = ft_cntwrd(s, c);
	if (!(out = (char **)malloc(sizeof(out) * count_wrd + 2)))
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (j < count_wrd && s[i])
	{
		out[j] = ft_setword(s, c, &i);
		j++;
	}
	out[j] = NULL;
	return (out);
}
