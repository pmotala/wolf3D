/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:17:20 by pmotala           #+#    #+#             */
/*   Updated: 2018/08/16 14:35:11 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			ft_col_row(t_mlx *mlx, char *line)
{
	int		x;
	char	**tab;

	x = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[x])
	{
		free(tab[x]);
		x++;
	}
	if (mlx->read.rows == 0)
		mlx->read.cols = x;
	else
	{
		if (x != mlx->read.cols)
			return (-1);
	}
	free(line);
	free(tab);
	mlx->read.rows++;
	return (0);
}

int			ft_alloc_tab(t_mlx *mlx)
{
	char	*line;
	int		ret;

	line = NULL;
	mlx->read.rows = 0;
	mlx->read.cols = 0;
	while ((ret = get_next_line(mlx->fd, &line)) > 0)
	{
		if (ft_col_row(mlx, line) == -1)
			return (-1);
	}
	mlx->map = ft_memalloc(sizeof(t_vector*) * mlx->read.rows);
	close(mlx->fd);
	mlx->fd = open(mlx->name, O_RDONLY);
	return (0);
}

int			ft_read(t_mlx *mlx)
{
	char	*line;
	char	**tab;
	int		xytab[3];

	xytab[1] = 0;
	if (ft_alloc_tab(mlx) == -1)
		return (-1);
	while ((xytab[2] = get_next_line(mlx->fd, &line)) > 0)
	{
		xytab[0] = 0;
		tab = ft_strsplit(line, ' ');
		mlx->map[xytab[1]] = ft_memalloc(sizeof(t_vector) * mlx->read.cols);
		while (tab[xytab[0]] != NULL)
		{
			mlx->map[xytab[1]][xytab[0]].x = (double)xytab[0];
			mlx->map[xytab[1]][xytab[0]].y = (double)xytab[1];
			mlx->map[xytab[1]][xytab[0]].z = (double)ft_atoi(tab[xytab[0]]);
			free(tab[xytab[0]]);
			xytab[0]++;
		}
		free(tab);
		free(line);
		xytab[1]++;
	}
	return ((xytab[2] == -1) ? -1 : 0);
}
