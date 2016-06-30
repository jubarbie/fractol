/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 20:11:28 by jubarbie          #+#    #+#             */
/*   Updated: 2016/06/30 19:54:12 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	create_img(t_param *param)
{
	int		posx;
	int		posy;

	if (M)
		ITER += (ITER < ITER_MAX) ? 1 : 0;
	posx = (WIN_X / 2 - (X2 - X1) * ZOOM / 2) + POSX - 5;
	posy = (WIN_Y / 2 - (Y2 - Y1) * ZOOM / 2) + POSY - 25;
	FRCT(posx, posy, param);
	mlx_put_image_to_window(MLX, WIN, IMG, 11, 51);
	display_param(param);
	return (0);
}

void		img_put_pixel(t_param *param, int x, int y, unsigned int color)
{
	unsigned int r;
	unsigned int g;
	unsigned int b;

	b = ((color & 0xFF0000) >> 16);
	g = ((color & 0xFF00) >> 8);
	r = (color & 0xFF);
	IMG_ADDR[y * SIZELINE + x * (BPP / 8)] = r;
	IMG_ADDR[y * SIZELINE + x * (BPP / 8) + 1] = g;
	IMG_ADDR[y * SIZELINE + x * (BPP / 8) + 2] = b;
}

int			main(int ac, char **av)
{
	char	opt;
	int		i;
	t_param	*param;

	i = get_options(ac, av, &opt);
	ac -= i + 1;
	if (ac <= 0)
		error_usage();
	while (ac-- > 0)
		if (fork() != 0)
		{
			param = init_param(1000, 900, opt, av[i + ac + 1]);
			if (M)
				ITER = 0;
			mlx_loop_hook(MLX, create_img, param);
			mlx_expose_hook(WIN, create_img, param);
			mlx_hook(WIN, KeyPress, KeyPressMask, ft_key, param);
			mlx_hook(WIN, MotionNotify, ButtonMotionMask, ft_mouse_motion,
					param);
			mlx_hook(WIN, ButtonPress, ButtonPressMask, ft_mouse, param);
			mlx_loop(MLX);
			free_param(param);
		}
	return (0);
}
