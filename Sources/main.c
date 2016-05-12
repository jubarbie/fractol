/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 10:47:22 by jubarbie          #+#    #+#             */
/*   Updated: 2016/05/12 19:04:47 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_img(int keycode, t_param *param)
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

int		ft_mouse_hook(int button, int x, int y, t_param *param)
{
	printf("click: %d\n", button);
	X1 = x - X1 / ZOOM;
	X2 = x + X2 / ZOOM;
	Y1 = y - Y1 / ZOOM;
	Y2 = y + Y1 / ZOOM;	
	return (0);
}

int		ft_key(int keycode, t_param *param)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 49)
		init_pos(param);
	if (keycode == 0 || keycode == 2 || keycode == 13 || keycode == 1 ||
		(keycode >= 123 && keycode <= 126))
		move_img(keycode, param);
	if (keycode == 78)
		ZOOM /= (ZOOM > 0) ? 1.5 : 1;
	if (keycode == 69)
		ZOOM *= 1.5;
	if (keycode == 17)
		ITER += (ITER < 150) ? 2 : 0;
	if (keycode == 5)
		ITER -= (ITER > 2) ? 2 : 0;
	if (keycode == 18)
		COLOR = 255 / ITER << 0;
	if (keycode == 19)
		COLOR = 255 / ITER << 8;
	if (keycode == 20)
		COLOR = 255 / ITER << 16;
	if (keycode == 21)
		COLOR = 0x00F0F0F0;
	//printf("pressed: %d\n", keycode);
	return (0);
}

int		main(int ac, char **av)
{
	t_param	*param;

	if (ac == 1)
		error_usage();
	else if (ac == 2 && (!ft_strcmp(av[1], "mandelbrot") ||
						!ft_strcmp(av[1], "julia")))
	{
		param = init_param(1800, 1200, av[1]);
		if (!ft_strcmp(av[1], "mandelbrot"))
			FRCT = &mandelbrot;
		if (!ft_strcmp(av[1], "julia"))
			FRCT =&julia;	
		white_screen(param);
		mlx_string_put(MLX, WIN, 10, 15, 0x00000000, av[1]);
		create_img(param);
		mlx_expose_hook(WIN, create_img, param);
		mlx_loop_hook(MLX, create_img, param);
		//	mlx_mouse_hook(MLX, ft_mouse_hook, param);
		//	mlx_key_hook(WIN, ft_key, param);
		mlx_hook(WIN, KeyPress, KeyPressMask, ft_key,  param);
		//	mlx_hook(WIN, ButtonPress, ButtonPressMask, ft_key,  param);
		mlx_loop(MLX);
		free(param);
	}
	else
		error_usage();
	return (0);
}
