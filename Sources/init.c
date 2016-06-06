/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:19:58 by jubarbie          #+#    #+#             */
/*   Updated: 2016/06/06 17:05:52 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "mlx.h"
#include "fractol.h"

static void	get_fractale(char *name, t_param *param)
{
	if (!ft_strcmp(name, "mandelbrot"))
		FRCT = &mandelbrot;
	else if (!ft_strcmp(name, "julia"))
		FRCT = &julia;
	else if (!ft_strcmp(name, "buddhabrot"))
		FRCT = &buddhabrot;
	else if (!ft_strcmp(name, "newton"))
		FRCT = &newton;
	else if (!ft_strcmp(name, "sierpinski"))
		FRCT = &sierpinski;
	else if (!ft_strcmp(name, "burningship"))
		FRCT = &burningship;
	else if (!ft_strcmp(name, "brain"))
		FRCT = &brain;
	else
		error_usage();
	NAME = name;
}

static void	init_palette(t_param *param)
{
	if (!(PAL = malloc(sizeof(unsigned int) * 6)))
		exit(EXIT_FAILURE);
	PAL[0] = BNW;
	PAL[1] = BLU;
	PAL[2] = GRE;
	PAL[3] = RED;
	PAL[4] = PUR;
	PAL[5] = BLG;
	PAL[6] = RAI;
	PAL[7] = PSY;
	COLOR = 0;
}

void		init_pos(char *name, t_param *param)
{
	get_fractale(name, param);
	POSX = 0;
	POSY = 0;
	X1 = -2.1;
	X2 = 0.6;
	Y1 = -1.2;
	Y2 = 1.2;
	ZOOM = 300;
	ITER_MAX = 20;
	V = 0;
	if (!ft_strcmp(NAME, "julia") || !ft_strcmp(NAME, "brain"))
	{
		ITER_MAX = 100;
		X1 = -1;
		X2 = 1;
		Y1 = -1.2;
		Y2 = 1.2;
	}
	ITER = ITER_MAX;
	init_palette(param);
	display_toolbar(name, param);
}

void		free_param(t_param *param)
{
	mlx_destroy_image(MLX, IMG);
	MLX = NULL;
	WIN = NULL;
	IMG = NULL;
	free(param);
}

t_param		*init_param(int size_x, int size_y, char opt, char *name)
{
	t_param	*param;

	if (!(param = (t_param *)malloc(sizeof(t_param))))
		exit(EXIT_FAILURE);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, size_x, size_y, "fract'ol");
	WIN_X = size_x;
	WIN_Y = size_y;
	BPP = 24;
	SIZELINE = WIDTH * (BPP / 8);
	init_pos(name, param);
	OPT = opt;
	WIDTH = WIN_X - 22;
	HEIGHT = WIN_Y - 62;
	V = 0;
	IMG = mlx_new_image(MLX, WIDTH, HEIGHT);
	IMG_ADDR = mlx_get_data_addr(IMG, &BPP, &SIZELINE, &ENDIAN);
	return (param);
}
