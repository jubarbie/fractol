/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:19:58 by jubarbie          #+#    #+#             */
/*   Updated: 2016/05/14 16:15:30 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "mlx.h"
#include "fractol.h"

void		init_pos(t_param *param)
{
	POSX = 0;
	POSY = 0;
	X1 = -2.1;
	X2 = 0.6;
	Y1 = -1.2;
	Y2 = 1.2;
	ZOOM = 400;
	ITER = 20;
	X = 0;
	Y = 0;
	if (!ft_strcmp(NAME, "julia"))
	{
		ITER = 100;
		X1 = -1;
		X2 = 1;
		Y1 = -1.2;
		Y2 = 1.2;
	}
}

t_param		*init_param(int size_x, int size_y, char opt, char *name)
{
	t_param	*param;

	if (!(param = (t_param *)malloc(sizeof(t_param))))
		exit(EXIT_FAILURE);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, size_x, size_y, name);
	WIN_X = size_x;
	WIN_Y = size_y;
	BPP = 24;
	SIZELINE = WIDTH * (BPP / 8);
	ENDIAN = 0;
	NAME = name;
	init_pos(param);
	COLOR = 255 / ITER << 0;
	OPT = opt;
	WIDTH = WIN_X - 22;
	HEIGHT = WIN_Y - 62;
	IMG = mlx_new_image(MLX, WIDTH, HEIGHT);
	IMG_ADDR = mlx_get_data_addr(IMG, &BPP, &SIZELINE, &ENDIAN);
	return (param);
}
