/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:06:43 by pmotala           #+#    #+#             */
/*   Updated: 2018/08/16 14:02:17 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		expose_hook(t_mlx *mlx)
{
	ray_casting(mlx);
	return (0);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Wolf3D");
	mlx->plyr.pos.x = 3;
	mlx->plyr.pos.y = 3;
	mlx->plyr.plyr_spd = 0.09;
	mlx->plyr.move[0] = 0;
	mlx->plyr.move[1] = 0;
	mlx->plyr.move[2] = 0;
	mlx->plyr.move[3] = 0;
	mlx->plyr.dir.x = -1;
	mlx->plyr.dir.y = 0;
	mlx->plyr.rot_speed = 0.09;
	mlx->camera.plane.x = 0;
	mlx->camera.plane.y = 0.66f;
	mlx->skybox.tex_cood.x = 0;
	mlx->skybox.tex_cood.y = 0;
	init_textures(mlx);
	mlx_hook(mlx->win, 17, 0L, ft_close, mlx);
	mlx_hook(mlx->win, 2, 0, &key_press, mlx);
	mlx_hook(mlx->win, 3, 0, &key_release, mlx);
	mlx_expose_hook(mlx->win, expose_hook, mlx);
	mlx_loop_hook(mlx->mlx, move, mlx);
	mlx_loop(mlx->mlx);
}
