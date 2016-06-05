/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 12:38:18 by jubarbie          #+#    #+#             */
/*   Updated: 2016/06/05 22:31:20 by jubarbie         ###   ########.fr       */
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
				mlx_pixel_put(MLX, WIN, i, j, color * ITER);
	}
	mlx_string_put(MLX, WIN, x + 15, y + r / 2, 0x00FFFFFF, &c);
}

static void	param_back(t_param *param)
{
	int	x;
	int	y;

	y = 54;
	while (++y < 186)
	{
		x = 14;
		while (++x < 171)
			mlx_pixel_put(MLX, WIN, x, y, 0x0000000);
	}
}

void		display_param(t_param *param)
{
	char	s[6];

	if (P)
	{
		param_back(param);
		mlx_string_put(MLX, WIN, 20, 60, 0x00FFFFFF, "x1: ");
		mlx_string_put(MLX, WIN, 100, 60, 0x00FFFFFF, ft_itoa(X1));
		mlx_string_put(MLX, WIN, 20, 80, 0x00FFFFFF, "x2: ");
		mlx_string_put(MLX, WIN, 100, 80, 0x00FFFFFF, ft_itoa(X2));
		mlx_string_put(MLX, WIN, 20, 100, 0x00FFFFFF, "iter: ");
		mlx_string_put(MLX, WIN, 100, 100, 0x00FFFFFF, ft_itoa(ITER));
		mlx_string_put(MLX, WIN, 20, 120, 0x00FFFFFF, "zoom: ");
		mlx_string_put(MLX, WIN, 100, 120, 0x00FFFFFF, ft_itoa(ZOOM / 100));
		mlx_string_put(MLX, WIN, 20, 140, 0x00FFFFFF, "cr: ");
		snprintf(s, 6, "%Lf", C_R);
		mlx_string_put(MLX, WIN, 100, 140, 0x00FFFFFF, s);
		mlx_string_put(MLX, WIN, 20, 160, 0x00FFFFFF, "ci: ");
		snprintf(s, 6, "%Lf", C_I);
		mlx_string_put(MLX, WIN, 100, 160, 0x00FFFFFF, s);
	}
}

void		display_toolbar(char *title, t_param *param)
{
	white_screen(param);
	mlx_string_put(MLX, WIN, 10, 15, 0x00000000, title);
	draw_circle(WIN_X - 40, 7, '6', param);
	draw_circle(WIN_X - 60, 7, '5', param);
	draw_circle(WIN_X - 80, 7, '4', param);
	draw_circle(WIN_X - 100, 7, '3', param);
	draw_circle(WIN_X - 120, 7, '2', param);
	draw_circle(WIN_X - 140, 7, '1', param);
}
