/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmotala <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 12:35:36 by pmotala           #+#    #+#             */
/*   Updated: 2018/08/16 14:25:45 by pmotala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init(t_mlx *mlx)
{
	if (ft_read(mlx) == -1)
	{
		ft_putendl("ERROR DURING READ");
		return ;
	}
	init_mlx(mlx);
}

int		main(int argc, char **argv)
{
	t_mlx mlx;

	if (argc == 2)
	{
		mlx.name = argv[1];
		mlx.fd = open(mlx.name, O_RDONLY);
		init(&mlx);
	}
	else
		ft_putendl("NEEDS A SINGLE MAP FILE");
	return (0);
}
