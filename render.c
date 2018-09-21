/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:16:04 by pmotala           #+#    #+#             */
/*   Updated: 2018/08/23 09:54:22 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	render_wall(int x, int start, int end, t_mlx *mlx)
{
	t_raycast *r;

	r = &mlx->ray_c;
	r->tex_hit_id = (int)mlx->map[(int)r->rcast_map.x][(int)r->rcast_map.y].z;
	if (r->side == 0)
		mlx->draw.wall_at_ray_pos = r->raypos.y + r->walldist * r->raydir.y;
	else
		mlx->draw.wall_at_ray_pos = r->raypos.x + r->walldist * r->raydir.x;
	mlx->skybox.tex_cood.x = (int)(mlx->draw.wall_at_ray_pos * (double)(64));
	if (r->side == 0 && r->raydir.x > 0)
		mlx->skybox.tex_cood.x = 64 - mlx->skybox.tex_cood.x - 1;
	if (r->side == 1 && r->raydir.y < 0)
		mlx->skybox.tex_cood.x = 64 - mlx->skybox.tex_cood.x - 1;
	mlx->skybox.tex_cood.x = fabs(mlx->skybox.tex_cood.x);
	while (++start <= end)
		set_pixel(mlx, x, start);
}

void	render_sky(t_mlx *mlx)
{
	int		tex_cood_x;
	int		tex_cood_y;

	tex_cood_x = 0;
	while (tex_cood_x < WIDTH)
	{
		tex_cood_y = 0;
		while (tex_cood_y < HEIGHT)
		{
			ft_memcpy(mlx->rend_image.data + 4 * WIDTH * tex_cood_y +
					tex_cood_x * 4, &mlx->tex_arr[6].data[tex_cood_y *
					mlx->tex_arr[6].sizeline + tex_cood_x *
					mlx->tex_arr[6].bpp / 8], sizeof(int));
			tex_cood_y++;
		}
		tex_cood_x++;
	}
	mlx->skybox.tex_cood.x = tex_cood_x;
	mlx->skybox.tex_cood.y = tex_cood_y;
}

void	render_ground(t_mlx *mlx, int x, int ground_colour)
{
	int		y;

	ground_colour = ground_colour >> 1;
	if (mlx->ray_c.end > 0)
	{
		y = mlx->ray_c.end - 1;
		if (x < WIDTH && y < HEIGHT)
			while (++y < HEIGHT)
				ft_memcpy(mlx->rend_image.data + 4 * WIDTH * y + x * 4,
					&ground_colour, sizeof(int));
	}
}
