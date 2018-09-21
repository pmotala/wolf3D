/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 12:36:22 by pmotala           #+#    #+#             */
/*   Updated: 2018/08/16 15:14:18 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdint.h>
# include "libft/libft.h"

# define WIDTH 1000
# define HEIGHT 800
# define SKY_SIZE 596

typedef struct	s_readinfo
{
	int			rows;
	int			cols;
}				t_readinfo;

typedef struct	s_image
{
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
}				t_image;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_plyr
{
	int			move[4];
	double		plyr_spd;
	double		rot_speed;
	t_vector	pos;
	t_vector	dir;
	t_vector	old_rot;
}				t_plyr;

typedef struct	s_draw
{
	int			line_h;
	double		wall_at_ray_pos;
}				t_draw;

typedef struct	s_skybox
{
	t_vector	tex_cood;
}				t_skybox;

typedef struct	s_raycast
{
	t_vector	rcast_map;
	int			start;
	int			end;
	int			tex_hit_id;
	t_vector	delta_dist;
	t_vector	raydir;
	t_vector	steps;
	t_vector	side_dist;
	t_vector	raypos;
	int			side;
	int			hit;
	double		walldist;
}				t_raycast;

typedef struct	s_camera
{
	t_vector	plane;
	t_vector	old_plane;
}				t_camera;

typedef struct	s_mlx
{
	char		*name;
	int			fd;
	void		*win;
	void		*mlx;
	t_readinfo	read;
	t_camera	camera;
	t_image		tex_arr[9];
	t_image		rend_image;
	t_draw		draw;
	t_vector	**map;
	t_plyr		plyr;
	t_raycast	ray_c;
	t_skybox	skybox;
}				t_mlx;

void			render_sky(t_mlx *t);
void			render_ground(t_mlx *t, int x, int ground_colour);
void			render_wall(int x, int start, int end, t_mlx *t);
void			set_pixel(t_mlx *t, int x, int y);

int				key_press(int keycode, t_mlx *t);
int				key_release(int keycode, t_mlx *t);
void			move_side(t_mlx *t);
int				move(t_mlx *t);

void			init_textures(t_mlx *mlx);
void			load_texture(t_mlx *mlx, char *path, int size_sqrd, int i);

int				ft_close(void);

void			ray_casting(t_mlx *t);
void			ray_cast_init(t_mlx *t, int x);
void			dda_cast(t_mlx *t);
void			dda_init(t_mlx *t);

void			init_mlx(t_mlx *mlx);

int				ft_read(t_mlx *mlx);
int				ft_alloc_tab(t_mlx *mlx);
int				ft_col_row(t_mlx *mlx, char *line);

void			init_img(t_mlx *mlx);
int				expose_hook(t_mlx *mlx);

#endif
