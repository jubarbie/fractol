/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 20:11:28 by jubarbie          #+#    #+#             */
/*   Updated: 2016/05/12 19:03:21 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	white_screen(t_param *param)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WIN_Y)
	{
		x = -1;
		while (++x < WIN_X)
			mlx_pixel_put(MLX, WIN, x, y, 0x00FFFFFF);
	}
}

void	img_put_pixel(t_param *param, int x, int y, unsigned int color)
{
	unsigned int r;
	unsigned int g;
	unsigned int b;

	b = ((color & 0xFF0000) >> 16);
	g = ((color & 0xFF00) >> 8);
	r = ((color & 0xFF));
	IMG_ADDR[y * SIZELINE + x * (BPP / 8)] = r;
	IMG_ADDR[y * SIZELINE + x * (BPP / 8) + 1] = g;
	IMG_ADDR[y * SIZELINE + x * (BPP / 8) + 2] = b;
}

int		create_img(t_param *param)
{
	int		posx;
	int		posy;

	WIDTH = WIN_X - 22;
	HEIGHT = WIN_Y - 62;
	posx = (WIN_X / 2 - (X2 - X1) * ZOOM / 2) + POSX;
	posy = (WIN_Y / 2 - (Y2 - Y1) * ZOOM / 2) + POSY - 31;
	IMG = mlx_new_image(MLX, WIDTH, HEIGHT);
	IMG_ADDR = mlx_get_data_addr(IMG, &BPP, &SIZELINE, &ENDIAN);
	FRCT(posx, posy, param);
	mlx_put_image_to_window(MLX, WIN, IMG, 11, 51);
	mlx_destroy_image(MLX, IMG);
	return (0);
}
