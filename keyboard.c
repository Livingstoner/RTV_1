/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 14:42:08 by rkhokhlo          #+#    #+#             */
/*   Updated: 2019/05/06 14:42:09 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	keys_actions(int key, void *param)
{
	t_env *env;

	env = (t_env*)param;
	(void)env;
	if (key == 53)
		exit(1);
	return (0);
}
