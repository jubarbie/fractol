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

void	*prm;

/*static void	fract_calc(t_param *param)
{
	long double	tmp;

	tmp = Z_R;
	Z_R = Z_R * Z_R - Z_I * Z_I + C_R;
	Z_I = 2 * Z_I * tmp + C_I;
}*/

static void		*julia1(void *th)
{
	int	x;
	int	y;
	int	i;
	long double c_r;
	long double c_i;
	long double z_r;
	long double z_i;
	long double tmp;
	t_param	*param;

	param = (t_param *)prm;
	x = -1;
	while (++x < WIDTH)
	{
		y = *(int *)th * (HEIGHT / NB_TH) - 1;
		while (++y < (*(int *)th + 1)  * HEIGHT /NB_TH)
		{
			c_r = 0.285 + V;
			c_i = 0.01 / V;
			z_r = (x - PX) / ZOOM + X1;
			z_i = (y - PY) / ZOOM + Y1;
			i = -1;
			while (z_r * z_r + z_i * z_i < 4 && ++i < ITER)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;

			}
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
	int i;

	i = -1;
	PX = posx;
	PY = posy;
	prm = (void *)param;
	while (++i < NB_TH)
	{	
		pthread_t	th;
		int n_th;
		n_th = i;
		if (pthread_create(&th, NULL, &julia1, (void *)&n_th) < 0)
		{
    			fprintf (stderr, "pthread_create error for thread 1\n");
    			exit (1);
  		}
		(void)pthread_join (th, NULL);
	}
}
