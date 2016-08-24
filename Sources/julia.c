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

t_param	*param;

static void	update_param(t_fract_param *fprm)
{
	long double	tmp;

	tmp = fprm->z_r;
	fprm->z_r = fprm->z_r * fprm->z_r - fprm->z_i * fprm->z_i + fprm->c_r;
	fprm->z_i = 2 * fprm->z_i * tmp + fprm->c_i;
}

static void	init_fract(t_fract_param *fprm, t_pix *pix, t_param *param)
{
	fprm->c_r = 0.285 + V;
	fprm->c_i = 0.01 / V;
	fprm->z_r = (pix->x - PX) / ZOOM + X1;
	fprm->z_i = (pix->y - PY) / ZOOM + Y1;
}

static void		*calc_fract(void *arg)
{
	t_pix	pix;
	t_fract_param fprm;
	int	i;
	static int th;
	t_param *param;

	param = arg;
	th = TH;
	pix.x = -1;
	while (++(pix.x) < WIDTH)
	{
		pix.y = th * (HEIGHT / NB_TH) - 1;
		while (++(pix.y) < (th + 1) * HEIGHT /NB_TH)
		{
			init_fract(&fprm, &pix, param);	
			i = -1;
			while (fprm.z_r * fprm.z_r + fprm.z_i * fprm.z_i < 4 && ++i < ITER)
				update_param(&fprm);
			if (i == ITER)
				img_put_pixel(param, pix.x, pix.y, 0);
			else
				img_put_pixel(param, pix.x, pix.y, mlx_get_color_value(MLX, 0
							| (i * (PAL[COLOR]))));
		}
	}
	pthread_exit (0);
}

void 		julia(int i, t_param *param)
{
	pthread_t	th;
	void *arg = param;

	TH = i;
	if (pthread_create(&th, NULL, &calc_fract, arg) < 0)
		exit (1);
	(void)pthread_join (th, NULL);
}
