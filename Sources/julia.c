/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 21:27:53 by jubarbie          #+#    #+#             */
/*   Updated: 2016/06/30 20:03:12 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fract_calc(t_param *param)
{
	long double	tmp;

	tmp = Z_R;
	Z_R = Z_R * Z_R - Z_I * Z_I + C_R;
	Z_I = 2 * Z_I * tmp + C_I;
}

static void		*julia1(void *prm)
{
	int	x;
	int	y;
	int	i;
	t_param	*param;

	param = (t_param *)prm;
	x = -1;
	while (++x < WIDTH / 2)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			C_R = 0.285 + V;
			C_I = 0.01 / V;
			Z_R = (x - PX) / ZOOM + X1;
			Z_I = (y - PY) / ZOOM + Y1;
			i = -1;
			while (Z_R * Z_R + Z_I * Z_I < 4 && ++i < ITER)
				fract_calc(param);
			if (i == ITER)
				img_put_pixel(param, x, y, 0);
			else
				img_put_pixel(param, x, y, mlx_get_color_value(MLX, 0
							| i * PAL[COLOR]));
		}
	}
	pthread_exit (0);
}

static void		*julia2(void *prm)
{
	int	x;
	int	y;
	int	i;
	t_param *param;

	
	param = (t_param *)prm;
	x = WIDTH / 2 - 1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			C_R = 0.285 + V;
			C_I = 0.01 / V;
			Z_R = (x - PX) / ZOOM + X1;
			Z_I = (y - PY) / ZOOM + Y1;
			i = -1;
			while (Z_R * Z_R + Z_I * Z_I < 4 && ++i < ITER)
				fract_calc(param);
			if (i == ITER)
				img_put_pixel(param, x, y, 0);
			else
				img_put_pixel(param, x, y, mlx_get_color_value(MLX, 0
							| i * PAL[COLOR]));
		}
	}
	pthread_exit (0);
}

void 		julia(int posx, int posy, t_param *param)
{
	pthread_t	th1;
	pthread_t	th2;
	void		*ret;

	PX = posx;
	PY = posy;
	if (pthread_create(&th1, NULL, &julia1, (void *)param) < 0)
	{
    	fprintf (stderr, "pthread_create error for thread 1\n");
    	exit (1);
  	}
	if (pthread_create (&th2, NULL, &julia2, (void *)param) < 0)
	{
		fprintf (stderr, "pthread_create error for thread 2\n");
		exit (1);
	}
	(void)pthread_join (th1, &ret);
	(void)pthread_join (th2, &ret);
}
