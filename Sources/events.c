/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 19:47:10 by jubarbie          #+#    #+#             */
/*   Updated: 2016/05/17 14:37:59 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	move_img(int keycode, t_param *param)
{
	if (keycode == 0 || keycode == 123)
		POSX -= 20;
	if (keycode == 2 || keycode == 124)
		POSX += 20;
	if (keycode == 13 || keycode == 126)
		POSY -= 20;
	if (keycode == 1 || keycode == 125)
		POSY += 20;
}

static void	change_color(int keycode, t_param *param)
{
	if (keycode == 18)
		COLOR = 255 / ITER << 0;
	if (keycode == 19)
		COLOR = 255 / ITER << 8;
	if (keycode == 20)
		COLOR = 255 / ITER << 16;
	if (keycode == 21)
		COLOR = 0x00F0F0F0;
}

static void	zoom(int keycode, t_param *param)
{
	if (keycode == 78)
	{
		ZOOM /= (ZOOM > 0) ? 1.5 : 1;
		ITER -= 3;
	}
	if (keycode == 69)
	{
		ZOOM *= 1.5;
		ITER += 3;
	}
}

int			ft_mouse(int button, int x, int y, t_param *param)
{
	if (button == 1 && x > WIN_X - 70 && x < WIN_X - 50 && y > 7 && y < 47)
		COLOR = 255 / ITER << 0;
	if (button == 1 && x > WIN_X - 50 && x < WIN_X - 30 && y > 7 && y < 47)
		COLOR = 255 / ITER << 8;
	if (button == 1 && x > WIN_X - 30 && x < WIN_X && y > 7 && y < 47)
		COLOR = 255 / ITER << 16;
	printf("btn: %d\n", button);
	return (0);
}

int			ft_key(int keycode, t_param *param)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 49)
		init_pos(param);
	if (keycode == 0 || keycode == 2 || keycode == 13 || keycode == 1 ||
			(keycode >= 123 && keycode <= 126))
		move_img(keycode, param);
	if (keycode >= 18 && keycode <= 21)
		change_color(keycode, param);
	if (keycode == 78 || keycode == 69)
		zoom(keycode, param);
	if (keycode == 17)
		ITER += (ITER < 150) ? 2 : 0;
	if (keycode == 5)
		ITER -= (ITER > 2) ? 2 : 0;
	if (keycode == 35)
		OPT = ~P;
	return (0);
}
