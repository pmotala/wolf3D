/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 12:13:26 by pmotala           #+#    #+#             */
/*   Updated: 2018/08/20 15:12:22 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	set_pixel(t_mlx *mlx, int x, int y)
{
	const void	*colour;
	int			ptr_color;

	if (x < WIDTH && y < HEIGHT)
	{
		mlx->skybox.tex_cood.y = abs((((y * 256 - HEIGHT * 128 +
								mlx->draw.line_h * 128) * 64) /
								mlx->draw.line_h) / 256);
		colour = &(mlx->tex_arr[mlx->ray_c.tex_hit_id].data[
					(int)mlx->skybox.tex_cood.y % 64 *
					mlx->tex_arr[mlx->ray_c.tex_hit_id].sizeline +
					(int)mlx->skybox.tex_cood.x % 64 *
					mlx->tex_arr[mlx->ray_c.tex_hit_id].bpp / 8]);
		ptr_color = *(int *)colour;
		if (mlx->ray_c.side == 1)
			ptr_color = (ptr_color >> 1);
		ft_memcpy(mlx->rend_image.data + 4 * WIDTH * y + x * 4,
				&ptr_color, sizeof(int));
	}
}

void	init_img(t_mlx *mlx)
{
	t_image *ri;

	ri = &mlx->rend_image;
	if (!(ri->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT)))
		return ;
	ri->data = mlx_get_data_addr(ri->img, &ri->bpp,
								&ri->sizeline, &ri->endian);
}
