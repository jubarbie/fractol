/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 22:01:18 by jubarbie          #+#    #+#             */
/*   Updated: 2016/06/06 17:10:23 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(int button, int x, int y, t_param *param)
{
	if (button == 5 && ZOOM < 900000000)
	{
		ZOOM *= 1.5;
		ITER += 3;
		POSX = (WIN_X - 20) / 2 - x + 10 + POSX * 1.5;
		POSY = (WIN_Y - 60) / 2 - y + 50 + POSY * 1.5;
	}
	if (button == 4 && ZOOM > 0)
	{
		ZOOM /= 1.5;
		ITER -= 3;
		POSX = (WIN_X - 20) / 2 - x + 10 + POSX / 1.5;
		POSY = (WIN_Y - 60) / 2 - y + 50 + POSY / 1.5;
	}
}

int			ft_mouse(int button, int x, int y, t_param *param)
{
	if (button == 1 && x > WIN_X - 170 && x < WIN_X - 150 && y > 7 && y < 47)
		COLOR = 0;
	if (button == 1 && x > WIN_X - 150 && x < WIN_X - 130 && y > 7 && y < 47)
		COLOR = 1;
	if (button == 1 && x > WIN_X - 130 && x < WIN_X - 110 && y > 7 && y < 47)
		COLOR = 2;
	if (button == 1 && x > WIN_X - 110 && x < WIN_X - 90 && y > 7 && y < 47)
		COLOR = 3;
	if (button == 1 && x > WIN_X - 90 && x < WIN_X - 70 && y > 7 && y < 47)
		COLOR = 4;
	if (button == 1 && x > WIN_X - 70 && x < WIN_X - 50 && y > 7 && y < 47)
		COLOR = 5;
	if (button == 1 && x > WIN_X - 50 && x < WIN_X - 30 && y > 7 && y < 47)
		COLOR = 6;
	if (button == 1 && x > WIN_X - 30 && x < WIN_X && y > 7 && y < 47)
		COLOR = 7;
	zoom(button, x, y, param);
	return (0);
}

int			ft_mouse_motion(int x, int y, t_param *param)
{
	if (Z)
		V = ((long double)x - WIDTH / 4) / 10000;
	y = 0;
	return (0);
}
