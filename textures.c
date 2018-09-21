/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:28:33 by pmotala           #+#    #+#             */
/*   Updated: 2018/08/16 15:07:48 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	load_texture(t_mlx *mlx, char *path, int size_sqrd, int i)
{
	mlx->tex_arr[i].img = mlx_xpm_file_to_image(mlx->mlx, path,
							&size_sqrd, &size_sqrd);
	mlx->tex_arr[i].data = mlx_get_data_addr(mlx->tex_arr[i].img,
							&mlx->tex_arr[i].bpp,
							&mlx->tex_arr[i].sizeline,
							&mlx->tex_arr[i].endian);
}

void	init_textures(t_mlx *mlx)
{
	int			tex_size;
	int			skybox_tex_size;

	tex_size = 64;
	skybox_tex_size = SKY_SIZE;
	load_texture(mlx, "textures/wood.xpm", tex_size, 0);
	load_texture(mlx, "textures/colorstone.xpm", tex_size, 1);
	load_texture(mlx, "textures/mossy.xpm", tex_size, 2);
	load_texture(mlx, "textures/redbrick.xpm", tex_size, 3);
	load_texture(mlx, "textures/greystone.xpm", tex_size, 4);
	load_texture(mlx, "textures/eagle.xpm", tex_size, 5);
	load_texture(mlx, "textures/sky.xpm", skybox_tex_size, 6);
}
