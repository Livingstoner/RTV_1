/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 22:59:56 by rkhokhlo          #+#    #+#             */
/*   Updated: 2019/06/15 23:00:18 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	*create_image(void *mlx_ptr)
{
	void	*img_ptr;

	img_ptr = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	return (img_ptr);
}

void	put_img_pix(void *img_ptr, int color, int x, int y)
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		*pix_arr;

	if (img_ptr)
	{
		pix_arr = (int *)mlx_get_data_addr(img_ptr,
		&bits_per_pixel, &size_line, &endian);
		pix_arr[y * WIDTH + x] = color;
	}
}

t_con	init_window(void)
{
	t_con	con;

	con.mlx_ptr = mlx_init();
	con.win_ptr = mlx_new_window(con.mlx_ptr, WIDTH, HEIGHT, "My Rtv1");
	con.img_ptr = create_image(con.mlx_ptr);
	return (con);
}
