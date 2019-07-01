/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 23:31:47 by rkhokhlo          #+#    #+#             */
/*   Updated: 2019/06/15 23:31:48 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	make_exit(t_env *env)
{
	(void)env;
	exit(1);
	return (0);
}

int	main(int ac, char **av)
{
	t_con	con;
	t_env	env;
	t_light *light;

	light = NULL;
	if (ac != 2)
	{
		ft_putendl("usage: ./rtv [file] ");
		return (0);
	}
	if (!(check_file(av[1]) == 0))
		return (0);
	con = init_window();
	env.con = &con;
	env.light = light;
	env = *get_mat_file(av[1], &env);
	raytrace(&env);
	mlx_key_hook(con.win_ptr, keys_actions, &env);
	mlx_hook(con.win_ptr, 17, 1L << 17, make_exit, &env);
	mlx_loop(con.mlx_ptr);
	return (0);
}
