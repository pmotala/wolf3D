/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:19:47 by pmotala           #+#    #+#             */
/*   Updated: 2018/08/16 14:24:40 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_close(void)
{
	exit(1);
	return (0);
}

int		key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 13 || keycode == 126)
		mlx->plyr.move[0] = 1;
	else if (keycode == 1 || keycode == 125)
		mlx->plyr.move[1] = 1;
	else if (keycode == 2 || keycode == 124)
		mlx->plyr.move[2] = 1;
	else if (keycode == 0 || keycode == 123)
		mlx->plyr.move[3] = 1;
	else if (keycode == 257 || keycode == 258)
		mlx->plyr.plyr_spd = 0.15f;
	else if (keycode == 53)
		exit(1);
	else if (keycode == 117)
		init_mlx(mlx);
	return (0);
}

int		key_release(int keycode, t_mlx *mlx)
{
	if (keycode == 13 || keycode == 126)
		mlx->plyr.move[0] = 0;
	else if (keycode == 1 || keycode == 125)
		mlx->plyr.move[1] = 0;
	else if (keycode == 2 || keycode == 124)
		mlx->plyr.move[2] = 0;
	else if (keycode == 0 || keycode == 123)
		mlx->plyr.move[3] = 0;
	else if (keycode == 257 || keycode == 258)
		mlx->plyr.plyr_spd = 0.09;
	return (0);
}

void	move_side(t_mlx *mlx)
{
	t_plyr		*p;
	t_camera	*c;
	double		rs;

	p = &mlx->plyr;
	c = &mlx->camera;
	rs = mlx->plyr.rot_speed;
	if (p->move[2] == 1)
	{
		p->dir.x = p->dir.x * cos(-rs) - p->dir.y * sin(-rs);
		p->dir.y = p->old_rot.x * sin(-rs) + p->dir.y * cos(-rs);
		c->old_plane.x = c->plane.x;
		c->plane.x = c->plane.x * cos(-rs) - c->plane.y * sin(-rs);
		c->plane.y = c->old_plane.x * sin(-rs) + c->plane.y * cos(-rs);
	}
	if (p->move[3] == 1)
	{
		p->dir.x = p->dir.x * cos(rs) - p->dir.y * sin(rs);
		p->dir.y = p->old_rot.x * sin(rs) + p->dir.y * cos(rs);
		c->old_plane.x = c->plane.x;
		c->plane.x = c->plane.x * cos(rs) - c->plane.y * sin(rs);
		c->plane.y = c->old_plane.x * sin(rs) + c->plane.y * cos(rs);
	}
	p->old_rot.x = p->dir.x;
}

int		move(t_mlx *mlx)
{
	t_plyr		*p;
	t_vector	*pr;
	double		ps;

	p = &mlx->plyr;
	pr = &mlx->plyr.dir;
	ps = mlx->plyr.plyr_spd;
	if (p->move[0] == 1)
	{
		if (mlx->map[(int)(p->pos.x + pr->x * ps)][(int)(p->pos.y)].z == 0)
			p->pos.x += pr->x * ps;
		if (mlx->map[(int)(p->pos.x)][(int)(p->pos.y + pr->y * ps)].z == 0)
			p->pos.y += pr->y * ps;
	}
	if (p->move[1] == 1)
	{
		if (mlx->map[(int)(p->pos.x - pr->x * ps)][(int)(p->pos.y)].z == 0)
			p->pos.x -= pr->x * ps;
		if (mlx->map[(int)(p->pos.x)][(int)(p->pos.y - pr->y * ps)].z == 0)
			p->pos.y -= pr->y * ps;
	}
	move_side(mlx);
	expose_hook(mlx);
	return (0);
}
