/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 20:11:28 by jubarbie          #+#    #+#             */
/*   Updated: 2016/04/19 14:10:31 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "mlx.h"
#include "fdf.h"
#include "libft.h"

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
	float	x1 = -2.1 / (ZOOM / 100);
	float	x2 = 0.6 / (ZOOM / 100);
	float	y1 = -1.2 / (ZOOM / 100);
	float	y2 = 1.2 / (ZOOM / 100);
	int		iter_max = 10 * ZOOM / 100;
	float	c_r;
	float	c_i;
	float	z_r;
	float	z_i;
	float	tmp;
	int		x;
	int		y;
	int		i;
	int		posx;
	int		posy;

	WIDTH = WIN_X - 22;
	HEIGHT = WIN_Y - 62;
	posx = (WIN_X / 2 - (x2 - x1) * ZOOM / 2) + POSX;
	posy = (WIN_Y / 2 - (y2 - y1) * ZOOM / 2) + POSY;
	IMG = mlx_new_image(MLX, WIDTH, HEIGHT);
	IMG_ADDR = mlx_get_data_addr(IMG, &BPP, &SIZELINE, &ENDIAN);
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			c_r = (x - posx) / ZOOM + x1;
			c_i = (y - posy) / ZOOM + y1;
			z_r = 0;
			z_i = 0;
			i = -1;
			while (z_r * z_r + z_i * z_i < 4 && ++i < iter_max)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
			}
			if (i == iter_max)
				img_put_pixel(param, x, y, mlx_get_color_value(MLX, 0x00000000));
			else
				img_put_pixel(param, x, y, mlx_get_color_value(MLX, 0x00000000 
							+ i * 255 /iter_max));	
		}
	}	
	mlx_put_image_to_window(MLX, WIN, IMG, 11, 51);
	mlx_destroy_image(MLX, IMG);
	return (0);
}
