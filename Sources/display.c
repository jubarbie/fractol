/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 12:38:18 by jubarbie          #+#    #+#             */
/*   Updated: 2016/06/30 19:20:34 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

static void	white_screen(t_param *param)
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

static void	draw_circle(int x, int y, char c, t_param *param)
{
	int	r;
	int	i;
	int	j;
	int	color;

	r = 20;
	j = y - 1;
	color = PAL[ft_atoi(&c) - 1];
	while (++j <= y + r * 2)
	{
		i = x - 1;
		while (++i <= x + r * 2)
			if (sqrt(ft_power_two(abs(x + r - i)) +
						ft_power_two(abs(y + r - j))) < r)
			{
				if (i < r)
					mlx_pixel_put(MLX, WIN, i, j, color * ITER);
				else
					mlx_pixel_put(MLX, WIN, i, j, color * ITER * 2);
			}
	}
	mlx_string_put(MLX, WIN, x + 15, y + r / 2, 0x00FFFFFF, &c);
}

static void	param_back(t_param *param)
{
	int	x;
	int	y;

	y = 54;
	while (++y < 106)
	{
		x = 14;
		while (++x < 191)
			mlx_pixel_put(MLX, WIN, x, y, 0x0000000);
	}
}

void		display_param(t_param *param)
{
	if (P)
	{
		param_back(param);
		mlx_string_put(MLX, WIN, 20, 60, 0x00FFFFFF, "iter: ");
		mlx_string_put(MLX, WIN, 100, 60, 0x00FFFFFF, ft_itoa(ITER));
		mlx_string_put(MLX, WIN, 20, 80, 0x00FFFFFF, "zoom: ");
		mlx_string_put(MLX, WIN, 100, 80, 0x00FFFFFF, ft_itoa(ZOOM / 100));
	}
}

void		display_toolbar(char *title, t_param *param)
{
	white_screen(param);
	mlx_string_put(MLX, WIN, 10, 15, 0x00000000, title);
	draw_circle(WIN_X - 40, 7, '8', param);
	draw_circle(WIN_X - 60, 7, '7', param);
	draw_circle(WIN_X - 80, 7, '6', param);
	draw_circle(WIN_X - 100, 7, '5', param);
	draw_circle(WIN_X - 120, 7, '4', param);
	draw_circle(WIN_X - 140, 7, '3', param);
	draw_circle(WIN_X - 160, 7, '2', param);
	draw_circle(WIN_X - 180, 7, '1', param);
}
