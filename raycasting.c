/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:21:08 by pmotala           #+#    #+#             */
/*   Updated: 2018/08/23 09:53:25 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	dda_init(t_mlx *mlx)
{
	t_raycast	*r;

	r = &mlx->ray_c;
	r->delta_dist.x = fabs(1 / r->raydir.x);
	r->delta_dist.y = fabs(1 / r->raydir.y);
	if (r->raydir.x < 0)
	{
		r->steps.x = -1;
		r->side_dist.x = (r->raypos.x - r->rcast_map.x) * r->delta_dist.x;
	}
	else
	{
		r->steps.x = 1;
		r->side_dist.x = (r->rcast_map.x + 1.0 - r->raypos.x) * r->delta_dist.x;
	}
	if (r->raydir.y < 0)
	{
		r->steps.y = -1;
		r->side_dist.y = (r->raypos.y - r->rcast_map.y) * r->delta_dist.y;
	}
	else
	{
		r->steps.y = 1;
		r->side_dist.y = (r->rcast_map.y + 1.0 - r->raypos.y) * r->delta_dist.y;
	}
}

void	dda_cast(t_mlx *mlx)
{
	t_raycast	*r;

	r = &mlx->ray_c;
	r->hit = 0;
	while (r->hit == 0)
	{
		if (r->side_dist.x < r->side_dist.y)
		{
			r->side_dist.x += r->delta_dist.x;
			r->rcast_map.x += r->steps.x;
			r->side = 0;
		}
		else
		{
			r->side_dist.y += r->delta_dist.y;
			r->rcast_map.y += r->steps.y;
			r->side = 1;
		}
		if (mlx->map[(int)r->rcast_map.x][(int)r->rcast_map.y].z > 0)
			r->hit = 1;
	}
}

void	ray_cast_init(t_mlx *mlx, int x)
{
	double		camera_plane_x;
	t_raycast	*r;

	r = &mlx->ray_c;
	camera_plane_x = 2 * x / (double)(WIDTH) - 1;
	r->raypos.x = mlx->plyr.pos.x;
	r->raypos.y = mlx->plyr.pos.y;
	r->raydir.x = mlx->plyr.dir.x + mlx->camera.plane.x * camera_plane_x;
	r->raydir.y = mlx->plyr.dir.y + mlx->camera.plane.y * camera_plane_x;
	r->rcast_map.x = (int)r->raypos.x;
	r->rcast_map.y = (int)r->raypos.y;
	dda_init(mlx);
	dda_cast(mlx);
	if (r->side == 0)
		r->walldist = (r->rcast_map.x - r->raypos.x +
				(1 - r->steps.x) / 2) / r->raydir.x;
	else
		r->walldist = (r->rcast_map.y - r->raypos.y +
				(1 - r->steps.y) / 2) / r->raydir.y;
}

void	ray_casting(t_mlx *mlx)
{
	int			x;

	x = -1;
	init_img(mlx);
	render_sky(mlx);
	while (++x < WIDTH)
	{
		ray_cast_init(mlx, x);
		mlx->draw.line_h = (int)(HEIGHT / mlx->ray_c.walldist);
		mlx->ray_c.start = -mlx->draw.line_h / 2 + HEIGHT / 2;
		if (mlx->ray_c.start < 0)
			mlx->ray_c.start = 0;
		mlx->ray_c.end = mlx->draw.line_h / 2 + HEIGHT / 2;
		if (mlx->ray_c.end >= HEIGHT)
			mlx->ray_c.end = HEIGHT - 1;
		render_ground(mlx, x, 0x808080);
		render_wall(x, mlx->ray_c.start - 1, mlx->ray_c.end, mlx);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->rend_image.img, 0, 0);
	mlx_destroy_image(mlx->mlx, mlx->rend_image.img);
}
